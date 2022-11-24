#ifndef CUPOM_HPP
#define CUPOM_HPP
#include <string>


class Cupom{

std::string numero;
std::string serie;
int num;

public:
Cupom();
int getNumero();
int getSerie();
void getCupom();
void aumentanum();
};

#endif
