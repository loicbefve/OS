#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int tube[2];
  char buffer[] = "Coucou moi!";
  char lecture[100];

  pipe(tube);
  //dup2( tube[1] , 1 );
  write( tube[1] , buffer , sizeof(buffer) );
  read( tube[0], lecture , sizeof(lecture) );
  printf("%s\n",lecture);

  return 0;
}
