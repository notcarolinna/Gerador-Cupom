#include <string>

#include "Endereco.h"

using namespace std;

Endereco::Endereco(std::string value)
{
    this->value = value;
}

Endereco::~Endereco()
{

}

std::string Endereco::getValue(){
    return this->value;
}

void Endereco::setvalue(std::string value){
    this->value = value;
}
