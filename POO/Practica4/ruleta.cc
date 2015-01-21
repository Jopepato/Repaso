#include "ruleta.h"

//Aqui haremos las funciones de la clase ruleta

Ruleta::Ruleta(Crupier crupier):crupier_(crupier){
  srand(time(NULL));
  setBanca(1000000);
  setBola(-1);
  setLanzamientos(0);
}


//Getters y setters de banca

void Ruleta::setBanca(const int &banca){
  if(banca>=0){
    banca_ = banca;
  }
}


//Getters y setter de bola


void Ruleta::setBola(const int &bola){
  if((bola>=0 && bola<=36)|| bola == -1)
    bola_ = bola;
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
  setLanzamientos(getLanzamientos() + 1);
}

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

//Metodo que nos muestra el estado actual de la ruleta
void Ruleta::getEstadoRuleta(int &jugadores, int &dinero, int &lanzamientos, int &ganancia){

  list<Jugador> aux;
  list<Jugador>::iterator i;
  aux = getJugadores();
  jugadores = 0;
  dinero = 0;
  lanzamientos = 0;
  ganancia = 0;

  //Recorremos la lista de jugadoes contandolos y sumando su dinero
  for(i = aux.begin(); i != aux.end(); ++i){
    jugadores++;
    //Este es el dinero pero de los jugadores
    dinero = dinero + i->getDinero();
  }
  //Ahora le sumamos el dinero de la banca
  dinero = dinero + getBanca();

  //Recogemos los lanzamientos
  lanzamientos = getLanzamientos();

  //Y ahora la ganancia

  ganancia = getBanca() - 1000000;

}
