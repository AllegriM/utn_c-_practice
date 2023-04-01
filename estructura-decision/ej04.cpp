// 4. Hacer un programa para ingresar por teclado dos números y luego informar por pantalla la diferencia absoluta entre ambos. 
// Ejemplo 1: Si se ingresan 3 y 8, se emite 5. Si se ingresan 8 y 3, se emite 5. 
// Ejemplo 2: Si se ingresan -3 y 9, se emite 12. Si se ingresan -12 y -1, se emite 11.

#include <iostream>
using namespace std;

int main() {
    int num1, num2, diferencia;

    cout << "Ingresar el numero 1: " << endl;
    cin >> num1;

    cout << "Ingresar el numero 2: " << endl;
    cin >> num2;

    if (num1 > num2){
        diferencia = num1 - num2;
    }else{
        diferencia = num2 - num1;
    }

    cout << "La diferencia entre ambos numeros es de " << diferencia;

}