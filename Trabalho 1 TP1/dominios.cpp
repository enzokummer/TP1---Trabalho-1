#include "dominios.h"

void Dominios::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

void CodPagamento::validar(string valor){
    primeiroDigito = valor[0];
    tamanhoCodigo = valor.length();
    if (primeiroDigito == '0' || tamanhoCodigo != 8)
        throw invalid_argument("Codigo invalido.");
}

void CodTitulo::validar(string valor){
    tamanhoCodigo = valor.length();
    sigla = valor.substr(0,3);
    string siglaValida = (sigla != "CDB" && sigla != "CRA" && sigla != "CRI"
                          && sigla != "LCA" && sigla != "LCI" && sigla != "DEB")
                           ? "invalida" : "valida";
    if (siglaValida == "invalida" || tamanhoCodigo != 11)
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
void Nome::validar(string valor){
    tamanhoNome = valor.length();
    quantosNomes = 1;
    posEspaco = 0;
    bool caractereInvalido = false;
    for (i=0; i<tamanhoNome; i++){
        if(valor[i] == ' '){
            quantosNomes++;
            posEspaco = i;
        }
        if(isalpha(valor[i]) == 0)
            caractereInvalido = true;
    }
    if(quantosNomes == 2){
        nome1 = "";
        for(k=0; k<i; k++){
            nome1 += valor[k];
        }
        nome2 = "";
        for(k=0; k<tamanhoNome; k++){
            nome2 += valor[k];
        }
            tamNome1 = nome1.length();
            tamNome2 = nome2.length();
    }
    if(quantosNomes > 2 || caractereInvalido == true
       || tamanhoNome < 2 || tamanhoNome > 10 || tamNome1 < 2
       || tamNome1 > 10 || tamNome2 < 2 || tamNome2 >10)
        throw invalid_argument("Nome invalido.");
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
