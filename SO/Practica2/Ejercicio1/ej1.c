//Hilos hilos futuro futuro
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void * EscribeCadena(void* cadena){

  char * cad;
  int i;
  cad = (char *)malloc(200*sizeof(char));
  cad = (char *) cadena;

  for(i =0; i<strlen(cad); i++){
    printf("%c", cad[i]);
    fflush(stdout);
    sleep(1);
  }

pthread_exit(NULL);

}

int main(int argc, char ** argv){

  if(argc != 3){
    perror("Argc error");
    printf("Error value: %d\n", errno);
    exit(EXIT_FAILURE);
  }

pthread_t hilo1, hilo2;

  //Aqui los creamos
  pthread_create(&hilo1, NULL, (void *)EscribeCadena, (void *)argv[1]);
  pthread_create(&hilo2, NULL, (void*)EscribeCadena, (void*) argv[2]);


  //Aqui los esperamos
  pthread_join(hilo1, NULL);
  pthread_join(hilo2, NULL);

  printf("\n");


  return 0;
}
