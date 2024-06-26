#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"
#include "dominios.cpp"

class Entidade{
    public: //Todos métodos abstratos puros. Cabe a cada classe filha implementar. O método "criar" vai ser o construtor de cada classe.
        virtual void ler() = 0;
        virtual void atualizar(string opcaoAtributo, string novoValor) = 0; // Lançando exceção caso dê errado.
        virtual void excluir() = 0; //Lançando exceção caso dê errado.
        virtual void listar() = 0;
};


class Conta : private Entidade{
    private:
        CPF cpf;
        Nome nome;
        Senha senha;

        Conta(string cpf, string nome, string senha);
        void ler();
        void atualizar(string opcaoAtributo, string novoValor);
        void excluir();
};

class Titulo : private Entidade{
    private:
        CodTitulo codigo;
        Nome emissor;
        Setor setor;
        Data emissao;
        Data vencimento;
        Dinheiro valor;

        Titulo(string codigo, string emissor, string setor, string emissao, string vencimento, string valor);
        void ler();
        void atualizar(string opcaoAtributo, string novoValor);
        void excluir();
        void listar();
};

class Pagamento : private Entidade{
    private:
        CodPagamento codigo;
        Data data;
        Percentual percentual;
        Estado estado;

        Pagamento(string codigo, string data, int percentual, string estado);
        void ler();
        void atualizar(string opcaoAtributo, string novoValor);
        void excluir();
        void listar();
};

#endif // evitar redefinição entidades.h
