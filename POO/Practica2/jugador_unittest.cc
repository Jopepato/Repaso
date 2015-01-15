// dados_unittest.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//
// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "jugador.h"
#include "gtest/gtest.h"

TEST(Jugador, ConstructorParametrosDefecto) {
  Jugador p("2223", "22231");
  list<Apuesto>::iterator i;
  list<Apuesto> aux;
  struct Apuesto stract;

  p.setApuestas();

  aux = p.getApuestas();

  EXPECT_EQ("22231", p.getCodigo());
  EXPECT_EQ("2223", p.getDNI());
  EXPECT_EQ(1000, p.getDinero());
  EXPECT_EQ("", p.getNombre());
  EXPECT_EQ("", p.getApellidos());
  EXPECT_EQ("", p.getDireccion());
  EXPECT_EQ("", p.getLocalidad());
  EXPECT_EQ("", p.getProvincia());
  EXPECT_EQ("", p.getPais());
  EXPECT_EQ(", ", p.getApellidosyNombre());

}

TEST(Jugador, ConstructorParametros) {
  Jugador p("2223", "22231", 288, "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España");
  list<Apuesto>::iterator i;
  list<Apuesto> aux;

  EXPECT_EQ("22231", p.getCodigo());
  EXPECT_EQ("2223", p.getDNI());
  EXPECT_EQ(288, p.getDinero());
  EXPECT_EQ("Carlos", p.getNombre());
  EXPECT_EQ("Gutierrez", p.getApellidos());
  EXPECT_EQ("C/ Mesa 1", p.getDireccion());
  EXPECT_EQ("Aguilar", p.getLocalidad());
  EXPECT_EQ("Sevilla", p.getProvincia());
  EXPECT_EQ("España", p.getPais());
  EXPECT_EQ("Gutierrez, Carlos", p.getApellidosyNombre());
  aux = p.getApuestas();
  //for(i=aux.begin(); i!= aux.end(); ++i){
    //EXPECT_TRUE(i->tipo);
    //EXPECT_TRUE(i->valor);
    //EXPECT_TRUE(i->cantidad);
  //}
}

TEST(Jugador, ConstructorCopiaDefecto) {
  Jugador p("2223", "288", 1024, "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España");
  Jugador q(p);
  Jugador r=q;
  list<Apuesto>::iterator i;
  list<Apuesto> aux;

  EXPECT_EQ("288", q.getCodigo());
  EXPECT_EQ("2223", q.getDNI());
  EXPECT_EQ(1024, q.getDinero());
  EXPECT_EQ("Carlos", q.getNombre());
  EXPECT_EQ("Gutierrez", q.getApellidos());
  EXPECT_EQ("C/ Mesa 1", q.getDireccion());
  EXPECT_EQ("Aguilar", q.getLocalidad());
  EXPECT_EQ("Sevilla", q.getProvincia());
  EXPECT_EQ("España", q.getPais());
  EXPECT_EQ("Gutierrez, Carlos", q.getApellidosyNombre());
  aux = q.getApuestas();
/*
  for(i=aux.begin(); i!= aux.end(); ++i){
    EXPECT_FALSE(0, i->tipo);
    EXPECT_FALSE("", i->valor);
    EXPECT_FALSE(0, i->cantidad);
  }
*/
  aux.clear();

  EXPECT_EQ("288", r.getCodigo());
  EXPECT_EQ("2223", r.getDNI());
  EXPECT_EQ(1024, r.getDinero());
  EXPECT_EQ("Carlos", r.getNombre());
  EXPECT_EQ("Gutierrez", r.getApellidos());
  EXPECT_EQ("C/ Mesa 1", r.getDireccion());
  EXPECT_EQ("Aguilar", r.getLocalidad());
  EXPECT_EQ("Sevilla", r.getProvincia());
  EXPECT_EQ("España", r.getPais());
  EXPECT_EQ("Gutierrez, Carlos", r.getApellidosyNombre());
  aux = r.getApuestas();
/*
  for(i=aux.begin(); i!= aux.end(); ++i){
    EXPECT_FALSE(0, i->tipo);
    EXPECT_FALSE("", i->valor);
    EXPECT_FALSE(0, i->cantidad);
  }
*/
}

TEST(Jugador, OperadorIgualDefecto) {
  Jugador p("2223", "288", 1024, "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España");
  Jugador q("2131", "1313123");
  q=p;

  EXPECT_EQ("288", q.getCodigo());
  EXPECT_EQ("2223", q.getDNI());
  EXPECT_EQ(1024, q.getDinero());
  EXPECT_EQ("Carlos", q.getNombre());
  EXPECT_EQ("Gutierrez", q.getApellidos());
  EXPECT_EQ("C/ Mesa 1", q.getDireccion());
  EXPECT_EQ("Aguilar", q.getLocalidad());
  EXPECT_EQ("Sevilla", q.getProvincia());
  EXPECT_EQ("España", q.getPais());
  EXPECT_EQ("Gutierrez, Carlos", q.getApellidosyNombre());

}
