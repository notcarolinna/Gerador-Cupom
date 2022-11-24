#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Empresa.hpp"
#include "EmpresaController.hpp"

#pragma once

class Application
{
public:
    Application();
    ~Application();
    void init();
    Empresa * getEmpresa();
private:
    EmpresaController *empresaController;
    Empresa *empresa;
};

#endif
