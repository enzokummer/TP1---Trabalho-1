#include "dominios.h"

void Dominios::setValor(const string& valor){
    validar(valor);
    this->valor = valor;
}
Dominios::Dominios(const string& valor){
    setValor(valor);
}

//Validando Codigo de Pagamento
void CodPagamento::validar(const string& valor){
    primeiroDigito = valor[0];
    size_t tamanhoCodigo = valor.length();
    //Verifica se o primeiro digito eh zero e se o codigo tem 8 digitos.
    if (primeiroDigito == '0' || tamanhoCodigo != 8)
        throw invalid_argument("Codigo invalido.");
}

//Validando Codigo de Titulo
void CodTitulo::validar(const string& valor){
    size_t tamanhoCodigo = valor.length();
    sigla = valor.substr(0,3);
    //Verifica se o codigo possui uma das siglas aleatorias
    //se nao tiver, recebe a classificacao invalida.
    //Tambem verifica se o codigo tem 11 digitos.
    string siglaValida = (sigla != "CDB" && sigla != "CRA" && sigla != "CRI"
                          && sigla != "LCA" && sigla != "LCI" && sigla != "DEB")
                           ? "invalida" : "valida";
    if (siglaValida == "invalida" || tamanhoCodigo != 11)
        throw invalid_argument("Codigo invalido.");
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
void Data::validar(const string& valor){
    if()
        throw invalid_argument("Data invalida.");
}

//Dinheiro INCOMPLETO!!
void Dinheiro::validar(const string& valor){
    if()
        throw invalid_argument("Dinheiro invalido.");
}

//Verifica se o Estado eh um dos 3 estados validos.
void Estado::validar(const string& valor){
    string estados[3] = {"Previsto","Liquidado",
    "Inadimplente"};

    bool valida = false;

    //Itera sobre a lista e compara com o valor de entrada
    for (const string &estado : estados){
        if (formato == valor){
            valida = true;
            break;
        }
    }
    if(!valida)
        throw invalid_argument("Estado invalido.");
}

//Verifica se o Nome atende os requisitos
void Nome::validar(const string& valor){
    size_t tamanhoNome = valor.length();
    quantosNomes = 1;
    posEspaco = 0;

    //Descobre quantos termos tem o nome e salva posicao do espaco ' '.
    //Tambem verifica se todos os caracteres sao validos.
    for (size_t i=0; i<tamanhoNome; i++){
        if(valor[i] == ' '){
            quantosNomes++;
            posEspaco = i;
        }
        if(isalpha(valor[i]) == 0 && valor[i] != ' '){
            throw invalid_argument("Nome com caractere invalido.");
        }
    }

    //Verifica se a primeira letra de cada termo eh maiuscula.
    if (!isupper(valor[0]) || (posEspaco != string::npos && !isupper(valor[posEspaco + 1])))
        throw invalid_argument("Nome invalido: deve começar com  letra maiuscula.");

    //Verifica se excedeu o numero maximo de nomes.
    if(quantosNomes > 2)
        throw invalid_argument("Numero maximo de nomes (2) excedido.");

    //Salva o tamanho dos termos em caso de nome composto.
    if(quantosNomes == 2){
        nome1 = valor.substr(0, posEspaco);
        nome2 = valor.substr(posEspaco + 1);
        size_t tamNome1 = nome1.length();
        size_t tamNome2 = nome2.length();
    }

    //Verifica se os termos tem a quantidade correta de caracteres
    if((quantosNomes == 1 && (tamanhoNome > 10 || tamanhoNome < 3))
        || tamNome1 > 10 || tamNome1 < 3 || tamNome2 > 10 || tamNome2 < 3)
        throw invalid_argument("Numero maximo de caracteres por nome excedido.");

}

//Verifica se o Percentual ta entre 0 e 100
void Percentual::validar(const int& valor){
    if(valor > MAX || or valor < MIN)
        throw invalid_argument("Percentual invalido.");
}

//Validando a senha
void Senha::validar(const string& valor){
    //Verifica se o primeiro digito eh zero
    if(valor[0] == '0')
        throw invalid_argument("Senha invalida: primeiro digito tem que ser diferente de zero");

    size_t tamanhoSenha = valor.length();
    //Verifica tamanho da senha
    if(tamanhoSenha != 6)
        throw invalid_argument("Senha invalida: senha deve ter 6 digitos");

    for(size_t i=0; i<tamanhoSenha; i++){
    //Verifica se a senha eh numerica
        if(isdigit(valor[i] == 0)
           throw invalid_argument("Senha invalida: caracter nao numerico identificado");
    }

    //Verifica se a senha eh sequencial
    string senhasInvalidas[8] = {"123456","234567","345678",
    "456789","987654","876543","765432","654321"};
    for(size_t i=0; i<8; i++){
        if(valor == senhasInvalidas[i])
            throw invalid_argument("Senha invalida: senha sequencial identificada");
    }

    //Verifica se ha digito duplicado
    int count[10] = {0};
    for (char c : valor){
        int digito = c - '0';
        if(count[digito] > 0)
            throw invalid_argument("Senha invalida: digito duplicado identificado");
        count[digito]++;
    }

}

//Verifica se o Setor eh um dos 10 setores validos.
void Setor::validar(const string& valor){
    string setores[10] = {"Agricultura","Construcao Civil",
    "Energia","Financas","Imobiliario","Papel e celulose",
    "Pecuaria","Quimica e petroquimica","Metalurgia e siderurgia",
    "Mineracao"};
    bool valida = false;

    //Itera sobre a lista e compara com o valor de entrada
    for (const string &setor : setores){
        if (formato == valor){
            valida = true
            break;
        }
    }
    if(!valida)
        throw invalid_argument("Setor invalido.");
}
