//Ejercicio 4

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <wait.h>


int main(){

  pid_t hijo;

  int status;

  hijo = fork();


  switch(hijo){

    case -1:
          perror("fork eror");
          printf("error value :%d", errno);
          exit(EXIT_FAILURE);
          break;

    case 0: //El hijo
          printf("pos me mato y mi pid es: %d\n", getpid());
          exit(0);
          break;

    default:
    wait(&status);
          sleep(30);

          exit(0);
          break;


  }




}
