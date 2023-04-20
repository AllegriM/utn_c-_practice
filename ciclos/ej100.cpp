// 13) Dada una lista de 7 números informar cual es el primer y último número impar
// ingresado.
// Ejemplo 8, 4, -5, 6, 9, 5, 18 se informa -5 y 5.

#include <iostream>
using namespace std;

int main(){
    int numero, primerNumeroImpar, ultimoNumeroImpar;
    bool esPrimerNumeroImpar = true;

    for (int i = 0; i < 7; i++){
        cout << "Ingrese un numero: " << endl;
        cin >> numero;
        if(numero % 2 != 0){
            if(esPrimerNumeroImpar){
                primerNumeroImpar = numero;
                esPrimerNumeroImpar = false;
            }
            ultimoNumeroImpar = numero;
        }
    }

    cout << "Primer numero impar: " << primerNumeroImpar << endl;
    cout << "Ultimo numero impar: " << ultimoNumeroImpar << endl;
}