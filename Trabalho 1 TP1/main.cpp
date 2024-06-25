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
    catch (const invalid_argument& e) { // Captura exceção de formato inválido
        std::cout << "Erro: " << e.what() << std::endl;
  }
    catch (const std::exception& e) { // Captura outras exceções
        std::cout << "Exceção não específica: " << e.what() << std::endl;
  }
}
