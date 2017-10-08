#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <semaphore.h>

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  int synchro = semaphore(-n-1);
  for( int i = 0 ; i < n ; i++ ){
    if( !fork() ){
      printf("Hello world %d\n", i );
      V(synchro);
    }
    else{
      P(synchro);
    }
  }

  return 0;
}
