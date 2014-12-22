#include "dados.h"





int main(){
Dados dado;
int d1, d2;
cout << "Bienvenido\n";
dado.lanzamiento();

cout << "Dado1: " << dado.getDado1() << "\n";
cout << "Dado2: " << dado.getDado2() << "\n";



cout << "Suma: " << dado.getSuma() << "\n";
cout << "Resta: " << dado.getDiferencia() << "\n";






  return 0;
}
