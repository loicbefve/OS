#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <wait.h>

int main(int argc, char *argv[]) {
  execvp ( argv[1] , argv+1 );
  return 0;
}
