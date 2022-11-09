#include <string>
#include <sstream>

#include "Empresa.h"

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

std::string Empresa::getEndereco(){
    this->endereco->getValue();
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
