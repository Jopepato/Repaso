#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

void * mp3tomp4(void *arg);



int main(int argc, char ** argv){

    if(argc != 3){
      perror("Adios");
      exit(EXIT_FAILURE);
    }

  pthread_t hilo1, hilo2;
  int error;
  int i;

  //Creamos los hilos


      error = pthread_create(&hilo1, NULL, (void*)mp3tomp4, (void*)argv[1]);
      switch(error){
        case EAGAIN:
                perror("Error en eagain");
                exit(EXIT_FAILURE);
                break;
        case EPERM:
                perror("Error eperm");
                exit(EXIT_FAILURE);
                break;
        default:
                break;
            }
      error = pthread_create(&hilo1, NULL, (void*)mp3tomp4, (void*)&argv[2]);
      switch(error){

        case EAGAIN:
              perror("Error en eagain");
              exit(EXIT_FAILURE);
              break;
        case EPERM:
              perror("Error eperm");
              exit(EXIT_FAILURE);
              break;
        default:
              break;

    }


pthread_join(hilo1, NULL);
pthread_join(hilo2, NULL);



return 0;
}


void * mp3tomp4(void *arg){

  char * aux;
  aux = (char*)malloc(500*sizeof(char));

  strcat(aux, "ffmpeg -i");
  strcat(aux, (char*)arg);
  strcat(aux, ".mp4 -f mp3 -ab 192000 -ar 48000 -vn");
  strcat(aux, (char*)arg);
  strcat(aux, "MP3.mp3");
  system(aux);

pthread_exit(NULL);

}
