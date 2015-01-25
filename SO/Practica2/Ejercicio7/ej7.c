#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

void * cambiaEstructura(void * arg);

struct hola{
  char cadena[20];
  int numero;
};

int main(int argc, char ** argv){
  if(argc==1){
    perror("Error en argc");
    printf("Error value: %d\n", errno);
    exit(EXIT_FAILURE);
  }
int num = atoi(argv[1]);
int i, error;
void * recoge;
struct hola pilla;
struct hola* cambiame;
pthread_t* hilo;

hilo = (pthread_t*)malloc(num*sizeof(pthread_t));
cambiame = (struct hola*)malloc(num*sizeof(struct hola));

for(i=0; i<num;i++){
  error = pthread_create(&hilo[i], NULL, (void*)cambiaEstructura, (void*)&cambiame[i]);
  switch(error){
    case EAGAIN:
          perror("Hilos maximos");
          printf("error value: %d\n", errno);
          exit(EXIT_FAILURE);
          break;
    case EINVAL:
          perror("Atributo invalido");
          printf("Error value: %d\n", errno);
          exit(EXIT_FAILURE);
          break;
    case EPERM:
          perror("Permisos necesarios");
          printf("Error value: %d\n", errno);
          exit(EXIT_FAILURE);
          break;
    default:
          break;
  }
}



//Para esperarlos
for(i=0; i<num; i++){
  error = pthread_join(hilo[i], &recoge);
  switch(error){
    case EINVAL:
          perror("Atributo invalido");
          printf("Error value: %d\n", errno);
          exit(EXIT_FAILURE);
          break;
    case EDEADLK:
          perror("Dead lock");
          printf("Error value: %d\n", errno);
          exit(EXIT_FAILURE);
          break;
    case ESRCH:
          perror("ID no encontrada");
          printf("Error value: %d\n", errno);
          exit(EXIT_FAILURE);
          break;
    default:
          pilla = *(struct hola*)recoge;
          printf("Cadena: %s\n numero: %d\n", pilla.cadena, pilla.numero);
  }
}


return 0;
}


void * cambiaEstructura(void * arg){

  struct hola* aux;
  aux = (struct hola*)malloc(sizeof(struct hola));

  aux = (struct hola*)arg;

  aux->numero= aux->numero +1;
  aux->cadena[0] = '9';


  pthread_exit((void*)aux);
}
