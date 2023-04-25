// 3. Hacer un programa para ingresar una lista de números que finaliza cuando
// se ingresa un cero, luego informar el máximo y la posición dentro de la
// lista.
// Ejemplo: 5, 10, 20, 8, 25, 13, 35, -8, -5, 20, 0. Se listará Máximo: 35 -
// Posición: 7. Ejemplo: 5, 10, 20, 8, 55, 13, 55, -8, -5, 20, 0. Se listará
// Máximo: 55 - Posición: 5. Ejemplo: -5, -10, -20, -8, -55, -400, -15, -20, 0.
// Se listará Máximo: -5 - Posición: 1.

#include <iostream>
using namespace std;

int main() {
  int n, pos = 0, max, posTotal = 0;

  cout << "Ingrese un numero: " << endl;
  cin >> n;

  max = n;
  pos = 1;
  posTotal = 1;

  while (n != 0) {
    cout << "Ingrese un numero: " << endl;
    cin >> n;

    ++posTotal;

    if (n > max) {
      max = n;
      pos = posTotal;
    }
  }

  cout << "El maximo numero es: " << max << " y su posicion: " << pos;
}
