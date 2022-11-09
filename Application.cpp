#include <string>
#include <iostream>

#include "Empresa.h"
#include "EmpresaService.h"
#include "EmpresaController.h"

#include "Application.h"

Application::Application()
{
    this->empresaController = new EmpresaController(new EmpresaService());
}

Application::~Application()
{

}

void Application::init() {
    this->empresa = this->empresaController->readEmpresa();

    cout << this->empresa->toString() << endl;
}
