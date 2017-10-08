#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <wait.h>

int main(int argc, char const *argv[]) {
  int n = 10 , status;
  pid_t pid[n];
  for ( int i = 0 ; i < n ; i++){
    printf( "i= %d\n" , i);
    if( (pid[i] = fork()) == 0){
      for ( int j = 0 ; j < 10 ; j++){
        printf ( "%d\n" , i);
      }
      exit(0);
    }
    else{
      waitpid( pid[i] , &status , 0 );
    }
  }
  return 0;
}
