#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <wait.h>
#include <assert.h>

int main(int argc, char *argv[]) {
  assert(argc >= 2); //On vérifie si il y a bien un argument

  execvp ( argv[1] , argv+1 );
  return 0;
}
