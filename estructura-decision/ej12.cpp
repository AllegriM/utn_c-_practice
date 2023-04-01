// 12. Hacer un programa para leer tres números diferentes y determinar e informar el número del medio. Ejemplo: si se ingresan 6, 10, 8, se emitirá 8.

#include <iostream>
using namespace std;

int main(){
    int num1, num2, num3;

    cout << "Ingrese el numero 1: " << endl;
    cin >> num1;

    cout << "Ingrese el numero 2: " << endl;
    cin >> num2;

    cout << "Ingrese el numero 3: " << endl;
    cin >> num3;

    // Numero 1: 1
    // Numero 2: 2
    // Numero 3: 3

    if ((num1 < num2 && num2 < num3) || (num3 < num2 && num2 < num1)) {
        cout << "El número del medio es: " << num2;
    }
    else if ((num2 < num1 && num1 < num3) || (num3 < num1 && num1 < num2)) {
        cout << "El número del medio es: " << num1;
    }
    else {
        cout << "El número del medio es: " << num3;
    }

    return 0;
}


