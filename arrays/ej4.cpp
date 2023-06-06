// 3 Hacer un programa donde se carguen 15 números enteros y luego muestre por
// pantalla el mínimo elemento del vector y además indique cuántas veces se
// repite el valor mínimo dentro del vector.

#include <iostream>
using namespace std;

int main() {
  const int MAX_NUMS = 15;
  int nums[MAX_NUMS] = {}, minNum;

  for (int i = 1; i <= MAX_NUMS; i++) {
    cout << "Ingrese el num " << i << endl;
    cin >> nums[i];

    if (i == 1) {
      minNum = nums[i];
    }

    if (nums[i] < minNum) {
      minNum = nums[i];
    }
  }

  cout << "El minimo numero del array es: " << minNum << endl;
}