#include "Cupom.hpp"
#include <fstream>
#include <sstream>

Cupom::Cupom() {

  std::ifstream infile("data/numcupom.csv");
  std::string line;

  while (std::getline(infile, line)) {
    int campo = 0;
    std::string delimiter = ";";
    line = line + delimiter;
    size_t pos = 0;
    std::string wait;
    while ((pos = line.find(delimiter)) != std::string::npos) {
      wait = line.substr(0, pos);
      line.erase(0, pos + delimiter.length());
      if (campo == 0) {
        numero = wait;
      } else if (campo == 1) {
        serie = wait;
      }
      campo++;
    }
  }
}

int Cupom::getNumero() {
  num = stoi(numero); 
  return num;
}

int Cupom::getSerie() {
  int ser = stoi(serie);
  return ser;
}

void Cupom::aumentanum(){
  num++;
}
