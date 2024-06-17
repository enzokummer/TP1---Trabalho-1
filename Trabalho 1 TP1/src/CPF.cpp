#include "CPF.h"
CPF::setCpf(string numCpf)
{
    this->numCpf = numCpf;
}
CPF::CPF(numCpf)
{
    setCpf(numCpf);
}

CPF::validarCPF(){
        // Remover caracteres não numéricos
        string cpfNumerico = "";
        for (char c : numCpf) {
            if (isdigit(c)) {
                cpfNumerico += c;
            }
        }

        // Verificar se o CPF tem 11 dígitos
        if (cpfNumerico.length() != 11) {
            return false;
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
            return false;
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
        return (cpfNumerico[9] - '0' == digitoVerificador1) && (cpfNumerico[10] - '0' == digitoVerificador2);
}
