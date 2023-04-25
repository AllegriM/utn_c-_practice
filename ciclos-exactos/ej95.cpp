// 13) Dada una lista de 7 números informar cual es el primer y segundo número impar
// ingresado.
// Ejemplo 8, 4, -5, 6, 9, 5, 18 se informa -5 y 9.

#include <iostream>
using namespace std;

int main(){
    int numero, primerNumeroImpar, segundoNumeroImpar;
    bool esPrimerNumeroImpar = true, esSegundoNumeroImpar = true;

    for (int i = 0; i < 7; i++){
        cout << "Ingrese un numero: " << endl;
        cin >> numero;
        if(numero % 2 != 0){
            if(esPrimerNumeroImpar){
                primerNumeroImpar = numero;
                esPrimerNumeroImpar = false;
            } else if(esSegundoNumeroImpar){
                segundoNumeroImpar = numero;
                esSegundoNumeroImpar = false;
            }
        }
    }

    cout << "Primer numero impar: " << primerNumeroImpar << endl;
    cout << "Segundo numero impar: " << segundoNumeroImpar << endl;
}