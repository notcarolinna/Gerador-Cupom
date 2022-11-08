#ifndef ENDERECO_H
#define ENDERECO_H

#pragma once

class Endereco
{
public:
    Endereco(std::string value);
    ~Endereco();
    std::string getValue();
    void setvalue(std::string value);
private:
    std::string value;
};

#endif
