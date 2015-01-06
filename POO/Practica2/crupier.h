#ifndef CRUPIER_H_
#define CRUPIER_H_

#include <iostream>
#include "persona.h"

using namespace std;


class Crupier: public Persona{

    private:
          int codigo_;
    public:

          Crupier(int codigo, string DNI,
                    string nombre = "",
                    string apellidos = "",
                    string direccion = "",
                    string localidad = "",
                    string provincia = "",
                    string pais = "");


          inline void setCodigo(int codigo){codigo_ = codigo;};
          inline int getCodigo(){return(codigo_);};




};
















#endif
