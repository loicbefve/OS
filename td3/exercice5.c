#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <wait.h>

void barbier(){
// Routine du barbier
}

void client(){
  //Routine d'un client
}

int main(int argc, char const *argv[]) {
  int const NB_CHAISE = 5, NB_CLIENT = 20;
  int placeLibre = 5;

  pid_t pid = 0;
  int status=0;
  for( int i = 0 ; i< NB_CLIENT ){

  }
  if ( !(pid=fork()) ){
    //exec client
  }
  else{
    while(1){
      if ( placeLibre < NB_CHAISE ){
        placeLibre++;
        printf("Je coupe les cheuveux d'un client");
      }
    }
  }
  return 0;
}
