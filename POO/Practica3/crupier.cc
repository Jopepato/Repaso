#include "crupier.h"
#include "persona.h"

Crupier::Crupier(string DNI, string codigo, string nombre, string apellidos, string direccion,
                    string localidad, string provincia, string pais): Persona(DNI){


                  setCodigo(codigo);
                  setDNI(DNI);
                  setNombre(nombre);
                  setApellidos(apellidos);
                  setDireccion(direccion);
                  setLocalidad(localidad);
                  setProvincia(provincia);
                  setPais(pais);
                  }
