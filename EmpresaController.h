#ifndef EMPRESACONTROLLER_HPP
#define EMPRESACONTROLLER_HPP
#include "EmpresaService.hpp"
#pragma once

using namespace std;

class EmpresaController
{
public:
    EmpresaController(EmpresaService *empresaService);
    ~EmpresaController();

    void createEmpresa(std::string nome, std::string cnpj);
    Empresa * readEmpresa();
    
private:
    EmpresaService *empresaService;
};

#endif
