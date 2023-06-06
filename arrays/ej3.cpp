// Hacer un programa donde se carguen 15 números enteros
// y luego le solicite al usuario un número e indique
// si el mismo pertenece a la lista cargada anteriormente.

#include <iostream>
using namespace std;

int main() {
  int nums[15], numEspecial;

  // Pido los 15 numeros
  for (int i = 1; i <= 15; i++) {
    cout << "Ingrese el numero: " << i << endl;
    cin >> nums[i];
  }

  cout << "Ingrese el numero especial: " << endl;
  cin >> numEspecial;
  // Recorro el array y valido si esta
  for (int i = 1; i <= 15; i++) {
    if (nums[i] == numEspecial) {
      cout << nums[i] << " === " << numEspecial;
      cout << "El numero pertenece al array." << endl;
    } else {
      cout << "El numero NO pertenece al array." << endl;
    }
  }
}