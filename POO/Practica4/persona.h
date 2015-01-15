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

      //getters and setter for "DNI"
        //setDNI() -> It catches a dni and gives it to the private member
        //getDNI() -> Returns the value of DNI_
      inline string getDNI(){return DNI_;};
      inline void setDNI(const string &dni){DNI_ = dni;};


      //getters and setter for "nombre"
        //setNombre() -> It catches a "nombre" and gives it to the private member
        //getNombre() -> Returns the value of nombre_
      inline string getNombre(){return nombre_;};
      inline void setNombre(const string &nombre){nombre_ = nombre;};


      //getters and setter for "Apellidos"
        //setApellido() -> It catches an "Apellido" and gives it to the private member
        //getApellido() -> Returns the value of apellidos_
      inline string getApellidos(){return apellidos_;};
      inline void setApellidos(const string &apellidos){apellidos_ = apellidos;};


      //getters and setter for "Direccion"
        //setDireccion() -> It catches a "Direccion" and gives it to the private member
        //getDireccion() -> Returns the value of direccion_
      inline string getDireccion(){return direccion_;};
      inline void setDireccion(const string &direccion){direccion_ = direccion;};


      //getters and setter for "Localidad"
        //setLocalidad() -> It catches a "Localidad" and gives it to the private member
        //getLocalidad() -> Returns the value of localidad_
      inline string getLocalidad(){return localidad_;};
      inline void setLocalidad(const string &localidad){localidad_ = localidad;};


      //getters and setter for "Provincia"
        //setProvincia() -> It catches a "Provincia" and gives it to the private member
        //getProvincia() -> Returns the value of provincia_
      inline string getProvincia(){return provincia_;};
      inline void setProvincia(const string &provincia){provincia_ = provincia;};


      //getters and setter for "Pais"
        //setPais() -> It catches a "Pais" and gives it to the private member
        //getPais() -> Returns the value of pais_
      inline string getPais(){return pais_;};
      inline void setPais(const string &pais){pais_ = pais;};

      //Este metodo devuelve los apellidos concatenados con el nombre
      string getApellidosyNombre();//Devuelve el nombre y el apellido concatenados


};


#endif
