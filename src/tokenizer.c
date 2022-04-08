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
  start = str;
  while (space_char(*start)){
      start++;
  }
  
  return start;
}

char *word_terminator(char *word){
  char *term = 0;
  term = word;
  while(non_space_char(*term)){
    term++;
  }
  return term;


}

int count_words(char *str){

  int count=0;
  boolean word_found = false;


  if(*str == 0){
    return 0;
  }

  while(!word_found | *str != 0){
    if(space_char(*str)){
      word_found = false;
      str++;
    }
    else{
      if(!word_found){
	word_found = true;
	count++;
	str++
      }
      else{
	str++
    }


  }
  return count;
  
}

char *copy_str(char *inStr, short len){
  char *copy;
  copy = (char*)malloc(sizeof(char)*(len+1));

  int i =0;
  for(i=0;i<len;i++){
    copy[i] = inStr[i];
  }

  return copy;
  
}

char**tokenize(char *str){


}

void print_tokens(char **tokens){

}

void free_tokens(char **tokens){

}

