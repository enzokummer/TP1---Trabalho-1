#include <iostream>
#include "dominios.h"

using namespace std;

int main()
{
    string cpfDoAndre;
    cin >> cpfDoAndre;
    try{
        CPF cpfAndre;
        cpfAndre.setValor("123456789");
    }
    catch (const invalid_argument& e) { // Captura exce��o de formato inv�lido
        std::cout << "Erro: " << e.what() << std::endl;
  }
    catch (const std::exception& e) { // Captura outras exce��es
        std::cout << "Exce��o n�o espec�fica: " << e.what() << std::endl;
  }
}
