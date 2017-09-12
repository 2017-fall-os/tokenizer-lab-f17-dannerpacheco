#include "mytoken.h"
#include <stdlib.h>


//counts the number of tokens
int countTokens(char *str, char delim){

  char currentChar = str[0];
  char prevChar;
  int count = 0;
  int i = 0;

  while(currentChar != '\0'){
    
    currentChar = str[i];
    prevChar = str[i-1];
    //rplace end of line by null
    if(str[i+1] == '\n')
      str[i+1] = '\0';
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
  //keeps track of the current token insterted
  int tokenNumber = 0;
  
  
  while(currentChar != '\0'){
    currentChar = str[i];

    //if current char is not blank and not null, add to the counter
    if(currentChar != delim && currentChar != '\0'){
      buffer[bufferCounter] = currentChar;
      bufferCounter++;
    }
    else if(bufferCounter !=0){
      tokenVec[tokenNumber] = (char *)malloc(bufferCounter+1);
      //copies string into vector 
      int j = 0;
      char * strcopy = malloc(bufferCounter+1);
      while(j < bufferCounter){
	strcopy[j] = buffer[j];
	j++;
       
      }
      //adds null terminator to string
      strcopy[bufferCounter+1] = '\0';
      tokenVec[tokenNumber] = strcopy;
      
      

      bufferCounter = 0;
      tokenNumber++;

    }
      
    i++;

  }
  //Adds null terminator to vector
  tokenVec[numberTokens+1] = '\0';
  
  return tokenVec;
}
