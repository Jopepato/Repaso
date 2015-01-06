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
//getters and setter for "DNI"
  //setDNI() -> It catches a dni and gives it to the private member
  //getDNI() -> Returns the value of DNI_
void Persona::setDNI(string DNI){
  DNI_ = DNI;
}
string Persona::getDNI(){
  return(DNI_);
}

//getters and setter for "nombre"
  //setNombre() -> It catches a "nombre" and gives it to the private member
  //getNombre() -> Returns the value of nombre_
void Persona::setNombre(string nombre){
  nombre_ = nombre;
}
string Persona::getNombre(){
  return(nombre_);
}

//getters and setter for "Apellidos"
  //setApellido() -> It catches an "Apellido" and gives it to the private member
  //getApellido() -> Returns the value of apellidos_
void Persona::setApellidos(string apellidos){
  apellidos_ = apellidos;
}
string Persona::getApellidos(){
  return(apellidos_);
}

//getters and setter for "Direccion"
  //setDireccion() -> It catches a "Direccion" and gives it to the private member
  //getDireccion() -> Returns the value of direccion_
void Persona::setDireccion(string direccion){
  direccion_ = direccion;
}
string Persona::getDireccion(){
  return(direccion_);
}

//getters and setter for "Localidad"
  //setLocalidad() -> It catches a "Localidad" and gives it to the private member
  //getLocalidad() -> Returns the value of localidad_
void Persona::setLocalidad(string localidad){
  localidad_ = localidad;
}
string Persona::getLocalidad(){
  return(localidad_);
}

//getters and setter for "Provincia"
  //setProvincia() -> It catches a "Provincia" and gives it to the private member
  //getProvincia() -> Returns the value of provincia_
void Persona::setProvincia(string provincia){
  provincia_ = provincia;
}
string Persona::getProvincia(){
  return(provincia_);
}

//getters and setter for "Pais"
  //setPais() -> It catches a "Pais" and gives it to the private member
  //getPais() -> Returns the value of pais_
void Persona::setPais(string Pais){
  pais_ = Pais;
}
string Persona::getPais(){
  return(pais_);
}

//It returns the concatenation of "Nombre" and "Apellidos"
//It would print it in this way : "Apellidos, Nombre"
string Persona::getApellidosyNombre(){
  return(getApellidos()+ ", " + getNombre());
}
