#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <fstream>
#include <iostream>
#include <sstream>

class Produto {
public:
   Produto(std::string codigo, std::string desc, std::string uni, std::string medida, std::string total_uni, std::string preco);
    ~Produto();
    std::string getCodigo_barras();
    std::string getDescricao();
    std::string getUni_ou_Gran();
    std::string getMedida();
    std::string getTotal_uni();
    float getPreco_uni();
    std::string toString();

private:
  std::string codigo_barras;
  std::string descricao;
  std::string uni_ou_gran; // como o produto é vendido
  std::string medida; // unidade de medida associada a embalagem
  std::string total_uni;
  std::string preco_uni; 


};

#endif
