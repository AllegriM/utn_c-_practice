// 8. Hacer un programa para ingresar una lista de números que finaliza cuando
// se ingresa un cero, informar si todos están ordenados en forma creciente. En
// caso de haber un número igual al anterior considerarlo como creciente. Por
// ejemplo si la lista fuera:
// Ejemplo 1: -10, 1, 5, 7, 15, 18, 20, 23, 0 se emitirá un cartel: “Conjunto
// Ordenado” Ejemplo 2: 10, 10, 15, 20, 25, 25, 28, 33, 0 se emitirá un cartel:
// “Conjunto Ordenado” Ejemplo 3: 10, 1, 15, 7, -15, 18, 20, 23, 0 se emitirá un
// cartel: “Conjunto No Ordenado”

#include <iostream>
using namespace std;

int main() {
  int n, last;
  bool ordenado = true;

  cout << "Ingrese un numero: " << endl;
  cin >> n;

  last = n;

  while (n != 0) {
    cout << "Ingrese un numero: " << endl;
    cin >> n;
    if (n > last && n != 0) {
      last = n;
    } else if (n < last && n != 0) {
      ordenado = false;
    }
  }
  if (ordenado) {
    cout << "El conjunto esta ordenado!" << endl;
  } else {
    cout << "El conjunto esta desordenado!" << endl;
  }
}