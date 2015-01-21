
#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <list>
#include <fstream>
#include <cstdlib>
#include "persona.h"


struct Apuesta{
  int tipo;
  string valor;
  int cantidad;
};


class Jugador: public Persona{


        private:
          int dinero_;
          string codigo_;
          list<Apuesta> apuestas_;

        public:

          Jugador(string DNI, string codigo,
                  string nombre = "", string apellidos = "",
                  string direccion = "", string localidad = "",
                  string provincia = "", string pais = "",
                  int dinero = 1000);

          //Getters and setters for "Dinero"
          inline int getDinero(){return(dinero_);};
          inline void setDinero(const int &dinero){dinero_ = dinero;};

          //Getters and setters for "Codigo"
          inline string getCodigo(){return(codigo_);};
          inline void setCodigo(const string &codigo){codigo_ = codigo;};

          //Getters and setters for "Apuestas"
          inline list<Apuesta> getApuestas(){return apuestas_;};
          bool setApuestas();

};


#endif
