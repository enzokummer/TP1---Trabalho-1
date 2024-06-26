#include "dominios.h"

void Dominios::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

//Validando Codigo de Pagamento
void CodPagamento::validar(string valor){
    char primeiroDigito = valor[0];
    size_t tamanhoCodigo = valor.length();
    //Verifica se o primeiro digito eh zero e se o codigo tem 8 digitos.
    if (primeiroDigito == '0' || tamanhoCodigo != 8)
        throw invalid_argument("Codigo invalido.");
}

//Validando Codigo de Titulo
void CodTitulo::validar(string valor){
    size_t tamanhoCodigo = valor.length();
    string sigla = valor.substr(0,3);
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
            throw invalid_argument("CPF Invalido");
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
            throw invalid_argument("CPF Invalido");
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
         if((cpfNumerico[9] - '0' != digitoVerificador1) || (cpfNumerico[10] - '0' != digitoVerificador2)){
            throw invalid_argument("CPF Invalido");
         }
}
CPF::CPF(string valor){
    setValor(valor);
}

//Verifica se eh bissexto
bool Data::isBissexto(string valor){
    string subs;
    subs = valor.substr(7);
    int ano = stoi(subs);

    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
        return true;
    } else {
        return false;
    }
}
//Validando a data
void Data::validar(string valor){
    int diasMes = 0;

    //Separando a data
    int dia = stoi(valor.substr(0,2));
    int mes = stoi(valor.substr(3,2));
    int ano = stoi(valor.substr(6,4));

    //Separando separadores
    string sep1 = valor.substr(2,1);
    string sep2 = valor.substr(5,1);

    //Definindo os dias do mes
    /*if (mes == "02" && isBissexto(valor))
        diasMes = 29;
    else if (mes == "02")
        diasMes = 28;
    else if (mes == "04" || mes == "06" || mes == "09" || mes == "11")
        diasMes = 30;
    else
        diasMes = 31;*/

    if((dia < 00 || dia > diasMes) //Verificando os dias
       ||(mes < 01 || mes >12) //Verificando os meses
       ||(ano < 2000 || ano > 2100) //Verificando os anos
       /*||(sep1 != '-' || sep2 != '-')*/){ //Verificando os hifens
        throw invalid_argument("Data invalida.");
    };
}

//Dinheiro INCOMPLETO!!
void Dinheiro::validar(string valor){
    //Regex para validar o formato da quantia
    std::regex regex("^([0-9]{1,3}(\\.[0-9]{3})*|[0-9]+),[0-9]{2}$");

    //Verifica se o formato ta certo
    if (!std::regex_match(valor, regex)) {
        throw invalid_argument("Dinheiro invalido.");
    }

    //Tira os pontos e troca virgula por ponto pra usar o double
    std::string quantiaSemPontos = valor;
    quantiaSemPontos.erase(remove(quantiaSemPontos.begin(), quantiaSemPontos.end(), '.'), quantiaSemPontos.end());
    std::replace(quantiaSemPontos.begin(), quantiaSemPontos.end(), ',', '.');

    // Converte a string para float
    double quantia = std::stof(quantiaSemPontos);

    if(quantia < 0.0 || quantia > 1000000.0){
        throw invalid_argument("Dinheiro invalido.");
    }
}

//Verifica se o Estado eh um dos 3 estados validos.
void Estado::validar(string valor){
    string estados[3] = {"Previsto","Liquidado",
    "Inadimplente"};

    bool valida = false;

    //Itera sobre a lista e compara com o valor de entrada
    for (const string &estado : estados){
        if (estado == valor){
            valida = true;
            break;
        }
    }
    if(!valida)
        throw invalid_argument("Estado invalido.");
}

//Verifica se o Nome atende os requisitos
void Nome::validar(string valor){
    size_t tamanhoNome = valor.length();
    int quantosNomes = 1;
    int posEspaco = 0;

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
    size_t tamNome1, tamNome2;
    if(quantosNomes == 2){
        string nome1 = valor.substr(0, posEspaco);
        string nome2 = valor.substr(posEspaco + 1);

        tamNome1 = nome1.length();
        tamNome2 = nome2.length();
    }

    //Verifica se os termos tem a quantidade correta de caracteres
    if((quantosNomes == 1 && (tamanhoNome > 10 || tamanhoNome < 3))
        || tamNome1 > 10 || tamNome1 < 3 || tamNome2 > 10 || tamNome2 < 3)
        throw invalid_argument("Numero maximo de caracteres por nome excedido.");

}

//Verifica se o Percentual ta entre 0 e 100
void Percentual::validar(int valor){
    if(valor > MAX || valor < MIN)
        throw invalid_argument("Percentual invalido.");
}

//Validando a senha
void Senha::validar(string valor){
    //Verifica se o primeiro digito eh zero
    if(valor[0] == '0')
        throw invalid_argument("Senha invalida: primeiro digito tem que ser diferente de zero");

    size_t tamanhoSenha = valor.length();
    //Verifica tamanho da senha
    if(tamanhoSenha != 6)
        throw invalid_argument("Senha invalida: senha deve ter 6 digitos");

    for(size_t i=0; i<tamanhoSenha; i++){
    //Verifica se a senha eh numerica
        if(isdigit(valor[i] == 0))
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
void Setor::validar(string valor){
    string setores[10] = {"Agricultura","Construcao Civil",
    "Energia","Financas","Imobiliario","Papel e celulose",
    "Pecuaria","Quimica e petroquimica","Metalurgia e siderurgia",
    "Mineracao"};
    bool valida = false;

    //Itera sobre a lista e compara com o valor de entrada
    for (const string &setor : setores){
        if (setor == valor){
            valida = true;
            break;
        }
    }
    if(!valida)
        throw invalid_argument("Setor invalido.");
}
