// 16. Hacer un programa para ingresar por teclado cuatro números. Si los valores que se ingresaran están ordenados en forma creciente, emitir el mensaje “Conjunto Ordenado”, caso contrario emitir el mensaje: “Conjunto Desordenado”. 
// Ejemplo 1: si los números que se ingresan son 8, 10, 12 y 14, entonces están ordenados. 
// Ejemplo 2: si los números que se ingresan son 8, 12, 12 y 14, entonces están ordenados. 
// Ejemplo 3: si los números que se ingresan son 10, 8, 12 y 14, entonces están desordenados.

#include <iostream>
using namespace std;

int main(){

    int numero[4];

    for (int i = 0; i < 4; i++){
        cout << "Ingrese el numero " << i << ":" << endl;
        cin >> numero[i];
    }
    // 0: 4
    // 1: 3
    // 2: 2
    // 3: 1
    if(numero[0] <= numero[1] && numero[1] <= numero[2] && numero[2] <= numero[3]){
        cout << "Conjunto Ordenado";
    }else{
        cout << "Conjunto Desordenado";
    }

}