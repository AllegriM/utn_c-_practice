
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

// bool verificarEscalera(int dados[5]) {
//   bool estanPresentes[6] = {false};
//   // [2, 5, 3, 6, 4]
//   for (int i = 0; i < 5; i++) {
//     int valor = dados[i];

//     if (estanPresentes[valor - 1]) {
//       return false;
//     }

//     estanPresentes[valor - 1] = true;
//   }

//   int contador = 0;
//   for (int i = 0; i < 6; i++) {
//     if (estanPresentes[i]) {
//       contador++;
//       cout << contador;
//       if (contador == 5) {
//         return true;  // Hay 5 valores consecutivos, es una escalera
//       }
//     } else {
//       contador = 0;
//     }
//   }
// }

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