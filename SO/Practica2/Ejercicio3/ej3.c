#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>


void * sumaVector(void * arg);

int vector[10];
struct numeros{
  int minimo;
  int maximo;
};

int main(int argc, char ** argv){

if(argc != 2){
  perror("Argc error");
  printf("Error value: %d\n", errno);
  exit(EXIT_FAILURE);
}
srand(time(NULL));
int i;
int error=0;
void * subtotal;
int total=0, aux;
//For para rellenar el vecto de randoms
  for(i = 0; i<10; i++){
    vector[i] = rand() %10 +1;
  }


struct numeros *Hue;
int num = atoi(argv[1]);
Hue = (struct numeros*)malloc(num * sizeof(struct numeros));

  for(i=0;i<num;i++){

    Hue[i].minimo = (10/num)*i;
    Hue[i].maximo = (10/num)*(i+1);
    if(i==num-1){
      Hue[i].maximo = 10;
    }
  }



pthread_t * hilo;



hilo = (pthread_t*)malloc(num*sizeof(pthread_t));


  for(i=0; i< num; i++){
    error = pthread_create(&hilo[i], NULL, (void*)sumaVector, (void*)&Hue[i]);
    switch(error){
      case EAGAIN:
              perror("Demasiadas hebras");
              printf("Error value: %d\n", errno);
              exit(EXIT_FAILURE);
              break;
      case EPERM:
              perror("Error");
              printf("Error value: %d\n", errno);
              exit(EXIT_FAILURE);
              break;
      default:
              break;
    }
  }





  for(i=0;i<num;i++){
    pthread_join(hilo[i], &subtotal);
    aux = *(int *)subtotal;
    total = total + aux;
  }

printf("El total es: %d\n", total);


}


void * sumaVector(void * arg){

struct numeros aux;
int i;
int * subtotal;
subtotal = (int *)malloc(sizeof(int));
aux = *(struct numeros *)arg;

for(i = aux.minimo; i<aux.maximo; i++){
  *subtotal = *subtotal + vector[i];
}

printf("El subtotal es :%d\n", *subtotal);

pthread_exit((void*)subtotal);


}
