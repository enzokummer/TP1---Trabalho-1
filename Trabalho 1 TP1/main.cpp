#include <iostream>
#include "dominios.h"
#include "dominios.cpp"
#include "entidades.h"
#include "entidades.cpp"

using namespace std;

int main(){
CodPagamento cod;
string qualquer;

cin >> qualquer;
cod.setValor(qualquer);

// Testando funcionamento da Entidade Conta.
Conta contaDoCleitin("182.705.860-99", "Cleitin", "123456");
contadoCleitin.ler();
}
