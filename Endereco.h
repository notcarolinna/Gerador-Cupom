#ifndef ENDERECO_HPP
#define ENDERECO_HPP

#pragma once

class Endereco
{
public:
    Endereco(std::string line);
    ~Endereco();
    std::string getLogradouro();
    std::string getNumero();
    std::string getComplemento();
    std::string getBairro();
    std::string getCidade();
    std::string getUf();
    std::string getCep();

private:
  std::string logradouro;
  std::string numero;
  std::string complemento; 
  std::string bairro;
  std::string cidade;
  std::string uf;
  std::string cep;
};

#endif
