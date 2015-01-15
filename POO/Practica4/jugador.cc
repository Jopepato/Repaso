

#include "jugador.h"


//Constructor de la case jugador
Jugador::Jugador(string DNI, string codigo,
                  string nombre, string apellidos,
                  string direccion, string localidad,
                  string provincia, string pais, int dinero): Persona(DNI){


                    setDNI(DNI);
                    setCodigo(codigo);
                    setDinero(dinero);
                    setNombre(nombre);
                    setApellidos(apellidos);
                    setDireccion(direccion);
                    setLocalidad(localidad);
                    setProvincia(provincia);
                    setPais(pais);
                  }
/*
Metodo setApuestas
Recorrera un fichero con las apuestas del jugador y las pasará  a una lista
Para ello haremos uso de iteradores
*/

bool Jugador::setApuestas(){

  fstream myfile;
  struct Apuesta stract;
  char aux[256];

  apuestas_.clear();

  myfile.open((getDNI() + ".txt").c_str());

  if(myfile.is_open()){
    while(myfile.getline(aux, 256, ',')){

        stract.tipo = atoi(aux);

        myfile.getline(aux, 256, ',');
        stract.valor = aux;

        myfile.getline(aux, 256, '\n');
        stract.cantidad = atoi(aux);

        apuestas_.push_back(stract);

  }
    myfile.close();
      return true;

  }else
      return false;
}
