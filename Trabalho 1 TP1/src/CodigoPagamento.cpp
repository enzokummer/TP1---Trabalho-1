#include "Codigo.h"

Codigo::Codigo()
{
    //ctor
}

Codigo::~Codigo()
{
    //dtor
}



// CodigoPagamento.cpp (arquivo de implementa��o)
#include "CodigoPagamento.h"
#include <stdexcept>
#include <regex>

CodigoPagamento::CodigoPagamento(const std::string& codigo) {
    setCodigo(codigo);
}

std::string CodigoPagamento::getCodigo() const {
    return codigo;
}

void CodigoPagamento::setCodigo(const std::string& codigo) {
    if (validarCodigo(codigo)) {
        this->codigo = codigo;
    } else {
        throw std::invalid_argument("C�digo de pagamento inv�lido!");
    }
}

bool CodigoPagamento::validarCodigo(const std::string& codigo) const {
    // Express�o regular para validar o formato do c�digo de pagamento
    const std::regex pattern("^[1-9][0-9]{7}$");
    return std::regex_match(codigo, pattern);
}
