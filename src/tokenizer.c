#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
  if(c == '\0'){
    return 0;
  }
  if (c != 0x20 || c != 0x09){
    return 1;
  }
  return 0;

}

char *word_start(char *str){
  char *start;
  start = str;
  while (space_char(*start)){
      start++;
  }
  
  return start;
}

char *word_terminator(char *word){
  char *term;
  
  term = word;

  if(*term == '\0'){
    return term;
  }
  while(!space_char(*term)){
    term++;
  }
  return term;


}

int count_words(char *str){

  int count=0;
  bool word_found = false;

  
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
	str++;
      }
      else{
	str++;
      }
    }
  

  }

  return count;
  
}

char *copy_str(char *inStr, short len){
  char *copy;
  copy = (char*)malloc(sizeof(char)*(len+1));

  
  for(int i = 0;i<len;i++){
    copy[i] = inStr[i];
  }
  copy[len] = '\0';

  return copy;
  
}

char**tokenize(char *str){
  char **tokens;

  int cw = count_words(str);
  tokens = (char **) malloc(sizeof(char *) * (cw+1));

  char *ws;
  char *wt;

  ws = word_start(str);
  wt = word_terminator(str);

  int len;

  for(int i = 0; i < cw; i++){
    len = wt - ws; 
    tokens[i]= copy_str(ws,len);
   
    ws = word_start(wt);
    wt = word_terminator(ws);

 }
  tokens[cw] = '\0';

  return tokens;
}

void print_tokens(char **tokens){
  
  
  while(*tokens != '\0'){
    printf("%s\n",*tokens);
    tokens++;
  }
  printf("0\n");
 
}

void free_tokens(char **tokens){
  char **iter

  while(*iter != '\0'){
    free(*iter);
    iter++;
  }
 
  free(*iter);//frees \0
  free(tokens);
  
}

