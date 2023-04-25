// 17) Hacer un programa para ingresar un número y luego informar todos los divisores pares
// de ese número.
// Ejemplo 1. Si se ingresa 6 se listarán: 2 y 6
// Ejemplo 2. Si se ingresa 8 se listarán: 2 y 4.
// Ejemplo 3. Si se ingresa 11 no se listará nada

#include <iostream>
using namespace std;

int main(){
    int numero; 

    cout << "Ingrese un numero: " << endl;
    cin >> numero;

    for(int i = 1; i <= numero; i++){
        if(i % 2 == 0 && numero % i == 0){
            cout << i << endl;
        }
    }
}