#include <string>

#include "Empresa.h"
#include "EmpresaService.h"
#include "EmpresaController.h"

using namespace std;

EmpresaController::EmpresaController(EmpresaService* empresaService)
{
    this->empresaService = empresaService;
}

EmpresaController::~EmpresaController()
{

}

void EmpresaController::createEmpresa(string nome, string cnpj) {

}

Empresa* EmpresaController::readEmpresa() {
    return this->empresaService->get();
}

void EmpresaController::updateEmpresa(string cnpj) {

}

void EmpresaController::deleteEmpresa(string cnpj) {

}
