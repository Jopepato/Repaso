#include "persona.h"
#include "jugador.h"
#include "crupier.h"



int main(){

  Jugador p("2223", "288", 288);
  list<Apuesto> aux;
  list<Apuesto>::iterator i;
  if(p.setApuestas()){

    aux = p.getApuestas();

    for(i=aux.begin();i!=aux.end();++i){
      cout << i->tipo << '\t' << i->valor << '\t' << i->cantidad;
      cout << endl;
    }

  }else{
    cout << "ERROR" << endl;
    exit(-1);
  }




return 0;
}
