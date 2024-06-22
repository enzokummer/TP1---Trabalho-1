#include "dominios.h"

void CodPagamento::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

void CodPagamento::validar(string valor){
    primeiro_digito = valor[0];
    if (primeiro_digito == '0')
        throw invalid_argument("Argumento invalido.");
}
