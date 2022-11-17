#ifndef DESCONTO_h
#define DESCONTO_h
#include <iostream>
#include <string>

using namespace std;

#pragma once

class Desconto {

	int tipo;
	string codigo_barras_a; //campo 1
	string valor_desc; // campo 2
	string num_itens_levados; //campo 3
	string num_itens_pagos; //campo 4
	string codigo_barras_b; //campo 5
	string desc_prod_b; // campo 6

public:
	Desconto(string, string);
	Desconto(string, string, string);
	Desconto(string, string, string, string, string);

};

#endif
