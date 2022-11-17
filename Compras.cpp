#include "Compras.hpp"
#include <sstream>

Compras::Compras::(std::string cod, std::string qnt){
  this->codigo_barras_p = cod;
  this->quantidade = qnt;
}

std::string Compras::getCodigo(){
  return codigo_barras_p;
}

std::string Compras::getQuantidade(){
  return quantidade;
}

void Compras::getCompras(){

std::ifstream infile("data/compras.csv");
std::string line; 

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
            codigo_barras_p = wait;
          } else if(campo == 1){
            quantidade = wait;
        }

      // no no produto e pegar tudo que precisa
        campo++;
        linha++;
    }
  }

int Compras::getLinha(){
  return linha;
}
