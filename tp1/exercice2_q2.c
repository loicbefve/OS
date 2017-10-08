#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <wait.h>

int main(int argc, char *argv[]) {
  int iter = 5;
  int status;
  pid_t pid = -1;
  for ( int i = 0 ; i < iter ; i++ ){
    if (!(pid = fork()) ){
      execvp( argv[1] , argv+1 );
    }
    else{
      wait(&status);
      if ( WIFEXITED(status) ){
        if ( WEXITSTATUS(status) == 0){
          printf("Tout c'est bhj byihjnliujn liuien passé\n");
        }
        else{
          printf("Il y a eu un problème aved %d, code erreur: %d\n" , pid, WEXITSTATUS(status)),
          exit(1);
        }
      }
      else{
        printf("Un signal m'a arrêter\n");
      }
    }
  }
  return 0;
}
