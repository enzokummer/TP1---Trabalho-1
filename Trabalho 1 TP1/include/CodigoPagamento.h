// CodigoPagamento.h (arquivo de cabeçalho)
#ifndef CODIGOPAGAMENTO_H
#define CODIGOPAGAMENTO_H

#include <string>

class CodigoPagamento {
public:
    CodigoPagamento(const std::string& codigo);
    std::string getCodigo() const;
    void setCodigo(const std::string& codigo);

private:
    std::string codigo;
    bool validarCodigo(const std::string& codigo) const;
};

#endif //CODIGOPAGAMENTO_H
