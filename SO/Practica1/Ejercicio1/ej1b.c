#include <stdio.h>
#include <sys/types.h>
#include <wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>


//Cada hijo crea un proceso

int main(int argc, char ** argv){

  if(argc != 2){
    perror("Error");
    exit(EXIT_FAILURE);
  }

  int numero = atoi(argv[1]);
  pid_t hijo;
  hijo = fork();
  while(numero != 0){




    switch(hijo){

      case -1:
              perror("fork error");
              printf("errno value = %d\n", errno);
              exit(EXIT_FAILURE);
              break;

      case 0: //El hijo

            printf("Soy el hijo %d, de padre: %d y creo otro hijo\n", getpid(), getppid());
            hijo = fork();
            break;

      default: //El padre

            printf("Soy el padre:%d y me voy\n", getpid());
            exit(0);
            break;

    }
    numero--;

  }








}
