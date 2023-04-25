// 6 Hacer un programa que permita ingresar una lista de números positivos,
//     negativos o cero hasta que se ingrese el 5º número par
//         .Calcular e informar : La cantidad de ternas de números negativos
//                                    ingresados de manera consecutiva.

//                                Ejemplo A : 4,
//     -1, -4, -5, 10, -3, -5, 7, -5, -3, -6, 10 → Cantidad de ternas : 2

#include <iostream>
using namespace std;

int main() {
  int n, contadorPar = 0, contadorImpar = 0, cantTerna = 0;

  while (contadorPar != 5) {
    cout << "Ingrese un numero positivos, negativos o cero: " << endl;
    cin >> n;
    if (n % 2 == 0) {
      contadorPar++;
      if (n > 0) {
        cout << "Entre en pares > a 0" << endl;
        contadorImpar = 0;
      } else {
        cout << "Entre en pares < a 0" << endl;
        ++contadorImpar;
      }
    } else if (n % 2 != 0) {
      cout << "Entre en < a 0" << endl;
      if (n < 0) {
        ++contadorImpar;
      } else {
        contadorImpar = 0;
      }
    }

    if (contadorImpar == 3) {
      cout << "Entre en terna + 1" << endl;
      cout << cantTerna++;
    }
  }
  cout << "Cantidad de ternas: " << cantTerna;
}
