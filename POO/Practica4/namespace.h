using namespace Ruleta {


using namespace std;

#include <string>
#include <list>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <iostream>




  class Persona{

  private:
    string DNI_;
    string nombre_;
    string apellidos_;
    string direccion_;
    string localidad_;
    string provincia_;
    string pais_;

  public:
    //Declaramos el constructor
    //El unico campo obligatorio es el dni, los demas no son obligatorios
    Persona(string DNI,
    string nombre= "",
    string apellidos = "",
    string direccion = "",
    string localidad = "",
    string provincia = "",
    string pais = "");

    //getters and setter for "DNI"
    //setDNI() -> It catches a dni and gives it to the private member
    //getDNI() -> Returns the value of DNI_
    inline string getDNI(){return DNI_;};
    inline void setDNI(const string &dni){DNI_ = dni;};


    //getters and setter for "nombre"
    //setNombre() -> It catches a "nombre" and gives it to the private member
    //getNombre() -> Returns the value of nombre_
    inline string getNombre(){return nombre_;};
    inline void setNombre(const string &nombre){nombre_ = nombre;};


    //getters and setter for "Apellidos"
    //setApellido() -> It catches an "Apellido" and gives it to the private member
    //getApellido() -> Returns the value of apellidos_
    inline string getApellidos(){return apellidos_;};
    inline void setApellidos(const string &apellidos){apellidos_ = apellidos;};


    //getters and setter for "Direccion"
    //setDireccion() -> It catches a "Direccion" and gives it to the private member
    //getDireccion() -> Returns the value of direccion_
    inline string getDireccion(){return direccion_;};
    inline void setDireccion(const string &direccion){direccion_ = direccion;};


    //getters and setter for "Localidad"
    //setLocalidad() -> It catches a "Localidad" and gives it to the private member
    //getLocalidad() -> Returns the value of localidad_
    inline string getLocalidad(){return localidad_;};
    inline void setLocalidad(const string &localidad){localidad_ = localidad;};


    //getters and setter for "Provincia"
    //setProvincia() -> It catches a "Provincia" and gives it to the private member
    //getProvincia() -> Returns the value of provincia_
    inline string getProvincia(){return provincia_;};
    inline void setProvincia(const string &provincia){provincia_ = provincia;};


    //getters and setter for "Pais"
    //setPais() -> It catches a "Pais" and gives it to the private member
    //getPais() -> Returns the value of pais_
    inline string getPais(){return pais_;};
    inline void setPais(const string &pais){pais_ = pais;};

    //Este metodo devuelve los apellidos concatenados con el nombre
    string getApellidosyNombre();//Devuelve el nombre y el apellido concatenados


  };

  Persona::Persona(string DNI, string nombre, string apellidos, string direccion, string localidad, string provincia, string pais){

    setDNI(DNI);
    setNombre(nombre);
    setApellidos(apellidos);
    setDireccion(direccion);
    setLocalidad(localidad);
    setProvincia(provincia);
    setPais(pais);
  }

  //It returns the concatenation of "Nombre" and "Apellidos"
  //It would print it in this way : "Apellidos, Nombre"
  string Persona::getApellidosyNombre(){
    return(getApellidos()+ ", " + getNombre());
  }

  /******************************************************************************************

                                    CRUPIER

  ********************************************************************************************/

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

  //Constructor de la clase Crupier
  Crupier::Crupier(string DNI, string codigo, string nombre, string apellidos, string direccion,
  string localidad, string provincia, string pais): Persona(DNI){


    setCodigo(codigo);
    setDNI(DNI);
    setNombre(nombre);
    setApellidos(apellidos);
    setDireccion(direccion);
    setLocalidad(localidad);
    setProvincia(provincia);
    setPais(pais);

  }


  /***********************************************************************

                            JUGADOR

  ************************************************************************/

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


  //Constructor de la case jugador
  Jugador::Jugador(string DNI, string codigo,
  string nombre, string apellidos,
  string direccion, string localidad,
  string provincia, string pais, int dinero): Persona(DNI){


    setDNI(DNI);
    setCodigo(codigo);
    setDinero(dinero);
    setNombre(nombre);
    setApellidos(apellidos);
    setDireccion(direccion);
    setLocalidad(localidad);
    setProvincia(provincia);
    setPais(pais);
  }
  /*
  Metodo setApuestas
  Recorrera un fichero con las apuestas del jugador y las pasará  a una lista
  Para ello haremos uso de iteradores
  */

  bool Jugador::setApuestas(){

    fstream myfile;
    struct Apuesta stract;
    char aux[256];

    apuestas_.clear();

    myfile.open((getDNI() + ".txt").c_str());

    if(myfile.is_open()){
      while(myfile.getline(aux, 256, ',')){

        stract.tipo = atoi(aux);

        myfile.getline(aux, 256, ',');
        stract.valor = aux;

        myfile.getline(aux, 256, '\n');
        stract.cantidad = atoi(aux);

        apuestas_.push_back(stract);

      }
      myfile.close();
      return true;

    }else
      return false;
    }





/*************************************************************************************

                                  RULETA

***************************************************************************************/

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

//Aqui haremos las funciones de la clase ruleta

Ruleta::Ruleta(Crupier crupier):crupier_(crupier){
  srand(time(NULL));
  setBanca(1000000);
  setBola(-1);
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




























}
