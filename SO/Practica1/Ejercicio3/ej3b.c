//Programa de verdad
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char ** argv){

  if(argc != 3){
    perror("argc error");
    printf ("errno value: %d\n\n", errno);
    exit(EXIT_FAILURE);
  }

  printf ("Hola :D\n");
  fflush(stdout);
  int numero1 = atoi(argv[1]);
  int numero2 = atoi(argv[2]);

  pid_t hijo1, hijo2;
  int status;

  hijo1 = fork();
  if(hijo1 > 0)
      hijo2 = fork();


  if(hijo1 == 0){
    execl("./ej3", "./ej3", argv[1], NULL);
    sleep(2);
    exit(0);

  }
  if(hijo2 == 0){
    execl("./ej3", "./ej3", argv[2], NULL);
    sleep(2);
    exit(0);
  }

  if(hijo1 > 0 && hijo2 > 0){
    waitpid(hijo1, &status, 0);
    waitpid(hijo2, &status, 0);
  }


return (0);

}
