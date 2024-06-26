#include "entidades.h"

Conta::Conta(string cpf, string nome, string senha){
    this->cpf = CPF(cpf);
    this->nome = Nome(nome);
    this->senha = Senha(senha);

}

void Conta:ler(){

    cout << "CPF: " + this->cpf.getValor() + "\nNome: " + this->nome.getValor() + "\nSenha: " + this->senha.getValor() << endl;
}

void Conta:atualizar(){

}

void Conta:excluir(){

}
