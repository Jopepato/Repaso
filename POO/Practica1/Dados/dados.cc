
#include "dados.h"

//Dados, the constructor
//It initialize the seed of time, and gives "1" to both dices
Dados::Dados(){
  srand(time(NULL));
  d1_ = 1;
  d2_ = 1;
  lanzamientos1_ = 0;
  lanzamientos2_ = 0;
  media1_ = 0;
  media2_ = 0;
  for(int i=0;i<5;i++){
    ultimos1_[i] = 0;
    ultimos2_[i] = 0;
  }
}
//lanzamiento
//It gives a random number to both dices
void Dados::lanzamiento(){
  d1_ = (rand()%6)+1;
  d2_ = (rand()%6)+1;
  lanzamientos1_ += 1;
  lanzamientos2_ += 1;
  Media1();
  Media2();
  Ultimos1();
  Ultimos2();

}

//getDado1
//It returns the value of the first dice
int Dados::getDado1(){//Devuelve el valor del dado 1
  return d1_;
}

//getDado2
//It returns the value of the second dice
int Dados::getDado2(){//Devuelve el valor del dado2
  return d2_;
}

//setDado1
//It is used for changing the value of the first dice
bool Dados::setDado1(int d1){//Permite cambiarle el valor al dado 1
  if(d1>0 && d1<=6){
    d1_ = d1;
    lanzamientos1_ += 1;
    Media1();
    Ultimos1();
    return true;
  }else
      return false;
}

//setDado2
//It is used for changing the value of the second dice
bool Dados::setDado2(int d2){//Permite cambiale el valor al dado 2
  if(d2>0 && d2<=6){
    d2_ = d2;
    lanzamientos2_ += 1;
    Media2();
    Ultimos2();
    return true;
  }else
    return false;
}
//Suma
//It returns the value of the first dice in addition with the value of the second dice
int Dados::getSuma(){
  return(getDado1() + getDado2());
}

//Diferencia
//Te da la diferencia del dado mayor, menos el dado menor
int Dados::getDiferencia(){
  if(getDado1()>getDado2()){
    return(getDado1() - getDado2());
  }else{
    return(getDado2() - getDado1());
  }
}

//getLanzamientos1
//This will give us the number of times that we have used the setDado2 function
int Dados::getLanzamientos1(){
  return(lanzamientos1_);
}

//getLanzamientos2
//This will give us the number of times that we have used the setDado1 function
int Dados::getLanzamientos2(){
  return(lanzamientos2_);
}

//Media1
//It makes the average of dice 1
void Dados::Media1(){
  if(lanzamientos1_ > 0){
    media1_ = media1_ + getDado1();

    if(lanzamientos1_ >= 1){
      media1_ = media1_ / lanzamientos1_;
    }
  }
}

//Media2
//It makes the average of dice 2
void Dados::Media2(){
  if(lanzamientos2_ > 0){
    media2_ = media2_ + getDado2();

    if(lanzamientos2_ >= 1){
      media2_ = media2_ / lanzamientos2_;
    }
  }
}

//getMedia1
//It returns the media1_ value
float Dados::getMedia1(){
  return(media1_);
}

//getMedia2
//It returns the media2_ value
float Dados::getMedia2(){
  return(media2_);
}



void Dados::Ultimos1(){
  ultimos1_[4] = ultimos1_[3];
  ultimos1_[3] = ultimos1_[2];
  ultimos1_[2] = ultimos1_[1];
  ultimos1_[1] = ultimos1_[0];
  ultimos1_[0] = getDado1();
}

void Dados::Ultimos2(){
  ultimos2_[4] = ultimos2_[3];
  ultimos2_[3] = ultimos2_[2];
  ultimos2_[2] = ultimos2_[1];
  ultimos2_[1] = ultimos2_[0];
  ultimos2_[0] = getDado2();
}

//getUltimos1
//It returns the array of the last 5 dices of dice 1
int * Dados::getUltimos1(){
  return(ultimos1_);
}
//getUltimos2
//It returns the array of the last 5 dices of dice 2
int * Dados::getUltimos2(){
  return(ultimos2_);
}
