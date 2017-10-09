#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <pthread.h>
#include <assert.h>
#include <semaphore.h>

long int SOMME = 0;

void *hello( void* arg){
  int* i = (int*) arg;
    printf("Thread:%li , Pid:%d : Hello world ---> %d\n", pthread_self(),getpid(),*i);
    for (int j = 0 ; j < 1000000 ; j++){
      SOMME += *i;                      //A protéger par un mutex
    }
    pthread_exit(NULL);
}


int main(int argc, char *argv[]) {

  //Variables:
  assert(argc==2);
  int n = atoi(argv[1]);
  pthread_t *thread = (pthread_t*) malloc( n * sizeof(pthread_t));
  int *ordre = (int*) malloc( n * sizeof(int));

  //Création des threads:
  for ( int i=0 ; i<n ; i++) {
    ordre[i] = i;
    printf("Crée thread %d\n",i);
    if( pthread_create(&thread[i], NULL, hello , (void *) &ordre[i]) == 11){
      printf("Tu as créé trop de threads: Error 11\n");
      exit(0);
    }
  }

  // Attente des threads:
  for ( int i=0 ; i<n ; i++) {
    pthread_join(thread[i],NULL);
  }
  printf("Mes fils ont fini, leur somme est %li\n" , SOMME );
  pthread_exit(NULL);


  return 0;
}
