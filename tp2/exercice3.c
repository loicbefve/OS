#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[]) {
  int fd[2];
  int status;
  char lecture[] = "coucou toi!";
  pipe(fd);
  if ( !fork() ){
    close(fd[1]);
    dup2( fd[0] , 0 );
    execlp("mail" , "mail" , "loic@localhost" , NULL);
  }
  else{
    close(fd[0]);
    dup2( fd[1] , 1 ); // Inutile car on écrit directement de nous même sur le tube
    write(fd[1] , lecture , sizeof(lecture));

  }
  wait(&status);
  return 0;
}
