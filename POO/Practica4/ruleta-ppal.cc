#include "namespace.h"


using namespace Ruletah;



  int main(){

    //Declaramos el crupier que entrará en la ruleta
    Crupier c1("288T", "234324");
    char opcion;

    //Declaramos la ruleta y le introducimos el crupier
    Ruleta r1(c1);
    int jugadores, dinero, lanzamientos, ganancia;
    string dni;
    //Un jugador nuevo para añadir a la lista
    Jugador nuevo("0000A", "121312");
    string DNI, codigo, nombre, apellidos, direccion, localidad, provincia, pais;

    while(opcion != '7'){

      //Hacemos el menu de opciones

      std::cout << "1) Cargar los jugadores del fichero" << endl;
      std::cout << "2) Guardar los jugadores en el fichero" << endl;
      std::cout << "3) Ver el estado de la ruleta" << endl;
      std::cout << "4) Hacer girar la ruleta" << endl;
      std::cout << "5) Eliminar un jugador de la mesa" << endl;
      std::cout << "6) Añadir un jugador a la mesa" << endl;
      std::cout << "7) Salir del programa" << endl << endl;

      cout << "Opcion: ";
      cin >> opcion;
      cout << endl;

      switch(opcion){

        case '1': r1.leeJugadores();
                  cout << "Jugadores leidos" << endl;
                  break;

        case '2': r1.escribeJugadores();
                  cout << "Jugadores guardados en el fichero" << endl;
                  break;

        case '3': r1.getEstadoRuleta(jugadores, dinero, lanzamientos, ganancia);

                  cout << "Numero de jugadores: " << jugadores << endl;
                  cout << "Dinero en la mesa: " << dinero << endl;
                  cout << "Numero de lanzamientos: " << lanzamientos << endl;
                  cout << "Ganancia de la banca: " << ganancia << endl << endl;
                  break;

        case '4': r1.giraRuleta();
                  cout << "Ruleta girando" << endl;
                  r1.getPremios();
                  cout << "Y premios repartidos" << endl;

                  break;

        case '5': cout << "Introduce el DNI del jugador que quieres eliminar: ";
                  cin >> dni;
                  int borrado;
                  borrado = r1.deleteJugador(dni);
                  if(borrado == 1){
                    cout << "Jugador borrado" << endl;
                  }
                  if(borrado == -1){
                    cout << "Lista vacia, no hay ningun jugador" << endl;
                  }
                  if(borrado == -2){
                    cout << "No se ha encontrado al jugador con dicho dni" << endl;
                  }

                  break;

        case '6': cout << "Vamos a añadir al jugador:"<< endl;

                  cout << "DNI: ";
                  cin >> DNI;
                  cout << "Codigo: ";
                  cin >> codigo;
                  cout << "Nombre: ";
                  cin >> nombre;
                  getchar();
                  cout << "Apellidos: ";
                  getline(cin, apellidos);
                  cout << "Direccion: ";
                  cin >> direccion;
                  cout << "Localidad: ";
                  cin >> localidad;
                  cout << "Provincia";
                  cin >> provincia;
                  cout << "Pais: ";
                  cin >> pais;

                  nuevo.setDNI(DNI);
                  nuevo.setCodigo(codigo);
                  nuevo.setNombre(nombre);
                  nuevo.setApellidos(apellidos);
                  nuevo.setDireccion(direccion);
                  nuevo.setLocalidad(localidad);
                  nuevo.setProvincia(provincia);
                  nuevo.setPais(pais);
                  r1.addJugador(nuevo);

                  cout << "Jugador añadido " << endl << endl;

                  break;

        case '7':
                  cout << "Gracias por su visita" << endl << endl;
                  break;

        default:
                  cout << "Opcion no validad" << endl;
                  break;


      }

    }


    return(0);
  }
