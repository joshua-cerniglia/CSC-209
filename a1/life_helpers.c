#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_state(char *state, int size){
  for (int i = 0; i<size; i++){
    printf("%c", state[i]);
  }
  printf("\n");
}

void update_state(char *state, int size){

  for(int i = 1; i < (size - 1); i++){
    if(state[i-1] == state[i+1]){
      state[i] = '.';
    }
    else{
      state[i] = 'X';
    }
  }

}

int main(int argc, char **argv) {

  return 0;

}
