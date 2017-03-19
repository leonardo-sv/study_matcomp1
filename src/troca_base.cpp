/*
Leonardo de Souza Vieira.
18/03/2017
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//String contendo os digitos de cada base.
std::string alfabeto= "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
// Conversão de um número na base N para a base 10.
long int baseN_base10(std::string num_baseN, int N);
// Conversão de um número na base 10 para a base M.
std::string base10_baseM(int num_base10, int baseN);

int main(int argc, char const *argv[]) {

  int num_base10 = 0;
  std::string num_baseN;

  //Verifica se o números de argumentos é 4. Se não for retorna modo de execução
  if(argc != 4) {
    std::cout << " [uso] ./troca_base <num> <baseN> <baseM>" << std::endl;
    return -1 ;
  }

  //Converte entrada padrão em um vetor de string C++
  std::vector<std::string> args(argv + 1,argv + argc);

  num_base10 = baseN_base10(args[0], std::stoi(args[1]));
  num_baseN = base10_baseM(num_base10, std::stoi(args[2]));

  std::cout << num_baseN << std::endl;


  return 0;
}


long int baseN_base10(std::string num_baseN, int baseN){

    long int num_base10 = 0;
    int index = num_baseN.size() -1;
    int exp = 1;

    //Loop para o somatório (d1*base^expn + d2*base^expn-1 + d3*base^expn-2 ... dn*base^0)
    while(index >= 0){

      num_base10 += alfabeto.find(num_baseN[index]) * exp;
      index--;
      exp = exp * baseN;
    }

    return num_base10;

}

std::string base10_baseM(int num_base10, int baseM){

  std::string saida;
  //se o valor na base 10 for 0 retorna 0;
  if(num_base10 == 0){
    saida = "0";
    return saida;
  }
  //Realiza sucessivas divisões. Guardando o resto de cada divisão em uma string
  while(num_base10){
    saida += alfabeto[num_base10%baseM];
    num_base10 /= baseM;
  }
  //Inverte a a string de saída
  std::reverse(saida.begin(), saida.end());

  return saida;

}

/*
Referência: https://daemoniolabs.wordpress.com/2012/07/19/conversao-de-base-numerica/
*/
