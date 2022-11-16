#include <string>
#include <sstream>
#include <fstream> 

#include "Empresa.h"

using namespace std;

Empresa::Empresa(string nome, string cnpj, string ie, string telefone, Endereco* endereco)
{
    this->nome = nome;
    this->cnpj = cnpj;
    this->ie = ie;
    this->telefone = telefone;
    this->endereco = endereco;
}

Empresa::~Empresa()
{
    if (this->endereco)
        delete (this->endereco);
}

string Empresa::getNome() {
    return this->nome;
}

void Empresa::setNome(string nome) {
    this->nome = nome;
}

string Empresa::getCnpj() {
    return this->cnpj;
}
void Empresa::setCnpj(string cnpj) {
    this->cnpj = cnpj;
}

string Empresa::getIe() {
    return this->ie;
}

void Empresa::setIe(string ie) {
    this->ie = ie;
}

string Empresa::getTelefone() {
    return this->telefone;
}

void Empresa::setTelefone(string telefone) {
    this->telefone = telefone;
}

string Empresa::getEndereco() {
    return
        this->endereco->getLogradouro() + " " +
        this->endereco->getNumero() + " " +
        this->endereco->getComplemento() + " " +
        this->endereco->getBairro() + " " +
        this->endereco->getCidade() + " " +
        this->endereco->getCep();
}

void Empresa::setEndereco(string endereco) {
    this->endereco = new Endereco(endereco);
}

string Empresa::toString() {
    stringstream ss;

    ss << "Nome: " << this->getNome() << endl;
    ss << "CNPj: " << this->getCnpj() << endl;
    ss << "IE: " << this->getIe() << endl;
    ss << "Telefone: " << this->getTelefone() << endl;
    ss << "Endereco: " << this->getEndereco() << endl;
    return ss.str();
}

void Empresa::getProdutos() {

    ifstream infile("data/produtos.csv");
    string line;

    string codigo_barras;
    string descricao;
    string uni_ou_gran; // como o produto é vendido
    string medida; // unidade de medida associada a embalagem
    string total_uni;
    string preco_uni; // preço unitario

    while (getline(infile, line)) {
        int campo = 0;
        string delimiter = ";";
        line = line + delimiter;
        size_t pos = 0;
        string wait;
        while ((pos = line.find(delimiter)) != string::npos) {
            wait = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            if (campo == 0) {
                codigo_barras = wait;
            }
            else if (campo == 1) {
                descricao = wait;
            }
            else if (campo == 2) {
                uni_ou_gran = wait;
            }
            else if (campo == 3) {
                medida = wait;
            }
            else if (campo == 4) {
                total_uni = wait;
            }
            else if (campo == 5) {
                preco_uni = wait;
            }
            campo++;
        }
        Produto* P = new Produto(codigo_barras, descricao, uni_ou_gran, medida, total_uni, preco_uni);
        cout << P->toString() << endl;
        produtos.push_back(P);
    }
}

void Empresa::getDescontos() {

    ifstream infile("data/desconto.csv");
    string line;

    string codigo_barras_a; //campo 1
    string valor_desc; // campo 2
    string num_itens_levados; //campo 3
    string num_itens_pagos; //campo 4
    string codigo_barras_b; //campo 5
    string desc_prod_b; // campo 6


    while (getline(infile, line)) {
        int aju = 0;
        string delimiter = ";";
        line = line + delimiter;
        size_t pos = 0;
        string carry;
        while ((pos = line.find(delimiter)) != string::npos) {
            carry = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());

            if (aju == 0) {
                codigo_barras_a = carry;
            }
            else if (aju == 1) { // campo 2
                valor_desc = carry;
            }
            else if (aju == 2) {
                num_itens_levados = carry; //campo 3
            }
            else if (aju == 3) {
                num_itens_pagos = carry; // campo 4
            }
            else if (aju == 4) {
                codigo_barras_b = carry; //campo 5
            }
            else if (aju == 5) {
                desc_prod_b = carry; //campo 6
            }
            aju++;
        }
        Desconto* d = nullptr;
        // Que desconto é?
        if (valor_desc != "") {   // Desconto 1
            d = new Desconto(codigo_barras_a, valor_desc);
        }

        if (valor_desc == "") {   // Desconto 2 ou 3
            if (codigo_barras_b == "") {   // Desconto 2
                d = new Desconto(codigo_barras_a, num_itens_levados, num_itens_pagos); // Desc 2
            }
            else {
                d = new Desconto(codigo_barras_a, num_itens_levados, codigo_barras_b, num_itens_pagos, desc_prod_b); // Desc 3
            }
        }

        descontos.push_back(d);
    }

}
