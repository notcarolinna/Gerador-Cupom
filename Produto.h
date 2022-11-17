#ifndef PRODUTO_h
#define PRODUTO_h

#pragma once

class Produto {
public:
    Produto(string codigo, string desc, string uni, string medida, string total_uni, string preco);
    ~Produto();
    string getCodigo_barras();
    string getDescricao();
    string getUni_ou_Gran();
    string getMedida();
    string getTotal_uni();
    string getPreco_uni();
    string toString();

private:
    string codigo_barras;
    string descricao;
    string uni_ou_gran; // como o produto é vendido
    string medida; // unidade de medida associada a embalagem
    string total_uni;
    string preco_uni; // preço unitario


};

#endif
