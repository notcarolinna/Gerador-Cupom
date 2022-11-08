#ifndef EMPRESA_H
#define EMPRESA_H

#include "Endereco.h"

#pragma once

class Empresa
{
public:
    Empresa(std::string nome, std::string cnpj, std::string ie, std::string telefone, Endereco *endereco);
    ~Empresa();

    std::string getNome();
    void setNome(std::string nome);

    std::string getCnpj();
    void setCnpj(std::string cnpj);

    std::string getIe();
    void setIe(std::string ie);

    std::string getTelefone();
    void setTelefone(std::string telefone);

    std::string getEndereco();
    void setEndereco(std::string endereco);

    std::string toString();
private:
    std::string nome;
    std::string cnpj;
    std::string ie;
    std::string telefone;
    Endereco *endereco;
};

#endif
