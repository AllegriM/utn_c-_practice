// 10) Hacer un programa para ingresar una lista de 10 números, luego informar el máximo y
// el mínimo.
// Ejemplo: 10, 20, -5, 30,-15, 5, 42, 0, 22, -13. Se listará Máximo 42 Mínimo -15.
// Ejemplo: 10, 20, 5, 30, 15, 5, 42, 8, 22, 13. Se listará Máximo 42 Mínimo 5.
// Ejemplo: -10, -20, -5, -30, -15, -12, -42, -8, -22, -13. Se listará Máximo -5 Mínimo -42.
// Observe que los tres ejemplos dejan en claro que la idea de que el máximo
// “seguramente” es un positivo y el mínimo “seguramente” es un negativo, queda
// totalmente descartada.

// Path: ciclos\ej10.cpp    
#include <iostream>
using namespace std;

int main(){

    int num, max, min;

    cout << "Ingrese 10 numeros: " << endl;
    cin >> num;
    max = num;
    min = num;

    for (int i = 1; i < 10; i++){
        cin >> num;
        if(num > max){
            max = num;
        }
        if(num < min){
            min = num;
        }
    }

    cout << "Maximo: " << max << endl;
    cout << "Minimo: " << min << endl;

}