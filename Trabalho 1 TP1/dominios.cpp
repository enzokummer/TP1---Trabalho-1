#include "dominios.h"

void Dominios::setValor(const string& valor){
    validar(valor);
    this->valor = valor;
}
Dominios::Dominios(const string& valor){
    setValor(valor);
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
CPF::CPF(){
    this->valor = '00000000000';
}
CPF::CPF(const string& valor){
    if(validar(valor)){
        this->valor=valor;
    }
    else{
        throw invalid_argument("CPF invalido.");
    }

}

//CPF INCOMPLETO!!
void CPF::validar(string valor){
    // Remover caracteres não numéricos
        string cpfNumerico = "";
        for (char c : valor) {
            if (isdigit(c)) {
                cpfNumerico += c;
            }
        }

        // Verificar se o CPF tem 11 dígitos
        if (cpfNumerico.length() != 11) {
            throw invalid_argument("CPF invalido.");
        }

        // Verificar se todos os dígitos são iguais
        bool todosIguais = true;
        for (int i = 1; i < 11; i++) {
            if (cpfNumerico[i] != cpfNumerico[0]) {
                todosIguais = false;
                break;
            }
        }
        if (todosIguais) {
            throw invalid_argument("CPF invalido.");
        }

        // Calcular o primeiro dígito verificador
        int soma = 0;
        for (int i = 0; i < 9; i++) {
            soma += (cpfNumerico[i] - '0') * (10 - i);
        }
        int resto = soma % 11;
        int digitoVerificador1 = resto < 2 ? 0 : 11 - resto;

        // Calcular o segundo dígito verificador
        soma = 0;
        for (int i = 0; i < 10; i++) {
            soma += (cpfNumerico[i] - '0') * (11 - i);
        }
        resto = soma % 11;
        int digitoVerificador2 = resto < 2 ? 0 : 11 - resto;

        // Verificar se os dígitos verificadores são iguais aos dígitos do CPF
        if (cpfNumerico[9] - '0' != digitoVerificador1) || (cpfNumerico[10] - '0' != digitoVerificador2) {
            throw invalid_argument("CPF invalido.");
            };
}


//Data INCOMPLETO!!
void Data::validar(string valor){
    if()
        throw invalid_argument("CPF invalido.");
}

//Dinheiro INCOMPLETO!!
void Dinheiro::validar(string valor){
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
       || tamanhoNome < 2 || (quantosNomes == 1 && tamanhoNome > 10)
       || tamNome1 < 2 || tamNome1 > 10 || tamNome2 < 2 || tamNome2 >10)
        throw invalid_argument("Nome invalido.");
}

//Percentual INCOMPLETO!!
void Percentual::validar(string valor){
    if()
        throw invalid_argument("CPF invalido.");
}

//Senha INCOMPLETO!!
void Senha::validar(string valor){
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
            valida = true
            break;
        }
    }
    if(!valida)
        throw invalid_argument("Setor invalido.");
}
