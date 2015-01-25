#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>


void * leeFichero(void * arg);


int main(int argc, char**argv){

  if(argc == 1){
    perror("Error ;E;E;E");
    exit(EXIT_FAILURE);
  }
int num;
num = argc -1;
int i;
int error;
void * subtotal;
int aux, total = 0;
pthread_t * hilo;

hilo = (pthread_t*)malloc(num*sizeof(pthread_t));

for(i=0; i<num;i++){
  error = pthread_create(&hilo[i], NULL, (void*)leeFichero, (void*)argv[i+1]);
  switch(error){
    case EAGAIN:
          perror("Muchos hilos");
          printf("Error value: %d\n", errno);
          exit(EXIT_FAILURE);
          break;
    case EINVAL:
          perror("Atributos no son correctos");
          printf("Error value: %d\n", errno);
          exit(EXIT_FAILURE);
          break;
    case EPERM:
          perror("Sin permisos");
          printf("Error value: %d\n", errno);
          exit(EXIT_FAILURE);
          break;
    default:
          break;
  }
}



for(i=0;i <num; i++){
  error = pthread_join(hilo[i], (void**)&subtotal);
  switch(error){
      case EDEADLK:
            perror("Error del deadlock");
            printf("Error value: %d\n", errno);
            exit(EXIT_FAILURE);
            break;
      case EINVAL:
            perror("Hilo no joinable");
            printf("Error value: %d\n", errno);
            exit(EXIT_FAILURE);
            break;
      case ESRCH:
            perror("ID no encontrada");
            printf("Error value: %d\n", errno);
            exit(EXIT_FAILURE);
            break;
      default:
            aux = *(int*)subtotal;
            total = total + aux;
            break;

  }



}

printf("El total de lineas es: %d\n", total);
return 0;
}



void * leeFichero(void * arg){
  char * aux;
  aux = (char*)malloc(100*sizeof(char));
  aux = (char*)arg;
  FILE * fichero;
  char cadena[265];
  int *subtotal;
  subtotal = (int*)malloc(sizeof(int));
  *subtotal = 0;
  fichero = fopen(aux, "r");

  while(fgets(cadena, 256, fichero)){
      *subtotal = *subtotal +1;
  }

printf("El subtotal de lineas del fichero %s es %d\n",aux,*subtotal);
pthread_exit((void*)subtotal);

}
