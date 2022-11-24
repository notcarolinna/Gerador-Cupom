#include <iostream>
#include <string>

#include "Endereco.hpp"

using namespace std;

Endereco::Endereco(std::string line) {

  int aux = 0;
  std::string delimiter = ":";
  line = line + delimiter;
  size_t pos = 0;   
  std::string hold; 
  while ((pos = line.find(delimiter)) !=
         std::string::npos) { 
    hold = line.substr(0, pos);
    line.erase(0, pos + delimiter.length());

    if (aux == 0) {
      logradouro = hold;
    } else if (aux == 1) {
      numero = hold;
    } else if (aux == 2) {
      bairro = hold;
    } else if (aux == 3) {
      cidade = hold;      
    } else if (aux == 4) {
       uf = hold;
    } else if (aux == 5) {
        cep = hold;
    } 
    aux++;
  }
}

Endereco::~Endereco() {}

std::string Endereco::getLogradouro() { return this->logradouro; }

std::string Endereco::getNumero() { return this->numero; }

std::string Endereco::getComplemento() { return this->complemento; }

std::string Endereco::getBairro() { return this->bairro; }

std::string Endereco::getCidade() { return this->cidade; }

std::string Endereco::getCep() { return this->cep; }

std::string Endereco::getUf() { return this->uf; }
