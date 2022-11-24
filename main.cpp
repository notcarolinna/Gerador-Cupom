// Replit: 
// https://replit.com/@BiancaFerronato/trabalho-poo#main.cpp

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <ctime>

#include "Application.hpp"
#include "Compras.hpp"
#include "Cupom.hpp"
#include "Desconto.hpp"
#include "Empresa.hpp"
#include "EmpresaController.hpp"
#include "EmpresaService.hpp"
#include "Produto.hpp"

std::string Centraliza(std::string str, int largura) {
  int comprimento = str.length();
  int diferenca = largura - comprimento;
  int parte1 = diferenca / 2;
  int parte2 = diferenca - parte1;

  return std::string(parte1, ' ') + str + std::string(parte2, ' ');
}

void Data() {
   auto t = std::time(nullptr);
   auto tm = *std::localtime(&t);
   std::cout << std::put_time(&tm,"                    Data: %d/%m/%Y  - Hora: %H:%M:%S") <<setfill(' ')<<std::endl;
  }

int main() {
  Application *app = new Application();
  Compras *compras = new Compras();
  Cupom *cupom = new Cupom();
  app->init();

  // std::cout << " Tem " << app->getEmpresa()->numProdutos() << " na lista de
  // produtos " << std:endblo;
  std::string frase =
      "DOCUMENTO AUXILIAR DA NOTA FISCAL DO CONSUMIDOR ELETRÔNICA";

  std::cout << std::string(85, '-') << std::endl;
  /// linhas de separação
  std::cout << std::setfill(' '); // Parar com o - e usar espaço
  std::cout << Centraliza(app->getEmpresa()->getNome() + " - " +
                              "Telefone: " + app->getEmpresa()->getTelefone(),
                          85)
            << std::endl;
  std::cout << Centraliza(
                   app->getEmpresa()->getEndereco()->getLogradouro() + ", " +
                       app->getEmpresa()->getEndereco()->getNumero() + " - " +
                       app->getEmpresa()->getEndereco()->getBairro() + " - " +
                       app->getEmpresa()->getEndereco()->getCidade() + "-" +
                       app->getEmpresa()->getEndereco()->getUf() + " CEP " +
                       app->getEmpresa()->getEndereco()->getCep(),
                   85)
            << std::endl;
  std::cout << Centraliza("CNPJ:" + app->getEmpresa()->getCnpj() +
                              " - IE:" + app->getEmpresa()->getIe(),
                          85)
            << std::endl;
  std::cout << std::string(85, '-') << std::endl;
  std::cout << Centraliza(frase, 85) << std::endl;
  std::cout << std::string(85, '-') << std::endl;
  std::cout << "I. CÓDIGO        DESCRIÇÃO                             R$   UN QTD "
               " DESCONTO  VAL(R$)"
            << std::endl;

  int c1, c2;
  for (c1 = 0; c1 < compras->getSize(); c1++) {
    for (c2 = c1 + 1; c2 < compras->getSize(); c2++) {
      if (compras->getCodigo(c1) == compras->getCodigo(c2)) {
        compras->setQuantidade(c1, stoi(compras->getQuantidade(c1)) +
                                       stoi(compras->getQuantidade(c2)));
        compras->setQuantidade(c2, 0);
      }
    }
  }

  float soma_total = 0;
  float soma_unitaria = 0;
  int c, lin = 0;
  for (c = 0; c < compras->getSize();
       c++) { // passa por todos os elementos da lista de compras
    if (compras->getQuantidade(c) == "0")
      continue;
    int p;
    lin++;
    for (p = 0; p < app->getEmpresa()->numProdutos(); p++) {
      if (compras->getCodigo(c) ==
          app->getEmpresa()->getProduto(p)->getCodigo_barras()) {
        std::cout << std::right << setfill('0') << setw(2) << lin << " "
                  << compras->getCodigo(c) << " ";

        std::string desc = app->getEmpresa()->getProduto(p)->getDescricao();

        if (desc.size() > 35) {
          std::cout << desc << std::endl;
          std::cout << std::string(52, ' ');
        } else {
          std::cout << std::left << std::setfill(' ') << std::setw(35) << desc;
        }

        std::cout << std::right<< setfill(' ')<<setw(6)<< app->getEmpresa()->getProduto(p)->getPreco_uni()
                  << std::right<<setw(4)<< app->getEmpresa()->getProduto(p)->getMedida()
                  << "  "<<std::left<<setw(5)<< compras->getQuantidade(c);
        break;
      }
    }
    int d;
    float desc = 0;
    for (d = 0; d < app->getEmpresa()->numDescontos(); d++) {
      if (compras->getCodigo(c) ==
          app->getEmpresa()->getDesconto(d)->getCodigo_barras_a()) {
        switch (app->getEmpresa()->getDesconto(d)->getTipo()) {
        case 1:
          desc = (stoi(compras->getQuantidade(c))) *
                 (app->getEmpresa()->getProduto(p)->getPreco_uni()) *
                 (app->getEmpresa()
                      ->getDesconto(d)
                      ->getValor_desc()); 
          break;
        case 2:
          if ((stoi(compras->getQuantidade(c))) %
                  (app->getEmpresa()->getDesconto(d)->getNum_itens_levados()) ==
              0) {
            desc = app->getEmpresa()
                       ->getProduto(p)
                       ->getPreco_uni(); 
          }
          break;
        }
      }
    }
    for (d = 0; d < app->getEmpresa()->numDescontos(); d++) {
      if (compras->getCodigo(c) ==
              app->getEmpresa()->getDesconto(d)->getCodigo_barras_b() &&
          app->getEmpresa()->getDesconto(d)->getTipo() == 3) {
        int b;
        for (b = 0; b < compras->getSize(); b++) {
          if (compras->getCodigo(b) ==
                  app->getEmpresa()->getDesconto(d)->getCodigo_barras_a() &&
              stoi(compras->getQuantidade(b)) >=
                  app->getEmpresa()->getDesconto(d)->getNum_itens_levados()) {
            desc = (app->getEmpresa()->getDesconto(d)->getDesc_prod_b()) *
                   (app->getEmpresa()->getProduto(p)->getPreco_uni());
          }
        }
      }
    }

    soma_unitaria = (stof(compras->getQuantidade(c)) *
                     (app->getEmpresa()->getProduto(p)->getPreco_uni())) -
                    desc;
    if (desc == 0)
      std::cout << fixed << setprecision(2) << std::right<<setw(16)<< soma_unitaria
                << std::endl;
    else
      std::cout << fixed << setprecision(2) << std::right<<setw(7) << (-desc) << std::right<<setw(9)
                << soma_unitaria << std::endl;
    soma_total = soma_total + soma_unitaria;
  }

  std::cout << std::string(85, '-') << std::endl;
  std::cout << setw(69) << "TOTAL" << std::setfill(' ') << std::right<<setw(16) <<soma_total
            << std::endl;
  std::cout << std::string(85, '-') << std::endl;
  std::cout << "NFC-e: " << cupom->getNumero()
            << " - Série:" << cupom->getSerie() << "          ";
            Data();
          
  cupom->aumentanum();
}
