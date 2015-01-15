
#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <list>
#include <fstream>
#include <cstdlib>
#include "persona.h"

struct Apuesto{
  int tipo;
  string valor;
  int cantidad;
};


class Jugador: public Persona{


        private:
          int dinero_;
          string codigo_;
          list<Apuesto> apuestas_;

        public:

          Jugador(string DNI, string codigo, int dinero = 1000,
                  string nombre = "", string apellidos = "",
                  string direccion = "", string localidad = "",
                  string provincia = "", string pais = "");

          inline void setDinero(int dinero){dinero_ = dinero;};
          inline int getDinero(){return(dinero_);};

          inline void setCodigo(string codigo){codigo_ = codigo;};
          inline string getCodigo(){return(codigo_);};

          inline list<Apuesto> getApuestas(){return apuestas_;};
          bool setApuestas();

};


#endif
