#include <iostream>
#include <fstream> 

#include "Empresa.hpp"
#include "EmpresaService.hpp"
#include "EmpresaController.hpp"
#include "Application.hpp"
#include "Produto.hpp"
#include "Desconto.hpp"
#include "cupom.hpp"
//Oi esquilinha <3

int main() {
    Application *app = new Application();
    app->init();

  std::cout<< "-------------------------------------------------------------------------"<< std::endl;
  std::cout<< "       "<< empresa->getNome()<<" - " << "Telefone: "<<empresa->getTelefone() <<std::endl;
  std::cout<< endereco->getLogradouro()<<", "<<endereco->getNumero()<<" - "<<endereco->getBairro() <<" - "<<endereco->getCidade()<<"-"<<endereco->getUf()<<" CEP "<<endereco->getCep()<<std::endl;
  std::cout<<"      CNPJ:"<<empresa->getCnpj()<<" - IE:"<<empresa->getIe()<<std::endl;
  std::cout<< "-------------------------------------------------------------------------"<< std::endl;
  std::cout<<"        DOCUMENTO AUXILIAR DA NOTA FISCAL DO CONSUMIDOR ELETRÔNICA         "<<std::endl;
  std::cout<< "-------------------------------------------------------------------------"<< std::endl;
  std::cout<<"I.  CÓDIGO      DESCRIÇÃO                    R$  UNI  QTD  DESCONTO  VAL(R$)"<<std::endl;

  //como faz pra ter o número de linhas correspondete ao numero de eprodutos?
  /// todo desenvolvimento da nota
  std::cout<< "-------------------------------------------------------------------------"<< std::endl;
  std::cout<< "                                                      TOTAL          "<</*soma dos valores*/<<std::endl;
  std::cout<< "-------------------------------------------------------------------------"<< std::endl;
  std::cout<<"NFC-e:  "<<cupom->getNumero()<< " - Série:" << cupom->getSerie() << "          "<<"Data: "<</*data*/<<" - Hora:"<</*colocar a hora*/<<std::endl;
    std::cout<< "-------------------------------------------------------------------------"<< std::endl;
  
}
//como delimitar 80 colunas?
//como fazer pra sair tudo bonitinho um alinhado com o outro?
  
