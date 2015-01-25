#include <stdio.h>
#include <sys/types.h>
#include <wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

//Padre que crea muchos hijos


void main(int argc, char ** argv){

  if(argc!= 2){
      perror("Error");
      exit(EXIT_FAILURE);
  }

  int hijos = atoi(argv[1]);
  pid_t hijo;
  int status;
  int i;
while(hijos != 0){

    hijo = fork();//fork devuelve 0 si es el hijo y devuelve -1 si es error

    switch(hijo){

      case -1: //error
        perror("fork error");
        printf("errno value = %d\n", errno);
        exit(-1);
        break;

      case 0: //El hijo

        printf("Soy el hijo y me voy\n");
        exit(0);

      default: //El padre

        printf("Padre: Mi pid es %d. El pid de mi hijo es %d\n", getpid(), hijo);
        break;
    }
    hijos--;

}

  waitpid(hijo, &status, 0);

  exit(0);

}
