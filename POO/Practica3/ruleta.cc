#include "ruleta.h"

//Aqui haremos las funciones de la clase ruleta

Ruleta::Ruleta(Crupier crupier):crupier_(crupier){
  srand(time(NULL));
  setBanca(1000000);
  setBola(-1);
}

//Getters y setters de banca
int Ruleta::getBanca(){
  return (banca_);
}

void Ruleta::setBanca(int banca){
  banca_ = banca;
}


//Getters y setter de bola
int Ruleta::getBola(){
  return(bola_);
}

void Ruleta::setBola(int bola){
  if(bola>=0 || bola<=36)
    bola_ = bola;
}

//Getters y setters de crupier
Crupier Ruleta::getCrupier(){
  return(crupier_);
}

void Ruleta::setCrupier(Crupier crupier){
  crupier_ = crupier;
}

//Clases relacionadas con el jugador

list<Jugador> Ruleta::getJugadores(){
  return (jugadores_);
}

//Añade un jugador a la lista siempre que no existe y crea su fichero de apuestas correspondiente
bool Ruleta::addJugador(Jugador jugador){

  list<Jugador>::iterator i;
  list<Jugador> aux;
  fstream myfile;
  int encontrado=0;
  string Dni;

  Dni = jugador.getDNI();
  aux = getJugadores();

  //Recorremos la lista de jugadores con un iterator
  for(i =aux.begin();i !=aux.end(); ++i){
    if(i->getDNI()==Dni){
      encontrado = 1;
    }
  }
  //Si no se ha encotrado lo añadimos y creamos su fichero
  if(encontrado == 0){
    myfile.open((jugador.getDNI() + ".txt").c_str());
    myfile.close();
    jugadores_.push_back(jugador);
    return true;
  }else
    return false;

}

//Esta funcion recibe un DNI de un jugador y lo borra de la lista si existe
int Ruleta::deleteJugador(string DNI){

  list<Jugador>::iterator i;

  //Primero comprobamos si la lista esta vacia
  if(jugadores_.empty()){
    return(-1);
  }

  //Para intentar encontrarlo
  for(i = jugadores_.begin(); i != jugadores_.end(); ++i){
    if(DNI == i->getDNI()){
      jugadores_.erase(i);
      return(1);//Jugador encontrado y borrado
    }
  }

  //Si no se ha encontrado al jugador ni la lista esta vacia
  return(-2);
}

//Sobrecarga de funciones, a esta funcion le entra un objeto tipo jugador
int Ruleta::deleteJugador(Jugador jugador){

  list<Jugador>::iterator i;

  //Primero comprobamos si la lista esta vacia
  if(jugadores_.empty()){
    return (-1);
  }


  //Ahora recorremos la lista buscando el dni del jugador pasado por parametro
  for(i = jugadores_.begin(); i != jugadores_.end(); ++i){
    if(jugador.getDNI() == i->getDNI()){
      jugadores_.erase(i);
      return(1);//Jugador encontrado y borrado
    }
  }

  //Si no se ha encontrado al jugador ni la lista esta vacia
  return(-2);
}

//Pasa a fichero la lista de jugadores
void Ruleta::escribeJugadores(){

  fstream myfile;
  list<Jugador>::iterator i;

  jugadores_.clear();
  myfile.open("jugadores.txt");
  if(myfile.is_open()){
    remove("jugadores.txt");
    myfile.open("jugadores.txt");
  }


  //Recorremos la lista pasandola al fichero

    for(i = jugadores_.begin(); i != jugadores_.end(); ++i){

      myfile << i->getDNI() << ',';
      myfile << i->getCodigo() << ',';
      myfile << i->getNombre() << ',';
      myfile << i->getApellidos() << ',';
      myfile << i->getDireccion() << ',';
      myfile << i->getLocalidad() << ',';
      myfile << i->getProvincia() << ',';
      myfile << i->getPais() << ',';
      myfile << i->getDinero() << '\n';
    }

    //Y por ultimo cerramos el fichero
    myfile.close();

}


//Funcion que pasa el fichero "jugadores.txt" a lista
void Ruleta::leeJugadores(){

  list<Jugador>::iterator i;
  fstream myfile;
  char aux[256];

  //Antes de operar con la lista la limpiamos
  jugadores_.clear();
  myfile.open("jugadores.txt");

  if(myfile.is_open()){//Si esta abierto operamos
    i = jugadores_.begin();
    while(myfile.getline(aux, 256, ',')){
      i->setDNI(aux);
      myfile.getline(aux, 256, ',');
      i->setCodigo(aux);
      myfile.getline(aux, 256, ',');
      i->setNombre(aux);
      myfile.getline(aux, 256, ',');
      i->setApellidos(aux);
      myfile.getline(aux, 256, ',');
      i->setDireccion(aux);
      myfile.getline(aux, 256, ',');
      i->setLocalidad(aux);
      myfile.getline(aux, 256, ',');
      i->setProvincia(aux);
      myfile.getline(aux, 256, ',');
      i->setPais(aux);
      myfile.getline(aux, 256, '\n');
      i->setDinero(atoi(aux));

      //Y aumentamos el iterador
      ++i;
    }

  }
  //Y por ultimo cerramos el fichero
  myfile.close();

}

//Ahora los metodos para la ruleta y los premios

//Simula un giro de la ruleta y la obtención de un numero entre 1 y 36
void Ruleta::giraRuleta(){
  setBola(rand()%36);
}

//Actualiza el dinero y las apuestas de los jugadores asi como el dinero de la banca
void Ruleta::getPremios(){

  //Cogera el tipo de apuesta y cada apuesta la mandará a una funcion distinta
  string DNI;
  int tipo;
  char aux[256];
  list<Jugador>::iterator i;
  list<Jugador> aux;
  fstream myfile;

  //Hacemos que la bola gire
  giraRuleta();

  for(i = aux.begin(); i != aux.end(); ++i){
    DNI = i->getDNI();
    myfile.open((DNI + ".txt").c_str());
    if(myfile.is_open()){
      while(myfile.getline(aux, 256, ',')){
        tipo = atoi(aux);
        myfile.getline(aux, 256, ',');
        myfile.getline(aux, 256, '\n');
        switch(tipo){
          case 1:
                Apuesta1(i->getDNI());
                break;
          case 2:
                Apuesta2(i->getDNI());
                break;
          case 3:
                Apuesta3(i->getDNI());
                break;
          case 4:
                Apuesta4(i->getDNI());
                break;
        }
      }
    }
    myfile.close();
  }

}

//Y ahora hacemos las funciones de cada tipo de Apuesta

//Apuesta para la funcion 1 (Apuesta sencilla)
void Ruleta::Apuesta1(string DNI){
  list<Jugador>::iterator i;
  fstream myfile;
  int dinero;
  int numero;
  char aux[256];

  //Abrimos el fichero
  myfile.open((DNI + ".txt").c_str());

  for(i = jugadores_.begin(); i != jugadores_.last(); ++i){
    if(DNI == i->getDNI()){
      while(myfile.getline(aux, 256, ',')){
        myfile.getline(aux, 256, ',');
        numero = atoi(aux);
        myfile.getline(aux, 256, '\n');
        dinero = atoi(aux);

        if(numero == getBola()){
          //Ha ganado 35 a 1
          i->setDinero(i->getDinero() + (dinero * 35));
          setBanca(getBanca() - (dinero *35));
        }else{
          //Ha perdido
          i->setDinero(i->getDinero() - (dinero));
          setBanca(getBanca() + (dinero));
        }
      }
    }
  }

  myfile.close();
}

//Apuesta para la funcion 2 (Apuesta Rojo o Negro)
void Ruleta::Apuesta2(string DNI){
  list<Jugador>::iterator i;
  fstream myfile;
  int dinero;
  int numero;
  char aux[256];

  //Abrimos el fichero
  myfile.open((DNI + ".txt").c_str());

  for(i = jugadores_.begin(); i != jugadores_.last(); ++i){
    if(DNI == i->getDNI()){
      while(myfile.getline(aux, 256, ',')){
        myfile.getline(aux, 256, ',');
        numero = atoi(aux);
        myfile.getline(aux, 256, '\n');
        dinero = atoi(aux);

        if(numero == getBola()){
          //Ha ganado 35 a 1
          i->setDinero(i->getDinero() + (dinero * 35));
          setBanca(getBanca() - (dinero *35));
        }else{
          //Ha perdido
          i->setDinero(i->getDinero() - (dinero));
          setBanca(getBanca() + (dinero));
        }
      }
    }
  }

  myfile.close();

}

//Apuesta para la funcion 3 (Apuesta par o impar)
void Ruleta::Apuesta3(string DNI){
  list<Jugador>::iterator i;

}
//Apuesta para la funcion 4 (Apuesta a alto o bajo)
void Ruleta::Apuesta4(string DNI){
  list<Jugador>::iterator i;

}
