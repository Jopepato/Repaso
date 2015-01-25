#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

//Productor consumidor :D

void funcionError(int error);
void * productor();
void * consumidor();

int vector[5];

pthread_mutex_t candado1, candado2;

int main(){

printf("holi");
srand(time(NULL));

pthread_mutex_init(&candado1, NULL);
pthread_mutex_init(&candado2, NULL);
int i, error;
printf("holi");
//Inicualizamos el vector a 0
for(i = 0; i<5; i++){
  vector[i] = 0;
}
printf("hola");
pthread_t productor, consumidor;

error = pthread_create(&productor, NULL, (void*)productor, NULL);
  funcionError(error);

error = pthread_create(&consumidor, NULL, (void*)consumidor, NULL);
  funcionError(error);
printf("hola");

error = pthread_join(productor, NULL);
  funcionError(error);

error = pthread_join(consumidor, NULL);
  funcionError(error);

//Y ahora imprimimos como queda el vector

for(i = 0; i<5; i++){
  printf("%d\t", vector[i]);
}
printf("\n");

pthread_mutex_destroy(&candado1);
pthread_mutex_destroy(&candado2);

return 0;

}

void * productor(){
  int i = 300;
  int j;
  int error;
  while(i >0){

      j = rand()%5;
          error = pthread_mutex_lock(&candado1);
          funcionError(error);
              if(vector[j] == 0)
                  vector[j] = 1;

          error = pthread_mutex_unlock(&candado2);
          funcionError(error);

          i--;
  }

pthread_exit(NULL);
}

void * consumidor(){
  int i = 300;
  int j;
  int error;

  while(i>0){


    j = rand()%5;

        error = pthread_mutex_lock(&candado2);
        funcionError(error);
              if(vector[j] == 1)
                    vector[j] = 0;

        error = pthread_mutex_unlock(&candado1);
        funcionError(error);

    i--;
  }

pthread_exit(NULL);
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
