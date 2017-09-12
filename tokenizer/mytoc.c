#include <stdio.h>
#include <stdlib.h>






int countTokens(char *str, char delim){

  char currentChar = str[0];
  char prevChar;
  int count = 0;
  int i = 0;

  while(currentChar != '\0'){

    
    currentChar = str[i];
    prevChar = str[i-1];
    printf("%c\n",currentChar);
    
    if((currentChar != delim && currentChar !='\0') && (prevChar == delim || prevChar == '\0'))
      count ++;
    
    i++;
  }

  return count;



}

char **mytoc(char *str, char delim){

  int numberTokens = countTokens(str, delim);
  char **tokenVec = (char **)calloc(numberTokens+1, sizeof(char *));
  char buffer[100];
  int bufferCounter = 0;
  char currentChar = str[0];
  int i = 0;
  int tokenNumber = 0;
  
  //printf("beforeWhile....\n");
  while(currentChar != '\0'){
    //printf("While\n");
    currentChar = str[i];
    //printf("CURRENT CHAR %c\n", currentChar);
    if(currentChar != delim && currentChar != '\0'){
      //printf("    if:...\n");
      buffer[bufferCounter] = currentChar;
      bufferCounter++;
    }
    else if(bufferCounter !=0){
      printf("Token:\n");

      tokenVec[tokenNumber] = (char *)malloc(bufferCounter+1);
      //char **addressOfCurrentToken = ((tokenVec[tokenNumber]));
      int j = 0;
      char * strcopy = malloc(bufferCounter+1);
      while(j < bufferCounter){
	
	
	printf("        !!!!:  %c   \n", buffer[j]);
	strcopy[j] = buffer[j];
	j++;
       
      }
      strcopy[bufferCounter+1] = '\0';
      printf("Copy: %s\n", strcopy);
      printf("token number: %d\n", tokenNumber);
      tokenVec[tokenNumber] = strcopy;
      
      

      bufferCounter = 0;
      tokenNumber++;

    }
      
    i++;

  }
  printf("Copying done: %s\n", tokenVec[0]);
  tokenVec[numberTokens+1] = '\0';
  printf("%d", numberTokens);
  
  return tokenVec;
}




int main(){
  
  char **vectorz = mytoc(" Danner     Says  Hi    ", ' ');
 
  printf("Copying done: %s\n", vectorz[0]);
  printf("Copying done: %s\n", vectorz[1]);
  printf("Copying done: %s\n", vectorz[2]);
  //
  return 0;
}
