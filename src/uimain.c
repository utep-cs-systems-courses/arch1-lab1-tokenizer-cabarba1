#include <stdio.h>
#include "tokenizer.h"


int main(){

  char user_input[50];
  
  printf("enter q to quit\n");
  printf("$ ");
  fgets(user_input, sizeof(user_input), stdin);
  puts(user_input);

  

}



