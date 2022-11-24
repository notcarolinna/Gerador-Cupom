#include <string>
#include <iostream>

#include "Empresa.hpp"
#include "EmpresaService.hpp"
#include "EmpresaController.hpp"

#include "Application.hpp"

Application::Application()
{
    this->empresaController = new EmpresaController(new EmpresaService());
}

Application::~Application() { }

void Application::init() {
    this->empresa = this->empresaController->readEmpresa();
    this->empresa->getProdutos();
    this->empresa->getDescontos();
}

Empresa* Application::getEmpresa(){
  return empresa;
}
