#include "Compras.hpp"
#include <fstream>
#include <sstream>

std::string Compras::getCodigo(int pos) {
  return comprinhas[pos]->getCod(); }

std::string Compras::getQuantidade(int pos) {
  return comprinhas[pos]->getQuant(); }

void Compras::setQuantidade(int c, int q) {
  comprinhas[c]->setQuant(q);
}

Compras::Compras() {

  std::ifstream infile("data/compras.csv");
  std::string line;

  while (std::getline(infile, line)) {
    int campo = 0;
    std::string delimiter = ";";
    line = line + delimiter;
    size_t pos = 0;
    std::string wait;
    std::string cod;
    std::string quant;
    while ((pos = line.find(delimiter)) != std::string::npos) {
      wait = line.substr(0, pos);
      line.erase(0, pos + delimiter.length());
      if (campo == 0) {
        cod = wait;
      } else if (campo == 1) {
        quant = wait;
      }
      campo++;
    }
    comprinhas.push_back( new Compra( cod, quant ) );
  }
}
