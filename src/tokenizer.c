#include "tokenizer.h"

/*
hex values in ascii table for space and tab are 
0x20 and 0x09 so we compare char with those values
and return true if it matches with any of those
*/
int space_char(char c){
  if (c == 0x20 || c == 0x09){
    return 1;
  }
  return 0;

}

int non_space_char(char c ){
  if (c != 0x20 || c != 0x09){
    return 1;
  }
  return 0;

}

char *word_start(char *str){
  char *start = 0;
  start = &str;
  while (space_char(*start)){
      start++;
  }
    
  return start; 
}
