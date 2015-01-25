#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char ** argv){
  if(argc != 3){
    perror("argc error");
    printf("error value: %d", errno);
    exit(EXIT_FAILURE);
  }

  int segundos = atoi(argv[1]);
  int estado = atoi(argv[2]);
  int status;

  pid_t hijo;


  hijo = fork();

  switch(hijo){

    case -1:
          perror("fork error");
          printf("error value: %d", errno);
          exit(EXIT_FAILURE);
          break;


    case 0: //El hijo
            sleep(segundos);
            exit(estado);
            break;

    default://El patter

          //Vemos si el hijo esta bien :(

          while(hijo != wait(&status));

            if(status == estado){
              printf("Todo ha salido bien\n");
            }else{
              if(WIFEXITED(status)){
                printf("El hijo termino y su valor devuelto fue: %i\n", WEXITSTATUS(status));
              }
              if(WIFSIGNALED(status)){
                printf("lo han matado, la señal el %d\n", WTERMSIG(status));
              }
            }
          break;
  }


return 0;
}
