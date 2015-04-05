//Joe Steele,260516386

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	char webStr[200]; //for storing our input from the browser
	char fileStr[200];
	char fileStr2[200];
	char s[2] = " ";
	char a[2] = "&";
	
	int parseLen = atoi(getenv("CONTENT_LENGTH"));
	FILE *memsIn;
	memsIn = fopen("members.txt", "r");
	
	int validMem = -1;
	char *token;
	int tokenCounter = 0;

	//first read STDIN input into a string
	fgets(webStr, parseLen+1, stdin);

	//file reading works, test token functionality:
	fgets(fileStr, 200, memsIn);
	printf("%s\n", fileStr);
	strcpy(fileStr2, fileStr);
	token = strtok(fileStr, s);
	printf("strtok successful\n");


	 while(token != NULL){
	 	printf("%s\n", token );
	 	token = strtok(NULL, s);
	 }



	//now tokenise webStr and pull out username and password

fclose(memsIn);

return 0;
}