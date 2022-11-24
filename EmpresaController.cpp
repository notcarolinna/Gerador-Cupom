#include <string>

#include "Empresa.hpp"
#include "EmpresaService.hpp"
#include "EmpresaController.hpp"

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

