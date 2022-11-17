#include "Cupom.hpp"
#include <sstream>

void Cupom::getCupom() {
 
std::ifstream infile("data/numcupom.csv");
std::string line; 

  std::string numero;
  std::string serie;

while(std::getline(infile, line)){
   int campo = 0;
    std::string delimiter = ";";
    line = line + delimiter;
    size_t pos = 0;
    std::string wait;
    while((pos = line.find(delimiter)) != std::string::npos){
        wait = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        if(campo == 0){
            numero = wait;
        } else if(campo == 1){
            serie = wait;
      }
      campo++;
    }
  }

std::string Cupom::getNumero(){
  int num = stoi(numero); //stoi connverte string pra inteiro
   return this->num;
}

std::string Cupom::getSerie(){
  int ser = stoi(serie);
   return this->ser;
}
