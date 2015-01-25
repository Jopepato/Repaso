#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <wait.h>


void hijo1(char ** argv);
void hijo2(char ** argv);

int main(int argc, char ** argv){



  pid_t hijo;
  int status;
  int i;

  for(i=0; i<2; i++){

    hijo = fork();
      if(hijo == 0)//Hijo
        break;

  }

  switch(hijo){

    case -1:
      perror("fork error");
      printf("error value: %d", errno);
      exit(EXIT_FAILURE);
      break;

    case 0:
      if(i == 0){
        //gnome-calculator
        hijo1(argv);
      }
      if(i == 1){
        //Fichero
        hijo2(argv);
      }
      break;

    default: //Padre

        //Espera a sus hijos
        waitpid(hijo, &status, 0);
  }



return 0;

}

void hijo1(char ** argv){
  //gnome-calculator
  if(execlp(argv[1], argv[1], NULL)== -1){
    perror("Error del execlp");
    exit(EXIT_FAILURE);
  }else
    exit(EXIT_SUCCESS);
}

void hijo2(char ** argv){
  //Ficheros

  if(execvp(argv[2], &argv[2]) == -1){
    perror("Error de execvp");
    exit(EXIT_FAILURE);
  }else
    exit(EXIT_SUCCESS);

}
