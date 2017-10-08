#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[]) {
  int fd[2];
  pid_t pid;
  pipe(fd);
  int status;
  char buffer[100];
  if( !(pid = fork()) ){
    close(fd[0]);
    dup2(1,fd[1]);
    execvp( argv[1] , argv+1 );
    close(fd[1]);
    exit(0);
  }
  else{
    close(fd[1]);
    read(fd[0],buffer,sizeof(buffer));
    printf("%s",buffer);
    close(fd[0]);
    wait(&status);
    if( WIFEXITED(status)){
      if( WEXITSTATUS(status)){
        printf("Le %d a fini avec le code %d\n" , pid , WEXITSTATUS(status));
      }
      else{
        printf("Le %d a très bien fini!\n" , pid);
      }
    }
    else{
      printf("On m'a interrompu\n");
    }
  }
  return 0;
}
