// Hacer un programa que le pida al usuario una lista de 10 números enteros y
// luego de ingresarlos muestre cuáles de ellos fueron positivos.

#include <iostream>
using namespace std;

int main() {
  int nums[10] = {};
  for (int i = 1; i <= 10; i++) {
    cout << "Ingrese el numero " << i << endl;
    cin >> nums[i];
    if (nums[i] > 0) {
      cout << nums[i] << " es positivo." << endl;
    }
  }
}