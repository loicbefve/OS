#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <pthread.h>
#include <assert.h>

void *hello( void* arg){
    printf("Thread:%li , Pid:%d : Hello world\n", pthread_self(),getpid());
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  assert(argc==2);
  int n = atoi(argv[1]);
  pthread_t thread[n];

  for ( int i=0 ; i<n ; i++) {
    printf("Crée thread %d\n",i);
    pthread_create(&thread[i], NULL, hello , (void *)NULL);
  }
  for ( int i=0 ; i<n ; i++) {
    pthread_join(thread[i],NULL);
  }
  printf("Mes fils ont fini\n" );
  pthread_exit(NULL);


  return 0;
}
