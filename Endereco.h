#ifndef ENDERECO_h
#define ENDERECO_h

#pragma once

class Endereco
{
public:
    Endereco(string line);
    ~Endereco();
    string getLogradouro();
    string getNumero();
    string getComplemento();
    string getBairro();
    string getCidade();
    string getCep();

private:
    string logradouro;
    string numero;
    string complemento;
    string bairro;
    string cidade;
    string cep;
};

#endif
