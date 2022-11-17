#include <fstream>
#include <iostream>
#include <sstream>
#include "Produto.hpp"

Produto::Produto(std::string codigo, std::string desc, std::string uni, std::string medida, std::string total_uni, std::string preco) {
  this->codigo_barras = codigo;
  this->descricao = desc;
  this->uni_ou_gran = uni;
  this->medida = medida;
  this->total_uni = total_uni;
  this->preco_uni = preco;
  } 

std::string Produto::getCodigo_barras(){
    return this->codigo_barras;
}

std::string Produto::getDescricao(){
    return this->descricao;
}

std::string Produto::getUni_ou_Gran(){
  return this->uni_ou_gran;
}

std::string Produto::getMedida(){
  return this->medida;
}

std::string Produto::getTotal_uni(){
return this->total_uni;
}

std::string Produto::getPreco_uni(){
return this->preco_uni;
}

std::string Produto::toString() {
    std::stringstream ss;
    
    ss << "Cod: " << this->getCodigo_barras() << std::endl;
    ss << "Desc: " << this->getDescricao() << std::endl;
    ss << "Uni: " << this->getUni_ou_Gran() << std::endl;
    ss << "Medida: " << this->getMedida() << std::endl;
    ss << "Total_uni: " << this->getTotal_uni() << std::endl;
    ss << "Preco_uni: " << this->getPreco_uni() << std::endl;
    return ss.str();
}
