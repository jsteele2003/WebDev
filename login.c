//Joe Steele,260516386

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(){
	fflush(stdout);
	char webStr[200] = "name=jbob&passwd=ddd&formula=a"; //for storing our input from the browser
	char webStr2[200];
	char fileStr[200];
	char fileStr2[200];
	char user[10]; // will preserve key tokens
	char pass[10];
	char space[2] = " ";
	char delimiters[2] = "=&"; //breaks up keys and values
	
	//int parseLength = atoi(getenv("CONTENT_LENGTH"));
	FILE *memsIn;
	memsIn = fopen("members.txt", "r");
	
	int validMem = FALSE;
	int validPass = FALSE;
	char *fToken;
	char *wToken;
	int wTokenKey = 0;
	int fCounter = 0;

	
	//first read STDIN input into a string
	//fgets(webStr, parseLength+1, stdin);


	//initalise token
	wToken = strtok(webStr, delimiters);
	
	
	//now walk through POST data for username and password
	 while(wToken != NULL){
	 	if(strcmp(wToken, "name") == 0){
	 		wTokenKey = 1;
	 	}
	 	if(strcmp(wToken, "passwd") == 0){
	 		wTokenKey = 2;
	 	}
	 	if(wTokenKey == 1 && strcmp(wToken, "name") != 0) //some value to be determined
	 	{
	 		strcpy(user, wToken);
	 		wTokenKey = 0;
	 	}
	 	if(wTokenKey == 2 && strcmp(wToken, "passwd") != 0) // another tbd value
	 	{
	 		strcpy(pass, wToken);
	 		wTokenKey = 0;
	 	}
	 	wToken = strtok(NULL, delimiters);
	 }



	 //cross reference with Database to validate
	 while((fgets(fileStr, 200, memsIn)) != NULL){

		
		fToken = strtok(fileStr, space); //starts at name, key counts will occur at 1 & 2

		while(fToken != NULL && validPass == FALSE){
			if(strcmp(user, fToken) == 0){
				validMem = TRUE;
				fCounter++;

			}
			else if(strcmp(pass, fToken) == 0 && validMem == TRUE && fCounter == 1){
				validPass = TRUE;
			}
			fToken = strtok(NULL, space);
		}
		fCounter = 0;
	 }

	 //Generate webpages
	 printf("Content-Type:text/html\n\n");
	 if(validPass == TRUE){
	 	printf("<html><head><title>Login Successful! Follow the below link</title></head>\n");
	 	printf("<body> <a href=//\"cs.mcgill.ca/~jsteel15\">Topic Updates</a></body>\n");
	 	printf("<html>\n");
	 }
	 else{
	 	printf("<html><head><title>Invalid username or password, follow below link to retry</title></head>\n");
	 	printf("<body> <a href=//\"cs.mcgill.ca/~jsteel15\">Topic Updates</a></body>\n");
	 	printf("<html>\n");
	 }


fclose(memsIn);

return 0;
}