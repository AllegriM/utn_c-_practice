// 11. Hacer un programa para ingresar una lista de 8 números 
// y luego informar si todos están ordenados en forma creciente. 
// En caso de haber dos números “empatados” considerarlos como crecientes.
// Por ejemplo si la lista fuera:
// Ejemplo 1: -10, 1, 5, 7, 15, 18, 20, 23 se emitirá un cartel: “Conjunto Ordenado”
// Ejemplo 2: 10, 10, 15, 20, 25, 25, 28, 33 se emitirá un cartel: “Conjunto Ordenado”
// Ejemplo 3: 10, 1, 15, 7, -15, 18, 20, 23 se emitirá un cartel: “Conjunto No Ordenado”

#include <iostream>
using namespace std;

int main() {
    int i, numero, numeroAnterior; 
    bool conjuntoOrdenado = true;
    
    cout << "Ingrese el numero 1: " << endl;
    cin >> numero;

    numeroAnterior = numero;

    for (i = 1; i < 8; i++){
        cout << "Ingrese el numero " << i + 1 << ":" << endl;
        cin >> numero;

        if(numeroAnterior < numero || numeroAnterior == numero){
            numeroAnterior = numero;
            conjuntoOrdenado = true;
        }else{
            conjuntoOrdenado = false;
        }
    }

    if(conjuntoOrdenado){
        cout << "Conjunto Ordenado";
    }else{
        cout << "Conjunto No Ordenado";
    }
}

