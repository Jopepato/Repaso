#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

pthread_mutex_t candado;

void *escribeMensaje(void * caracter);

void funcionError(int error);

int main(){

  pthread_t hilo1,hilo2,hilo3;
  pthread_mutex_init(&candado, NULL);
  int error;
  int i;
  char a = '*', b= '?',c = '+',d = '-';

  error = pthread_create(&hilo1, NULL,(void*)escribeMensaje, (void*)&a);
  funcionError(error);
  error = pthread_create(&hilo2, NULL, (void*)escribeMensaje,(void*)&b);
  funcionError(error);
  error = pthread_create(&hilo3, NULL, (void*)escribeMensaje,(void*)&c);
  funcionError(error);

  error = pthread_mutex_lock(&candado);
  funcionError(error);
  for(i=0; i<5; i++){
    printf("%c", d);
    fflush(stdout);
    sleep(1);
  }
  error = pthread_mutex_unlock(&candado);
  funcionError(error);


  //Esperamos a las hebras

  pthread_join(hilo1, NULL);
  pthread_join(hilo2, NULL);
  pthread_join(hilo3, NULL);



printf("\n");

pthread_mutex_destroy(&candado);

return 0;
}

void* escribeMensaje(void * caracter){
  int i;
  int error;
  char * aux;
  aux = (char *)malloc(sizeof(char));
  aux = (char *)caracter;

  error = pthread_mutex_lock(&candado);
  funcionError(error);
  for(i=0; i<5;i++){
    printf("%c", *aux);
    fflush(stdout);
    sleep(1);
  }
  error = pthread_mutex_unlock(&candado);
  funcionError(error);
}

void funcionError(int error){

  switch(error){

    case EAGAIN:
          perror("Hilos maximos alcanzados");
          printf("Error value: %d\n", errno);
          exit(EXIT_FAILURE);
          break;


    case EPERM:
          perror("permisos");
          printf("Error value: %d\n", errno);
          exit(EXIT_FAILURE);
          break;


    case EINVAL:
          perror("PAM");
          printf("Error value: %d\n", errno);
          break;


    case ESRCH:
          perror("PIM");
          printf("Error value: %d\n", errno);
          exit(EXIT_FAILURE);
          break;

    case EDEADLK:
          perror("PUM");
          printf("Error value: %d\n", errno);
          exit(EXIT_FAILURE);
          break;

    case ENOTRECOVERABLE:
          perror("POM");
          printf("Error value: %d\n", errno);
          exit(EXIT_FAILURE);
          break;

    case EBUSY://Semaforo cerrado
          perror("Semaforo ya cerrado");
          printf("Error value: %d\n", errno);
          exit(EXIT_FAILURE);
          break;


    default:
        break;

  }
}
