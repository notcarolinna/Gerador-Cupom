#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include <vector>
#include "Endereco.hpp"
#include "Produto.hpp"
#include "Desconto.hpp"

#pragma once

class Empresa
{
public:
    Empresa(std::string nome, std::string cnpj, std::string ie, std::string telefone, Endereco *endereco);
    ~Empresa();

    void getProdutos();
    void getDescontos();

    std::string getNome();
    void setNome(std::string nome);

    std::string getCnpj();
    void setCnpj(std::string cnpj);

    std::string getIe();
    void setIe(std::string ie);

    std::string getTelefone();
    void setTelefone(std::string telefone);

    Endereco * getEndereco();
    void setEndereco(std::string endereco);

    std::string toString();

private:
    std::string nome;
    std::string cnpj;
    std::string ie;
    std::string telefone;
    Endereco *endereco;
    std::vector<Produto *> produtos;
    std::vector<Desconto *> descontos;

public:
    int numProdutos( ) {
      return produtos.size();
    }

    Produto* getProduto( int p ) {
      return produtos[p];
    }

    int numDescontos( ) {
      return descontos.size();
    }

    Desconto* getDesconto( int d ) {
      return descontos[d];
    }

};

#endif
