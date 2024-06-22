#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <string>
#include <stdexcept>
#include <regex>

using namespace std;

class Dominios {
    private:
        string valor;
    protected:
        virtual void validar(string);
    public:
        virtual ~Dominios(){}
        void setValor(string);
        string getValor() const;
};

inline string Dominios::getValor() const{
    return valor;
}

class CodPagamento : public Dominios {
    private:
        void validar(string) override;
};

class CodTitulo : public Dominios {
    private:
        void validar(string) override;
};

class CPF : public Dominios {
    private:
        void validar(string) override;
};

class Data : public Dominios {
    private:
        void validar(string) override;
};

class Dinheiro : public Dominios {
    private:
        void validar(string) override;
};

class Estado : public Dominios {
    private:
        void validar(string) override;
};

class Nome : public Dominios {
    private:
        void validar(string) override;
};

class Percentual : public Dominios {
    private:
        void validar(string) override;
};

class Senha : public Dominios {
    private:
        void validar(string) override;
};

class Setor : public Dominios {
    private:
        void validar(string) override;
};


#endif // DOMINIOS_H_INCLUDED
