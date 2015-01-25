#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char ** argv){

  if(argc != 2){
    perror("Argc error");
    printf("Error value: %d\n", errno);
    exit(EXIT_FAILURE);
  }

//Padre e hijo esciben en fichero
pid_t hijo;
FILE* fichero;
int i, j;
int status;
fichero = fopen(argv[1], "w");

hijo = fork();

  switch(hijo){

    case -1:
          perror("fork error");
          printf("Error value: %d\n", errno);
          exit(EXIT_FAILURE);
          break;

    case 0:
          for(i= 0; i<5; i++){
            fprintf(fichero, "-----\n");
            fflush(fichero);
            sleep(1);
          }
          exit(0);

    default:
          for(j = 0; j<5; j++){
            fprintf(fichero, "+++++\n");
            fflush(fichero);
            sleep(1);
          }
          wait(&status);

          if(status == 0){
            printf("Todo ha terminado bien\n");
          }else{
            if(WIFEXITED(status)){//Ha salido pero su valor es otro
              printf("Ha terminado pero con otro estado: %d\n",WEXITSTATUS(status));
            }
            if(WIFSIGNALED(status)){//Lo han matado despiadadamente y sin compasion alguna
              printf("Lo han matado %d\n",WTERMSIGN(status));

            }
          }

          fclose(fichero);
          exit(0);
  }

}
