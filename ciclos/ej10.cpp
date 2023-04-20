// 10. Dada una lista de 7 números informar cual es el primer y segundo número impar ingresado.
// Ejemplo: 8, 4, 5, 6, -9, 5,7 se informa 5 y -9.

#include <iostream>
using namespace std;


int main() {
    int numero, i, primNumImpar, segNumImpar; 
    bool primerImpar = true, segundoImpar = true;

    for (i = 0; i < 7; i++){

        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> numero;

        if(numero % 2 != 0 && !primerImpar && segundoImpar){
            cout << "Estoy en el segundo IF, Este numero es: " << numero << endl;
            segNumImpar = numero;
            segundoImpar = false;
        }

        if(numero % 2 != 0 && primerImpar){
            cout << "Estoy en el primer IF, Este numero es: " << numero << endl;
            primNumImpar = numero;
            primerImpar = false;
        }
    }
    cout << "El primer numero impar es: " << primNumImpar << endl;
    cout << "El segundo numero impar es: " << segNumImpar << endl;
}


