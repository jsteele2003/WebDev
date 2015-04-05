//Joe Steele,260516386

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(){
	printf("testing seg\n");
	fflush(stdout);
	char webStr[200]; //for storing our input from the browser
	char webStr2[200];
	char fileStr[200];
	char fileStr2[200];
	char user[10]; // will preserve key tokens
	char pass[10];
	char space[2] = " ";
	char *delimiters = "&="; //breaks up keys and values
	
	int parseLength = atoi(getenv("CONTENT_LENGTH"));
	FILE *memsIn;
	memsIn = fopen("members.txt", "r");
	
	int validMem = FALSE;
	int validPass = FALSE;
	char *fToken;
	char *wToken;
	int fTokenCounter = 1; //since we bump the token before we enter the loop
	int wTokenCounter = 0;

	
	//first read STDIN input into a string
	fgets(webStr, parseLength+1, stdin);


	//initalise token
	wToken = strtok(webStr, delimiters);
	
	
	//now walk through POST data for username and password
	 while(wToken != NULL){
	 	printf("%s\n", wToken );
	 	if(wTokenCounter == 0) //some value to be determined
	 	{
	 		printf("%s\n", wToken);
	 		strcpy(user, wToken);
	 	}
	 	if(wTokenCounter == 1) // another tbd value
	 	{
	 		printf("%s\n", wToken);
	 		strcpy(pass, wToken);
	 	}
	 	wToken = strtok(NULL, space);
	 	wTokenCounter++;
	 }


	 //check with Database to validate
	 while((fgets(fileStr, 200, memsIn)) != NULL){

		
		printf("%s", fileStr);
		fToken = strtok(fileStr, space); //starts at name, key counts will occur at 1 & 2
		fToken = strtok(NULL, space); // bump token to username

		while(fToken != NULL && validPass == FALSE){
			printf("%s\n", fToken);
			if(strcmp(user, fToken) == 0){
				validMem = TRUE;

			}
			else if(strcmp(pass, fToken) == 0 && validMem == TRUE){
				validPass = TRUE;
			}
			fToken = strtok(NULL, space);
		}
	 }

	 //Generate webpages
	 printf("Content-Type:text/html\n\n");
	 if(validPass == TRUE){
	 	printf("<html><head><title>Login Successful! Follow the below link</title></head>\n");
	 	printf("<body> <a href="cs.mcgill.ca/~jsteel15">Topic Updates</a></body>\n");
	 	printf("<html>\n");
	 }
	 else{

	 }


fclose(memsIn);

return 0;
}