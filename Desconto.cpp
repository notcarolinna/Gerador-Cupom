#include "Desconto.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

Desconto::Desconto( std::string cod, std::string valor ) {
  this->tipo = 1;
  this->codigo_barras_a = cod;
  this->valor_desc = valor;
}

Desconto::Desconto( std::string cod, std::string levados, std::string pagos ) {
  this->tipo = 2;
  this->codigo_barras_a = cod;
  this->num_itens_levados = levados;
  this->num_itens_pagos = pagos;
}

Desconto::Desconto( std::string codigo_a, std::string levados, std::string codigo_b, std::string pagos, std::string desc_b ){
  this->tipo = 3;
  this->codigo_barras_a = codigo_a;
  this->num_itens_levados = levados;
  this->codigo_barras_b = codigo_b;
  this->num_itens_pagos = pagos;
  this->desc_prod_b = desc_b;
}

std::string Desconto::toString() {
    std::stringstream ss;
    
    ss << "Cod_a: " << this->getCodigo_barras_a() << std::endl;
    ss << "Desc_a: " << this->getValor_desc() << std::endl;
    ss << "Uni_lev: " << this->getNum_itens_levados() << std::endl;
    ss << "Uni_pag: " << this->getNum_itens_pagos() << std::endl;
    ss << "Cod_b: " << this->getCodigo_barras_b() << std::endl;
    ss << "Desc_b: " << this->getDesc_prod_b() << std::endl;
    return ss.str();
  }

std::string Desconto::getCodigo_barras_a(){
    return this->codigo_barras_a;
}

float Desconto::getValor_desc(){
    float valor = stof(valor_desc);
    return valor;
}

int Desconto::getNum_itens_levados(){
  int num_itens_l = stoi(num_itens_levados);
  return num_itens_l;
}

int Desconto::getNum_itens_pagos(){
  int num_itens_p = stoi(num_itens_pagos);
  return num_itens_p;
}

std::string Desconto::getCodigo_barras_b(){
return this->codigo_barras_b;
}

float Desconto::getDesc_prod_b(){
  float desc_b = stof(desc_prod_b);
return desc_b;
}

int Desconto::getTipo(){
  return tipo;
}


