#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <wait.h>

void handler( int sig ){
  compt ++;
  if ( compt == 5 ){
    kill(SIGINT)
  }

}
int main(int argc, char *argv[]) {
  int compt = 0;
  pid_t pid = 0;
  if( !(pid = fork()) ){
    pause();
  }
  else{
    compt++
    struct sigaction nvt, old;
    memset(nvt,0,sizeof(nvt));
    nvt.sa_handler = &handler;
    sigaction( SIGINT , &nvt , &old );
  }

  return 0;
}
