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
  if(banca>=0){
    banca_ = banca;
  }
}


//Getters y setter de bola
int Ruleta::getBola(){
  return(bola_);
}

void Ruleta::setBola(int bola){
  if((bola>=0 && bola<=36)|| bola == -1)
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
  ofstream myfile;
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

  ofstream myfile;
  ifstream aux;
  list<Jugador>::iterator i;

  //Primero borramos el fichero ya existente
  aux.open("jugadores.txt");
  if(aux.is_open()){
    remove("jugadores.txt");
    aux.close();
  }
  //Y ahora lo abrimos
  myfile.open("jugadores.txt");




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

  Jugador j("ffd", "ggg");
  fstream myfile;
  char aux[256];

  //Antes de operar con la lista la limpiamos
  jugadores_.clear();

  myfile.open("jugadores.txt");

  if(myfile.is_open()){//Si esta abierto operamos

    while(myfile.getline(aux, 256, ',')){
      j.setDNI(aux);
      myfile.getline(aux, 256, ',');
      j.setCodigo(aux);
      myfile.getline(aux, 256, ',');
      j.setNombre(aux);
      myfile.getline(aux, 256, ',');
      j.setApellidos(aux);
      myfile.getline(aux, 256, ',');
      j.setDireccion(aux);
      myfile.getline(aux, 256, ',');
      j.setLocalidad(aux);
      myfile.getline(aux, 256, ',');
      j.setProvincia(aux);
      myfile.getline(aux, 256, ',');
      j.setPais(aux);
      myfile.getline(aux, 256, '\n');
      j.setDinero(atoi(aux));

      //Y ahora los añadimos a la lista
      jugadores_.push_back(j);

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


/***********************************************************************************


//Actualiza el dinero y las apuestas de los jugadores asi como el dinero de la banca
void Ruleta::getPremios(){

  //Cogera el tipo de apuesta y cada apuesta la mandará a una funcion distinta
  string DNI;
  int tipo;
  list<Jugador>::iterator i;
  list<Apuesta>::iterator j;
  list<Apuesta> auxlist;




  for(i = jugadores_.begin(); i != jugadores_.end(); ++i){

      i->setApuestas();
      auxlist = i->getApuestas();
      //Recorremos las apuestas
      for(j = auxlist.begin(); j != auxlist.end(); ++j){
        switch(j->tipo){
          case 1: Apuesta1(*i, *j);
                  break;
          case 2: Apuesta2(*i, *j);
                  break;
          case 3: Apuesta3(*i, *j);
                  break;
          case 4: Apuesta4(*i, *j);
                  break;
        }
      }

      }

  }

//Y ahora hacemos las funciones de cada tipo de Apuesta

//Apuesta para la funcion 1 (Apuesta sencilla)
void Ruleta::Apuesta1(Jugador j, Apuesta a){


  if(getBola() == atoi(a.valor.c_str())) {
    j.setDinero(j.getDinero() + (a.cantidad * 35));
    setBanca(getBanca() - a.cantidad);
  }else{
    j.setDinero(j.getDinero() - a.cantidad);
    setBanca(getBanca() + a.cantidad);
  }
}

//Apuesta para la funcion 2 (Apuesta Rojo o Negro)
void Ruleta::Apuesta2(Jugador j, Apuesta a){

  if(getBola() != 0){
      if(Color(getBola())){//El color es rojo
        if(a.valor == "rojo"){
          j.setDinero(j.getDinero() + a.cantidad);
          setBanca(getBanca() - a.cantidad);
        }else{
          j.setDinero(j.getDinero() - a.cantidad);
          setBanca(getBanca() + a.cantidad);
        }

      }else{
        if(a.valor == "negro"){
          j.setDinero(j.getDinero() + a.cantidad);
          setBanca(getBanca() - a.cantidad);
        }else{
          j.setDinero(j.getDinero() - a.cantidad);
          setBanca(getBanca() + a.cantidad);
        }
      }
  }else{//El jugador pierde porque sale 0 D:
    j.setDinero(j.getDinero() - a.cantidad);
    setBanca(getBanca() + a.cantidad);
  }
}

              //Devuelve true si es rojo
              //False si es negro
              bool Ruleta::Color(int numero){
                if(numero == 1 || numero == 3 || numero == 5 ||
                   numero == 7 || numero == 9 || numero == 12 ||
                   numero == 14 || numero == 16 || numero == 18 ||
                   numero == 19 || numero == 21 || numero == 23 ||
                   numero == 25 || numero == 27 || numero == 30 ||
                   numero == 32 || numero == 34 || numero == 36)
                  return true;
                else
                  return false;
              }

//Apuesta para la funcion 3 (Apuesta par o impar)
void Ruleta::Apuesta3(Jugador j, Apuesta a){

  if(getBola()!=0){

    if(getBola()%2 == 0){//Es par

      if(a.valor == "par"){
        j.setDinero(j.getDinero() + a.cantidad);
        setBanca(getBanca() - a.cantidad);
      }else{
        j.setDinero(j.getDinero() - a.cantidad);
        setBanca(getBanca() + a.cantidad);
      }

    }else{//Es impar
      if(a.valor == "impar"){
        j.setDinero(j.getDinero() + a.cantidad);
        setBanca(getBanca() - a.cantidad);
      }else{
        j.setDinero(j.getDinero() - a.cantidad);
        setBanca(getBanca() + a.cantidad);
      }
    }
  }else{//Ha salido 0, gana la banca
    j.setDinero(j.getDinero() - a.cantidad);
    setBanca(getBanca() + a.cantidad);
  }

}

//Apuesta para la funcion 4 (Apuesta a alto o bajo)
void Ruleta::Apuesta4(Jugador j, Apuesta a){

  if(getBola()!=0){

    if(getBola()> 0 && getBola() < 19){//Es bajo

      if(a.valor == "bajo"){
        j.setDinero(j.getDinero() + a.cantidad);
        setBanca(getBanca() - a.cantidad);
      }else{
        j.setDinero(j.getDinero() - a.cantidad);
        setBanca(getBanca() + a.cantidad);
      }

    }else{//Es alto
      if(a.valor == "alto"){
        j.setDinero(j.getDinero() + a.cantidad);
        setBanca(getBanca() - a.cantidad);
      }else{
        j.setDinero(j.getDinero() - a.cantidad);
        setBanca(getBanca() + a.cantidad);
      }
    }
  }else{//Ha salido 0, gana la banca
    j.setDinero(j.getDinero() - a.cantidad);
    setBanca(getBanca() + a.cantidad);
  }

}

***************************************************************************************/
























void Ruleta::getPremios(){

  Jugador jugAux("44XX", "1234");

  list<Jugador>::iterator j;
  list<Apuesta>::iterator a;
  list<Apuesta> la;
  string valorApu;


  for(j=jugadores_.begin(); j!=jugadores_.end(); j++){

    j->setApuestas();
    la=j->getApuestas();

    for(a=la.begin(); a!=la.end();a++){


      switch(a->tipo){

        case 1:	if(atoi((a->valor).c_str())==getBola()){
          j->setDinero(j->getDinero()+(a->cantidad*35));
          banca_-=a->cantidad*35;
        }else{
          j->setDinero(j->getDinero()-(a->cantidad));
          banca_+=a->cantidad;
        }
        break;

        case 2:	valorApu = Color(bola_);

        if((a->valor==valorApu)&&(bola_!=0)){
          j->setDinero(j->getDinero()+(a->cantidad));
          banca_-=a->cantidad;
        }else{
          j->setDinero(j->getDinero()-(a->cantidad));
          banca_+=a->cantidad;
        }
        break;

        case 3:
        if(bola_%2==0){
          valorApu="par";
        }else{
          valorApu="impar";
        }

        if((a->valor==valorApu)&&(bola_!=0)){
          j->setDinero(j->getDinero()+(a->cantidad));
          banca_-=a->cantidad;
        }else{
          j->setDinero(j->getDinero()-(a->cantidad));
          banca_+=a->cantidad;
        }

        break;

        case 4:	if(bola_>0&&bola_<19){
          valorApu="bajo";
        }else{
          valorApu="alto";
        }

        if((a->valor==valorApu)&&(bola_!=0)){
          j->setDinero(j->getDinero()+(a->cantidad));
          banca_-=a->cantidad;
        }else{
          j->setDinero(j->getDinero()-(a->cantidad));
          banca_+=a->cantidad;
        }
        break;

      //  default: cout<<"Tipo apuesta no valida"<<endl;
      //  break;
      }
    }
  }
}

/*Devuelve un valor de color segun la bola*/
string Ruleta::Color(int bola){
  string color;


  if((bola>0&&bola<11)||(bola>18&&bola<29)){
    if(bola%2==0){
      color="negro";
    }else{
      color="rojo";
    }
  }else{
    if(bola%2==0){
      color="rojo";
    }else{
      color="negro";
    }
  }

  return (color);
}
