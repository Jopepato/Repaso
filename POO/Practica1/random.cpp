//Random.cc
//A program that generates a random number and u have to deal with it

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
  srand(time(NULL));
  int num1, num2;

  num2 = (rand()%10)+1;

  cout << "Introduce un numero del 1 al 10: ";
  cin >> num1;
  cout << "\n";

  while(num1!=num2){
    if(num1<num2){
      cout << "El numero introducido es menor: ";
      cin >> num1;
      cout << "\n";
    }else{
      cout << "El numero introducido es mayor: ";
      cin >> num1;
      cout << "\n";
    }
  }

  cout << "Has averiguado el numero, enhorabuena :D\n";

  return 0;
}
