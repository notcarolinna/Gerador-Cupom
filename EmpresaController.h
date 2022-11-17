#ifndef EMPRESACONTROLLER_h
#define EMPRESACONTROLLER_h

#pragma once

using namespace std;

class EmpresaController
{
public:
    EmpresaController(EmpresaService* empresaService);
    ~EmpresaController();

    void createEmpresa(string nome, string cnpj);
    Empresa* readEmpresa();
    void updateEmpresa(string cnpj);
    void deleteEmpresa(string cnpj);

private:
    EmpresaService* empresaService;
};

#endif
