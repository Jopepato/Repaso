#ifndef CRUPIER_H_
#define CRUPIER_H_

#include <iostream>
#include "persona.h"

using namespace std;


class Crupier: public Persona{

    private:
          string codigo_;
    public:

          Crupier(string DNI, string codigo,
                    string nombre = "",
                    string apellidos = "",
                    string direccion = "",
                    string localidad = "",
                    string provincia = "",
                    string pais = "");

          //Getters and setters for "codigo_"
          inline string getCodigo(){return(codigo_);};
          inline void setCodigo(const string &codigo){codigo_ = codigo;};




};
















#endif
