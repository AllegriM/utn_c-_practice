// 5 Hacer un programa que permita ingresar una lista de números positivos,
//     negativos o cero hasta que la diferencia entre el máximo y el mínimo sea
//         mayor a 10. Calcular e informar
//     : La cantidad de números que componen la lista.

//       Ejemplo A : 1,
//     4, 6, -10 → Cantidad de números : 4 Ejemplo B : 100, 104, 106, 100, 100,
//     105, 200 → Cantidad de números : 7

#include <iostream>
using namespace std;

int main() {
  int num, numMax = 0, numMin = 0, cantNum = 1;

  cout << "Ingrese un numero: " << endl;
  cin >> num;

  numMax = num;
  numMin = num;

  while ((numMax - numMin) < 10) {
    cout << "Ingrese un numero: " << endl;
    cin >> num;

    ++cantNum;

    if (num > numMax) {
      numMax = num;
    } else {
      numMin = num;
    }
  }

  cout << "La cantidad de números es: " << cantNum;
}