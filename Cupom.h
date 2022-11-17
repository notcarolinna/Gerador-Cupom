#ifndef CUPOM_HPP
#define CUPOM_HPP
#include <string>


class Cupom{
Cupom(std::string num, std::string serie);
std::string numero;
std::string serie;

public:
std::string getNumero();
std::string getSerie();
std::stirng getCupom();
}

#endif
