#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

int global = 0;

void * aumenta(){
  int i;
  for(i=0; i<50;i++){
    global++;
  }
pthread_exit(NULL);
}


int main(){

  pthread_t hilo1, hilo2;

  pthread_create(&hilo1, NULL, (void*)aumenta, NULL);
  pthread_create(&hilo2, NULL, (void*)aumenta, NULL);


  pthread_join(hilo1, NULL);
  pthread_join(hilo2, NULL);

  printf("Global: %d\n", global);

  return 0;
}
