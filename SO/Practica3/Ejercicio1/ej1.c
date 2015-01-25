#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

pthread_mutex_t candado;

void *escribeMensaje();

void funcionError(int error);

int main(){

pthread_t hilo1,hilo2,hilo3;
pthread_mutex_init(&candado);
int error;

  error = pthread_create(&hilo1, NULL, )



}

void funcionError(int error){

  switch(error){

      case 
  }
}
