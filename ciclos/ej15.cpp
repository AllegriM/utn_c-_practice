// 15. Hacer un programa para ingresar un número positivo y calcular e informar si el mismo es un número primero. 
// Recordar que un número primo es un número natural que tiene exactamente dos divisores.

#include <iostream>
using namespace std;

int main(){
    int numero, i; 
    bool esPrimo = true, noEsPrimo = false;

    cout << "Ingrese un numero: " << endl;
    cin >> numero;

    for(i = 1; i <= numero; i++){
        if(i != 1 && i != numero && numero % i == 0){
            esPrimo = false;
            noEsPrimo = true;
        }
        if(numero % numero == 0 && numero % 1 == 0 && !noEsPrimo){
            esPrimo = true;
        }
    }

    if(esPrimo){
        cout << "Es Primo.";
    }else{
        cout << "No es Primo.";
    }
}