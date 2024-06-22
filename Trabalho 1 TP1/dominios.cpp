#include "dominios.h"

void Dominios::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

void CodPagamento::validar(string valor){
    primeiro_digito = valor[0];
    tamanho_codigo = valor.length();
    if (primeiro_digito == '0' || tamanho_codigo != 8)
        throw invalid_argument("Codigo invalido.");
}

void CodTitulo::validar(string valor){
    tamanho_codigo = valor.length();
    sigla = valor.substr(0,3);
    string siglaValida = (sigla != "CDB" && sigla != "CRA" && sigla != "CRI"
                          && sigla != "LCA" && sigla != "LCI" && sigla != "DEB")
                           ? "invalida" : "valida";
    if (siglaValida == "invalida" || tamanho_codigo != 11)
        throw invalid_argument("Codigo invalido.");
}
//CPF INCOMPLETO!!
void CPF::validar(string valor){
    if()
        throw invalid_argument("CPF invalido.");
}

//Data INCOMPLETO!!
void CPF::validar(string valor){
    if()
        throw invalid_argument("CPF invalido.");
}

//Dinheiro INCOMPLETO!!
void CPF::validar(string valor){
    if()
        throw invalid_argument("CPF invalido.");
}

void Estado::validar(string valor){
    string estados[3] = {"Previsto","Liquidado",
    "Inadimplente"};

    bool valida = false;

    for (const string &estado : estados){
        if (formato == valor){
            valida = true;
            break;
        }
    }
    if(!valida)
        throw invalid_argument("Estado invalido.");
}

//Nome INCOMPLETO!!
void CPF::validar(string valor){
    if()
        throw invalid_argument("CPF invalido.");
}

//Percentual INCOMPLETO!!
void CPF::validar(string valor){
    if()
        throw invalid_argument("CPF invalido.");
}

//Senha INCOMPLETO!!
void CPF::validar(string valor){
    if()
        throw invalid_argument("CPF invalido.");
}

void Setor::validar(string valor){
    string setores[3] = {"Agricultura","Construcao Civil",
    "Energia","Financas","Imobiliario","Papel e celulose",
    "Pecuaria","Quimica e petroquimica","Metalurgia e siderurgia",
    "Mineracao"};
    bool valida = false;

    for (const string &setor : setores){
        if (formato == valor){
            valida = true;
            break;
        }
    }
    if(!valida)
        throw invalid_argument("Setor invalido.");
}
