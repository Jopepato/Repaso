#ifndef PERSONA_H_
#define PERSONA_H_

#include <string>

using namespace std;


class Persona{

    private:
      string DNI_;
      string nombre_;
      string apellidos_;
      string direccion_;
      string localidad_;
      string provincia_;
      string pais_;

    public:
      //Declaramos el constructor
      //El unico campo obligatorio es el dni, los demas no son obligatorios
      Persona(string DNI,
      string nombre= "",
      string apellidos = "",
      string direccion = "",
      string localidad = "",
      string provincia = "",
      string pais = "");

      string getDNI();
      void setDNI(string dni);

      string getNombre();
      void setNombre(string nombre);

      string getApellidos();
      void setApellidos(string apellidos);

      string getDireccion();
      void setDireccion(string direccion);

      string getLocalidad();
      void setLocalidad(string localidad);

      string getProvincia();
      void setProvincia(string provincia);

      string getPais();
      void setPais(string pais);

      string getApellidosyNombre();//Devuelve el nombre y el apellido concatenados


};


#endif
