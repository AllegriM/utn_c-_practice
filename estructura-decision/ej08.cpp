// 8. Basado en los 2 ejercicios anteriores, hacer un programa para ingresar por teclado la longitud de los tres lados de un triángulo y luego listar que tipo de triángulo es: 
// - Equilátero: si los tres lados son iguales.
// - Isósceles: si dos de los tres lados son iguales.
// - Escaleno: si los tres lados son distintos entre sí.

#include <iostream>
using namespace std;

int main(){
    int ladoA, ladoB, ladoC;

    cout << "Ingrese el lado A: " << endl;
    cin >> ladoA;

    cout << "Ingrese el lado B: " << endl;
    cin >> ladoB;

    cout << "Ingrese el lado C: " << endl;
    cin >> ladoC;

    if (ladoA == ladoB && ladoB == ladoC){
        cout << "Este es un triangulo Equilatero.";
    }else{
        if(ladoA == ladoB || ladoB == ladoC || ladoC == ladoA){
            cout << "Es un triangulo Isoceles.";
        }else{
            cout << "Es un triangulo Escaleno";
        }
    }
}



