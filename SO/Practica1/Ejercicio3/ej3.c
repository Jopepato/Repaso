#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char ** argv){
  if(argc != 2){
    perror ("Argc error");
    printf("error value: %d", errno);
    exit(EXIT_FAILURE);
  }

  int numero = atoi(argv[1]);
  int factorial = 1;

  while(numero>0){
    factorial = factorial * numero;
    numero--;
  }

  printf("Factorial: %d\n", factorial);
}
