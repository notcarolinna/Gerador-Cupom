#ifndef DESCONTO_HPP
#define DESCONTO_HPP
#include <iostream>
#include <string>

#pragma once
 
class Desconto{

int tipo;
std::string codigo_barras_a; //campo 1
std::string valor_desc; // campo 2
std::string num_itens_levados; //campo 3
std::string num_itens_pagos; //campo 4
std::string codigo_barras_b; //campo 5
std::string desc_prod_b; // campo 6


public: 
Desconto( std::string, std::string );
Desconto( std::string, std::string, std::string );
Desconto( std::string, std::string, std::string, std::string, std::string );
std::string toString();
std::string getCodigo_barras_a();
float getValor_desc();
int getNum_itens_levados();
int getNum_itens_pagos();
std::string getCodigo_barras_b();
float getDesc_prod_b();
int getTipo();

};

#endif
