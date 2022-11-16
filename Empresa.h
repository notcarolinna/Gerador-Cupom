#ifndef EMPRESA_h
#define EMPRESA_h

#include <vector>
#include "Endereco.h"
#include "Produto.h"
#include "Desconto.h"

#pragma once

class Empresa
{
public:
    Empresa(string nome, string cnpj, string ie, string telefone, Endereco* endereco);
    ~Empresa();

    void getProdutos();
    void getDescontos();

    string getNome();
    void setNome(string nome);

    string getCnpj();
    void setCnpj(string cnpj);

    string getIe();
    void setIe(string ie);

    string getTelefone();
    void setTelefone(string telefone);

    string getEndereco();
    void setEndereco(string endereco);

    string toString();
private:
    string nome;
    string cnpj;
    string ie;
    string telefone;
    Endereco* endereco;
    vector<Produto*> produtos;
    vector<Desconto*> descontos;
};

#endif
