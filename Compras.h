#ifndef COMPRAS_HPP
#define COMPRAS_HPP
#include <string>
#include <vector>

class Compras {

class Compra {
  std::string codigo_barras_p;
  std::string quantidade;

  public:
  Compra( std::string cod, std::string quant ) {
    codigo_barras_p = cod;
    quantidade = quant;
  }
  std::string getCod() { return codigo_barras_p; }
  std::string getQuant() { return quantidade; }
  void setQuant(int q) { quantidade = std::to_string( q ); }

};

std::vector<Compra*> comprinhas;

public:
Compras();
std::string getCodigo(int);
std::string getQuantidade(int);
void setQuantidade(int, int);

  int getSize(){
    return comprinhas.size();
  }
};

#endif
