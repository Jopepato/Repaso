

#include "jugador.h"



Jugador::Jugador(string DNI, string codigo, int dinero,
                  string nombre, string apellidos,
                  string direccion, string localidad,
                  string provincia, string pais): Persona(DNI){


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

bool Jugador::setApuestas(){

  fstream myfile;
  struct Apuesto stract;
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
