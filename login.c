//Joe Steele,260516386

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	
	char webStr[200]; //for storing our input from the browser
	char webStr2[200];
	char fileStr[200];
	char fileStr2[200];
	char s[2] = " ";
	char a[2] = "&";
	
	int parseLength = atoi(getenv("CONTENT_LENGTH"));
	FILE *memsIn;
	memsIn = fopen("members.txt", "r");
	
	int validMem = -1;
	int validPass = - 1;
	char *fToken;
	char *wToken;
	int fTokenCounter = 1; //since we bump the token before we enter the loop
	int wTokenCOunter = 0;

	//first read STDIN input into a string
	fgets(webStr, parseLength+1, stdin);

	//read Database into a string:
	fgets(fileStr, 200, memsIn);
	printf("%s\n", fileStr);
	strcpy(fileStr2, fileStr);

	//initalise tokens
	wToken = strtok(webStr, a);
	fToken = strtok(fileStr, s); //starts at name, key counts will occur at 1 & 2
	fToken = strtok(NULL, s); // bump token to username
	
	//now walk through POST data
	 while(wToken != NULL){

	 	printf("%s\n", wToken );
	 	wToken = strtok(NULL, s);
	 	fTokenCounter++;
	 }



	//now fTokenise webStr and pull out username and password

fclose(memsIn);

return 0;
}