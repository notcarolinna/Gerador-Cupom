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

Application::~Application() { }

void Application::init() {
    this->empresa = this->empresaController->readEmpresa();
    cout << "Li empresa " << endl;
    this->empresa->getProdutos();
    cout << "Li produtos " << endl;
    this->empresa->getDescontos();
    cout << "Li descontos " << endl;

    cout << this->empresa->toString() << endl;
}
