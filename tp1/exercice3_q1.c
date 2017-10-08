#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <wait.h>

void handler( int sig ){
  static int compt = 0; //Le static permet de n(initialiser qu'une fois au premier appel
  compt ++;
  if ( compt == 5 ){
    printf("Ok tu as gagné\n");
    exit(0);
  }
  else{
    printf("Encore une fois!\n");
  }

}
int main(int argc, char *argv[]) {
  struct sigaction nvt, old; //création de 2 nouveau objets struct sigaction
  memset(&nvt,0,sizeof(nvt)); //mise à zéro du nouveau sigaction
  nvt.sa_handler = &handler; // le sa_handler du nouveau = adresse fonction voulue
  sigaction( SIGINT , &nvt , &old ); // modification des sigaction
  printf("try to stop me\n");
  while(1);
  return 0;
}
