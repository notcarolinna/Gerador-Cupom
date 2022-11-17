#include <fstream>   // para usar file streams (ifstream, ofstream)
#include <iostream>  // para usar cin, cout
#include <string>    // para usar string
#include <iomanip>   // para usar manip. (setw, right, ...)
#include <cstdlib>   // para usar srand(), rand() e exit()
#include <ctime>     // para usar time()
#include "Empresa.h"
#include "EmpresaService.h"

using namespace std;

EmpresaService::EmpresaService()
{

}

EmpresaService::~EmpresaService()
{

}

Empresa* EmpresaService::get() {
    ifstream infile("data/empresa.csv");
    string line;

    string nome;
    string cnpj;
    string ie;
    string telefone;
    string endereco;

    int attr = 0;
    while (getline(infile, line))
    {
        string delimiter = ";";
        line = line + delimiter; // "gruda a linha com o ;"
        size_t pos = 0;
        string token;
        while ((pos = line.find(delimiter)) != string::npos) {
            token = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            if (attr == 0) {
                nome = token;
            }
            else if (attr == 1) {
                cnpj = token;
            }
            else if (attr == 2) {
                ie = token;
            }
            else if (attr == 3) {
                endereco = token;
            }
            else if (attr == 4) {
                telefone = token;
            }
            attr++;
        }
    }

    Empresa* empresa = new Empresa(nome, cnpj, ie, telefone, new Endereco(endereco));
    return empresa;
}
