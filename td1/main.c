#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <wait.h>

#define N 2

int main(){
  int status,i;
  pid_t pid;

  for ( i = 0 ; i < N ; i++ ){
    if ( (pid = fork()) == 0 ){
      exit(100+i);
    }
  }

  while ((pid = waitpid(-1, &status, 0)) > 0){
    if(WIFEXITED(status)){
      if(WEXITSTATUS(status) == 0){
        printf("Le fils %d s'est terminé normalement avec le code 0.\n" , pid);
        printf("Il n'a donc pas rencontré de problème.\n");
      }
      else{
        printf("Le fils %d s'est terminé avec le code %d.\n", pid , WEXITSTATUS(status));
        printf("Il s'agit en général d'un code d'erreur\n");
      }
    }
    if (errno != ECHILD){
      perror("Erreur dans waitpid");
    }
  }
  exit(0);
//test
}
