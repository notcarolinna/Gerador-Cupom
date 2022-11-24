#include <string>
#include <sstream>
#include <fstream> 

#include "Empresa.hpp"

using namespace std;

Empresa::Empresa(string nome, string cnpj, string ie, string telefone, Endereco *endereco)
{
    this->nome = nome;
    this->cnpj = cnpj;
    this->ie = ie;
    this->telefone = telefone;
    this->endereco = endereco;
}

Empresa::~Empresa()
{
    if(this->endereco) 
        delete (this->endereco);
}

std::string Empresa::getNome(){
    return this->nome;
}

void Empresa::setNome(std::string nome){
    this->nome = nome;
}

std::string Empresa::getCnpj(){
    return this->cnpj;
}
void Empresa::setCnpj(std::string cnpj){
    this->cnpj = cnpj;
}

std::string Empresa::getIe(){
    return this->ie;
}

void Empresa::setIe(std::string ie){
    this->ie = ie;
}

std::string Empresa::getTelefone(){
    return this->telefone;
}

void Empresa::setTelefone(std::string telefone){
    this->telefone = telefone;
}

Endereco * Empresa::getEndereco(){
  return endereco;
}

void Empresa::setEndereco(std::string endereco){
    this->endereco = new Endereco(endereco);
}

std::string Empresa::toString() {
    stringstream ss;
    
    ss << "Nome: " << this->getNome() << endl;
    ss << "CNPj: " << this->getCnpj() << endl;
    ss << "IE: " << this->getIe() << endl;
    ss << "Telefone: " << this->getTelefone() << endl;
    ss << "Endereco: " << this->getEndereco() << endl;
    return ss.str();
}

void Empresa::getProdutos() {
 
std::ifstream infile("data/produtos.csv");
std::string line; 

  std::string codigo_barras;
  std::string descricao;
  std::string uni_ou_gran; // como o produto é vendido
  std::string medida; // unidade de medida associada a embalagem
  std::string total_uni;
  std::string preco_uni; 

while(std::getline(infile, line)){
   int campo = 0;
    std::string delimiter = ";";
    line = line + delimiter;
    size_t pos = 0;
    std::string wait;
    while((pos = line.find(delimiter)) != std::string::npos){
        wait = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        if(campo == 0){
            codigo_barras = wait;
        } else if(campo == 1){
            descricao = wait;
        } else if(campo == 2){
            uni_ou_gran = wait;
        } else if(campo == 3){
            medida = wait;
        } else if(campo == 4){
            total_uni = wait;
        } else if(campo == 5){
            preco_uni = wait;
        }
        campo++;
    }
     Produto * P = new Produto( codigo_barras, descricao, uni_ou_gran, medida, total_uni, preco_uni);
     produtos.push_back(P);
  }
}

void Empresa::getDescontos() {

std::ifstream infile("data/desconto.csv");
std::string line; 

std::string codigo_barras_a; //campo 1
std::string valor_desc; // campo 2
std::string num_itens_levados; //campo 3
std::string num_itens_pagos; //campo 4
std::string codigo_barras_b; //campo 5
std:: string desc_prod_b; // campo 6


while(std::getline(infile,line)){
    int aju = 0;
    std::string delimiter = ";";
    line = line + delimiter;
    size_t pos = 0;
    std::string carry;
    while((pos = line.find(delimiter)) != std::string::npos){
        carry = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
      
        if(aju == 0){
            codigo_barras_a = carry;
        } else if (aju == 1){ // campo 2
            valor_desc = carry;
        } else if(aju == 2){
            num_itens_levados = carry; //campo 3
        } else if(aju == 3){
            num_itens_pagos = carry; // campo 4
        }else if( aju == 4){
            codigo_barras_b = carry; //campo 5
        }else if (aju ==5){
            desc_prod_b = carry; //campo 6
        }
        aju++;
    }
  Desconto * d = nullptr;
  if ( valor_desc != "" ) {   // Desconto 1
     d = new Desconto( codigo_barras_a, valor_desc );
  }
  
  if ( valor_desc == "" ) {   // Desconto 2 ou 3
    if ( codigo_barras_b == "" ) {   // Desconto 2
       d = new Desconto( codigo_barras_a, num_itens_levados, num_itens_pagos ); // Desc 2
    }
    else {
       d = new Desconto( codigo_barras_a, num_itens_levados, codigo_barras_b, num_itens_pagos, desc_prod_b ); // Desc 3
    }
  }    

  descontos.push_back( d );
}

}
