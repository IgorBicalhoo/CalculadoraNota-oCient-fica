#include <iostream>
#include <iomanip>
#include <map>
#include <functional>


double realizarOperacao(double num1, double num2, char operacao) {
  static const std::map<char, std::function<double(double, double)>> operacoes = {
    {'+', [](double a, double b) { return a + b; }},
    {'-', [](double a, double b) { return a - b; }},
    {'*', [](double a, double b) { return a * b; }},
    {'/', [](double a, double b) { return b != 0 ? a / b : 0; }}
  };

  auto it = operacoes.find(operacao);
  if (it != operacoes.end()) {
    return it->second(num1, num2);
  } else {
    std::cout << "Erro: Operação inválida!" << std::endl;
    return 0;
  }
}

int main() {
  double num1, num2;
  char operacao;

  std::cout << "------------CALCULADORA COM NUMEROS ESCRITOS EM NOTACAO CIENTIFICA------------" << std::endl <<" por exemplo: 1.23e3 ou 4.56e-2 (Use o ponto inves da virgula)):" << std::endl ;


  std::cout << "Insira o primeiro valor: ";
  if (!(std::cin >> num1)) {
    std::cout << "Erro: Entrada inválida!" << std::endl;
    return 1;
  }

  std::cout << "Insira o segundo valor: ";
  if (!(std::cin >> num2)) {
    std::cout << "Erro: Entrada inválida!" << std::endl;
    return 1;
  }

  std::cout << "Escolha a operação: " << std::endl;
  std::cout << "  +: Adição" << std::endl;
  std::cout << "  -: Subtração" << std::endl;
  std::cout << "  *: Multiplicação" << std::endl;
  std::cout << "  /: Divisão" << std::endl;
  std::cin >> operacao;


  double resultado = realizarOperacao(num1, num2, operacao);
  std::cout << "Resultado: " << std::scientific << std::setprecision(10) << resultado << std::endl;

  return 0;
}
