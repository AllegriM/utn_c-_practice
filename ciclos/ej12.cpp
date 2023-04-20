// 12. Hacer un programa para ingresar 5 números, luego informar los 2 mayores valores ingresados, aclarando cual es el máximo y cual el que le sigue.
// Ejemplo: 10, 8, 12, 14, 3 el resultado será 14 y 12.
// Ejemplo: 14, 8, 12, 14 ,3 el resultado será 14 y 14.
// Ejemplo: -4, -8, -12, -20, -2 el resultado será -2 y -4

#include <iostream>
using namespace std;

int main(){
    int numero, primMaxNum, segMaxNum, i;

    cout << "Ingrese el numero 0: " << endl;
    cin >> numero;

    primMaxNum = numero;
    segMaxNum = numero;

    for( i = 1; i < 5; i++){
        cout << "Ingrese el numero " << i << ":" << endl;
        cin >> numero;

        if(numero > primMaxNum){
            segMaxNum = primMaxNum;
            primMaxNum = numero;
        }
    }
    cout << "Primer Max Num: " << primMaxNum << endl;
    cout << "Segundo Max Num: " << segMaxNum << endl;    
}


