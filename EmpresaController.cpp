#include <string>

#include "Empresa.h"
#include "EmpresaService.h"
#include "EmpresaController.h"

using namespace std;

EmpresaController::EmpresaController(EmpresaService *empresaService)
{
    this->empresaService = empresaService;
}

EmpresaController::~EmpresaController()
{

}

void EmpresaController::createEmpresa(std::string nome, std::string cnpj){

}

Empresa * EmpresaController::readEmpresa(){
    return this->empresaService->get();
}

void EmpresaController::updateEmpresa(std::string cnpj){

}

void EmpresaController::deleteEmpresa(std::string cnpj){

}
