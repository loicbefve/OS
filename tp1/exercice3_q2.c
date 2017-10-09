#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <signal.h>

void sigUsr1( int sig ){
  kill(pid1,SIGUSR2);
}


int main(int argc, char *argv[]) {
  pid_t pid1,pid2;
  switch( pid=fork()){
    case -1:
      printf("Il y a eu un problème");
      exit(1);
    case 0:
      //ROUTINE FILS 1
      struct sigaction nvt,old;
      memset(&nvt,0,sizeof(nvt));
      nvt.sa_handler = &//fonction
      sigaction(SIGUSR2,&nvt,&old);
      break;
    default:
      //ROUTINE PERE
      switch( pid2 = fork()){
        case -1:
          printf("Il y a eu un problème");
          exit(1);
        case 0:
          //ROUTINE FILS 2
          struct sigaction nvt,old;
          memset(&nvt,0,sizeof(nvt));
          nvt.sa_handler = &//fonction
          sigaction(SIGUSR1,&nvt,&old);
          break;
        default:
          //ROUTINE PERE
          kill(pid2,SIGUSR1);
      }
  }
  return 0;
}
