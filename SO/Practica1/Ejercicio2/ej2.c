#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <wait.h>




int main(int argc, char ** argv){

  if(argc != 2){
    perror("Argc error");
    exit(EXIT_FAILURE);
  }
  int n = atoi(argv[1]);
  int duerme = 0;
  pid_t hijo;
  int status;

  while(n !=0){
    duerme++;

    hijo = fork();

    switch(hijo){

      case -1:
              perror("Fork error");
              printf("errno value= %d\n", errno);
              exit(EXIT_FAILURE);
              break;

      case 0: //El hijo
              printf("Soy el hijo: %d, y mi pae es: %d\n", getpid(), getppid());
              sleep(1*duerme);
              exit(0);
              break;

      default: //El padre
              wait(&status);
              printf("Soy el padre : %d y mi hijo ya se ha ido :(\n", getpid());
              break;


    }

    n--;


  }

  wait(&status);
  printf("Soy el padre: %d y mi ultimo hijo ya se fue\n", getpid());

  exit(0);
}
