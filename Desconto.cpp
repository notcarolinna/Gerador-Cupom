#include "Desconto.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Desconto::Desconto(string cod, string valor) {
	this->tipo = 1;
	this->codigo_barras_a = cod;
	this->valor_desc = valor;
}

Desconto::Desconto(string cod, string levados, string pagos) {
	this->tipo = 2;
	this->codigo_barras_a = cod;
	this->num_itens_levados = levados;
	this->num_itens_pagos = pagos;
}

Desconto::Desconto(string codigo_a, string levados, string codigo_b, string pagos, string desc_b) {
	this->tipo = 3;
	this->codigo_barras_a = codigo_a;
	this->num_itens_levados = levados;
	this->codigo_barras_b = codigo_b;
	this->num_itens_pagos = pagos;
	this->desc_prod_b = desc_b;
}



