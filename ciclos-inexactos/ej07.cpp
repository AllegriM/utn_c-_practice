// 7 Dada una lista de números que finaliza cuando se ingresa un número
// divisible
//     por 7,
//     informar cual es el anteúltimo y último número impar ingresado.Ejemplo 8,
//     4, -5, 6, 10, 5, 18, 14 se informa - 5 y 5.

//                     Nota
//     : Contemplar la posibilidad que podría no haber números impares en la
//     lista.

#include <iostream>
using namespace std;

int main() {
  int n, anteultimo, ultimo, cantImpar = 0;

  while (n % 7 != 0) {
    cout << "Ingrese un numero: " << endl;
    cin >> n;

    if (n % 2 != 0) {
      cantImpar++;
      if (cantImpar > 1) {
        anteultimo = ultimo;
        cout << anteultimo;
      }
      ultimo = n;
      cout << ultimo;
    }
  }

  if (!cantImpar) {
    cout << "No hubo numero impares" << endl;
  } else {
    cout << "El anteultimo numero es: " << anteultimo << endl;
    cout << "El ultimo numero es: " << ultimo << endl;
  }
}