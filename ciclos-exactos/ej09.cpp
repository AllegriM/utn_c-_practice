// 9 Hacer un programa para ingresar una lista 10 números e 
// informar el máximo de los negativos y el mínimo de los positivos. 
// Ejemplo: 5, 8, 12, 2, -10, 15, -20, 8, -3, 24. 
// Máximo Negativo: -3. 
// Mínimo Positivo: 2.

#include <iostream>
using namespace std;

int main() {
    int numero, maxNeg, minPos, primerPos = true, primerNeg = true;
    int i = 0; 

    for (i = 0; i < 10; i++){
        cout << "Ingrese el numero " << i + 1 << ":" << endl;
        cin >> numero;

        if(numero > 0 && primerPos){
            minPos = numero;
            primerPos = false;
        }

        if(numero < 0 && primerNeg){
            maxNeg = numero;
            primerNeg = false;
        }
        
        if(numero < 0 && numero > maxNeg){
            maxNeg = numero;
        }

        if(numero > 0 && numero < minPos){
            minPos = numero;
        }

    }

    cout << "El maximo de los negativos (-) es: " << maxNeg << endl;
    cout << "El minimo de los positivos (+) es: " << minPos << endl;

}

