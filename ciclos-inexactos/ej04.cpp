// 4. Hacer un programa para ingresar una lista de números que finaliza cuando
// se ingresa un cero, luego informar el máximo de los números pares. Ejemplo:
// 2, 10, 20, 8, 25, 13, 36, -8, -5, 20, 0. Se listará Máximo 36. Ejemplo: 5,
// -13, 23, 81, -55, -13, 55, 4, 15, -20, 0. Se listará Máximo 4. Ejemplo: -5,
// -13, -20, -8, -55, -13, -55, -14, -15, -20, 0. Se listará Máximo 0

#include <iostream>
using namespace std;

int main() {
  int n, maxPar;
  bool primPar = true;

  cout << "Ingrese un numero: " << endl;
  cin >> n;

  while (n != 0) {
    cout << "Ingrese un numero: " << endl;
    cin >> n;

    if (n % 2 == 0 && primPar) {
      maxPar = n;
      primPar = false;
    } else if (n % 2 == 0 && !primPar) {
      if (n > maxPar) {
        maxPar = n;
      }
    }
  }

  cout << "El numero mas alto es: " << maxPar;
}
