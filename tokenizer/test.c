#include "mytoken.h"
#include <stdlib.h>
#include <unistd.h>

int length(char *str);
int compare(char *str1, char *str2);

int main(){

  char buffer[512];
  int run = 1;

  while(run){

    write(1, "$ ", 2);
    read(0, buffer, 512);
    char **vecToken = mytoc(buffer, ' ');
   
    run = compare(vecToken[0], "exit");

    int i = 0;

    //prints all the tokens inside of the array
    while(vecToken[i] != '\0'){
      int len = length(vecToken[i]);
      write(1, vecToken[i], len);
      write(1, "\n", 1);
      i++;
      
    }
    

  }

  
  
}

//Returns the length of a string
int length(char *str){

  int count = 0;
  while(str[count] != '\0')
	count ++;
	
  return count;
}

//compares two strings
int compare(char *str1, char *str2){

  int count = 0;

  while(str1[count] == str2[count])
    if( str1[count] != '\n' ||  str2[count] != '\0')
      count ++;
  if(str1[count] == '\0' && str2[count] == '\0')
    return 0;
  else
    return 1;
  
}
