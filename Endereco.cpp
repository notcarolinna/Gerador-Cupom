#include <string>
#include <iostream>

#include "Endereco.h"

using namespace std;

Endereco::Endereco(string line) {

    int aux = 0;
    string delimiter = ":";
    line = line + delimiter;
    size_t pos = 0;  // size_t é tipo um int, só q pra tamanhos de objetos
    string hold; // a string q armazena temporariamente os valores
    while ((pos = line.find(delimiter)) != string::npos) { // npos = é tipo o \0 , indica o fim da string
        hold = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());

        if (aux == 0) {
            logradouro = hold;
        }
        else if (aux == 1) {
            numero = hold;
        }
        else if (aux == 2) {
            complemento = hold;
        }
        else if (aux == 3) {
            bairro = hold;
        }
        else if (aux == 4) {
            cidade = hold;
        }
        else if (aux == 5) {
            cep = hold;
        }
        aux++;
    }
}

Endereco::~Endereco() { }

string Endereco::getLogradouro() {
    return this->logradouro;
}

string Endereco::getNumero() {
    return this->numero;
}

string Endereco::getComplemento() {
    return this->complemento;
}

string Endereco::getBairro() {
    return this->bairro;
}

string Endereco::getCidade() {
    return this->cidade;
}

string Endereco::getCep() {
    return this->cep;
}
