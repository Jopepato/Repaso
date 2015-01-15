#include "persona.h"


Persona::Persona(string DNI, string nombre, string apellidos, string direccion, string localidad, string provincia, string pais){

  setDNI(DNI);
  setNombre(nombre);
  setApellidos(apellidos);
  setDireccion(direccion);
  setLocalidad(localidad);
  setProvincia(provincia);
  setPais(pais);
}

//It returns the concatenation of "Nombre" and "Apellidos"
//It would print it in this way : "Apellidos, Nombre"
string Persona::getApellidosyNombre(){
  return(getApellidos()+ ", " + getNombre());
}
