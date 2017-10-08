#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <wait.h>

void chaine ( int n ){
  int status;
  printf("Pour une chaîne n = %d:\n" , n);
  for ( int i = 0 ; i < n ; i++ ){
    if( !fork() ){
      printf("pid = %d ; ppid = %d\n", getpid() , getppid() );
      exit(0);
    }
    else{
      wait(&status);
    }
  }
}

void arbre ( int n ){
  printf("\nPour un arbre n = %d:\n" , n);
  for ( int i = 0 ; i < n ; i++ ){
    if ( !fork() ){
      printf("pid = %d ; ppid = %d\n", getpid() , getppid() );
    }
    else{

      exit(0);
    }
  }
}
/* On a une ligne de shell qui apparait en plein milieu
c'est normal car on exit le shell avant la fin des autres */


int main(int argc, char const *argv[]) {
  int n = 10;
  chaine(n);
  arbre(n);
  return 0;
}
