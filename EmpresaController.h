#ifndef EMPRESACONTROLLER_H
#define EMPRESACONTROLLER_H

#pragma once

using namespace std;

class EmpresaController
{
public:
    EmpresaController(EmpresaService *empresaService);
    ~EmpresaController();

    void createEmpresa(std::string nome, std::string cnpj);
    Empresa * readEmpresa();
    void updateEmpresa(std::string cnpj);
    void deleteEmpresa(std::string cnpj);

private:
    EmpresaService *empresaService;
};

#endif
