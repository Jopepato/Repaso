#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <wait.h>

int global = 0;



int main(int argc, char ** argv){

  if(argc != 2){
    perror("Argc error");
    printf("Value error %d\n", errno);
    exit(EXIT_FAILURE);
  }

  //Los procesos no comparten memoria :(
  //Creamos un padre con muchos hijos

pid_t hijo;
int hijos = atoi(argv[1]);
int status;

while(hijos != 0){

  hijo = fork();

  switch(hijo){

    case -1:
            perror("Fork error");
            printf("Value error %d\n", errno);
            exit(EXIT_FAILURE);
            break;

    case 0:
          global += 1;
          printf("%d", global);
          exit(0);
          break;

    default:

          printf("%d\n", global);

          wait(&status);
          if(status == 0){
            printf("Everything done\n");
          }else{
            if(WIFEXITED(status)){
              printf("Se ha salido con otro cosa %d", WEXITSTATUS(status));
            }
            if(WIFSIGNALED(status)){
              printf("Se mató %d", WTERMSIG(status));
            }
          }
          break;


}

hijos--;


}

return 0;
}
