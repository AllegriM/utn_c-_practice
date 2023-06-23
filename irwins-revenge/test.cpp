
#include <iostream>
using namespace std;

bool validarEscaleraDeCuatro(int dados[5]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4 - i; j++) {
      if (dados[j] > dados[j + 1]) {
        int temp = dados[j];
        dados[j] = dados[j + 1];
        dados[j + 1] = temp;
      }
    }
  }

  // Verificar si hay una escalera de 4 números
  int contador = 1;
  for (int i = 1; i < 5; i++) {
    if (dados[i] == dados[i - 1] + 1)
      contador++;
    else if (dados[i] != dados[i - 1])
      contador = 1;

    if (contador == 4)
      return true;
  }

  return false;
}

int main() {
  int dados[5] = {3, 1, 4, 5, 2};
  bool esEscalera = validarEscaleraDeCuatro(dados);

  cout << endl;
  if (esEscalera) {
    cout << "Es una escalera." << endl;
  } else {
    cout << "No es una escalera." << endl;
  }
  cout << endl;
  return 0;
}