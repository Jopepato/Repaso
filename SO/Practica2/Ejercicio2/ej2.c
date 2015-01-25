#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>


void * SumaAleatorio(){
int a, b;
int * suma;

suma = (int*)malloc(sizeof(int));

a = rand() % 10+1;
b = rand() % 10+1;
*suma = a+b;
printf("Los numeros son: %d, %d y su suma parcial %d\n", a, b, *suma);


pthread_exit((void*)suma);

}

//Me voy de este trabajo
//mal pagado
//:(
int main(int argc, char ** argv){
  if(argc != 2){
  perror("argc error");
  printf("Error value: %d\n", errno);
  exit(EXIT_FAILURE);
  }
  srand(time(NULL));
  int hebras;
  int error;
  hebras = atoi(argv[1]);
  int global=0;
  void* recoge;
  int * aux;
  aux = (int *)malloc(sizeof(int));
  int i;

  pthread_t* hilo;
  hilo = (pthread_t*)malloc(hebras*sizeof(pthread_t));

  for(i =0; i<hebras; i++){
    error = pthread_create(&hilo[i],NULL,(void*)SumaAleatorio,NULL);
    switch(error){
          case EAGAIN:
                  perror("Limete de hilos alcanzado");
                  printf("Error value: %d\n", errno);
                  exit(EXIT_FAILURE);
                  break;

          case EPERM:
                  perror("Error de algo desconocido");
                  printf("Error value: %d\n", errno);
                  exit(EXIT_FAILURE);
                  break;
          default:
                  break;
      }
  }


  for(i=0; i<hebras;i++){
    pthread_join(hilo[i],(void**)&recoge);

    aux = (int *)recoge;

    global = global + *aux;
  }

printf("El global es: %d\n", global);


}
