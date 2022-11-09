#ifndef APPLICATION_H
#define APPLICATION_H

#pragma once

class Application
{
public:
    Application();
    ~Application();
    void init();
private:
    EmpresaController *empresaController;
    Empresa *empresa;
};

#endif
