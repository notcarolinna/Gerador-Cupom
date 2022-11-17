#ifndef CUPOM_HPP
#define CUPOM_HPP
#include <string>

class Compras{
Compras(std::string cod, std::string qtd);
std::string codigo_barras_p;
std::string quantidade;
int linha = 0;

public:
std::string getCodigo();
std::string getQuantidade();
void getCompras();
int getLinha();

}

#endif
