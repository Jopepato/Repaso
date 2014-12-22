#ifndef DADOS_H
#define DADOS_H

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Dados{
    private:
        int d1_;
        int d2_;
    public:
        Dados();
        void lanzamiento();
        int getDado1();
        int getDado2();
        bool setDado1(int d1);//Devuelve true si la operacion es correcta
        bool setDado2(int d2);
        int getSuma();//Devuelve la suma de los dos dados
        int getDiferencia();

};

#endif
