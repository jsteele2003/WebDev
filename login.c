//Joe Steele,260516386

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	
	char webStr[200]; //for storing our input from the browser
	char webStr2[200];
	char fileStr[200];
	char fileStr2[200];
	char user[10]; // will preserve key tokens
	char pass[10];
	char space[2] = " ";
	char *delimiters = "&=";
	
	int parseLength = atoi(getenv("CONTENT_LENGTH"));
	FILE *memsIn;
	memsIn = fopen("members.txt", "r");
	
	int validMem = -1;
	int validPass = - 1;
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
	 		strcpy(user, wToken);
	 	}
	 	if(wTokenCounter == 1) // another tbd value
	 	{
	 		strcpy(pass, wToken);
	 	}
	 	wToken = strtok(NULL, space);
	 	wTokenCounter++;
	 }

	 //check with Database and generate web pages
	 while(1){
	 	//read Database into a string:
		if(fgets(fileStr, 200, memsIn) == NULL) break;
		
		printf("%s\n", fileStr);
		fToken = strtok(fileStr, space); //starts at name, key counts will occur at 1 & 2
		fToken = strtok(NULL, space); // bump token to username

		while(fToken != NULL){
			if(strcmp(user, fToken) == 1){
				validMem = 1;

			}
			else if(strcmp(pass, fToken) == 1 && validMem == 1){
				validPass = 1;
				break;
			}
			else{

			}
		}
	 }




	//now fTokenise webStr and pull out username and password

fclose(memsIn);

return 0;
}