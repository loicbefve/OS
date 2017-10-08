#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char buff[100000];
  int fd[2];
  pipe(fd);
  long int n = atoi(argv[1]);
  int ecrit = write(fd[1] , buff , n );
  printf("Ecriture: %d\n" , ecrit);
}
