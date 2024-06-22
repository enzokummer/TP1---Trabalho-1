#include "Codigo.h"

Codigo::Codigo()
{
    //ctor
}

Codigo::~Codigo()
{
    //dtor
}



// CodigoPagamento.cpp (arquivo de implementação)
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
        throw std::invalid_argument("Código de pagamento inválido!");
    }
}

bool CodigoPagamento::validarCodigo(const std::string& codigo) const {
    // Expressão regular para validar o formato do código de pagamento
    const std::regex pattern("^[1-9][0-9]{7}$");
    return std::regex_match(codigo, pattern);
}
