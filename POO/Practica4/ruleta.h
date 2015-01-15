#ifndef RULETA_H_
#define RULETA_H_

#include "persona.h"
#include "jugador.h"
#include "crupier.h"
#include <list>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstdio>


using namespace std;

class Ruleta{

    private:
      int banca_;
      int bola_;
      list<Jugador> jugadores_;
      Crupier crupier_;

    public:

      Ruleta(Crupier crupier);

      inline int getBanca(){return banca_;};
      void setBanca(const int &banca);

      inline int getBola(){return bola_;};
      void setBola(const int &bola);

      inline Crupier getCrupier(){return crupier_;};
      inline void setCrupier(const Crupier &c){crupier_ = c;};

      inline list<Jugador> getJugadores(){return jugadores_;};//Devuelve la lista de jugadores

      bool addJugador(Jugador j);//Añade un jugador a la lista
      int deleteJugador(string DNI);//Borra un jugador de la lista de jugadores con ese DNI
      int deleteJugador(Jugador jugador);//Borra un jugador de la lista de jugadores igual que el jugador pasado
      void escribeJugadores();//Escribe los jugadores en un fichero jugadores.txt
      void leeJugadores();//Lee el fichero jugadores.txt y lo pasa a la lista jugadores_

      void giraRuleta();//Simula el giro de la ruleta y la obtención de un número entre 0 y 36

      void getPremios();//Recorre la lista y segun los premios de los jugadores va cambiando su dinero
                        //Asi como el dinero de la banca

      //Funciones auxiliares segun el tipo de apuesta

      string Color(int bola);//Devuelve true si es rojo y false si es negro
};


#endif
