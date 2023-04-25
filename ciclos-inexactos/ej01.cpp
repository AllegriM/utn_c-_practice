// 1 Hacer un programa para ingresar una lista de números que finaliza cuando se ingresa un cero,
// luego informar cuántos son positivos y cuántos son negativos.
// Ejemplo: 4, -3, 8, -5, 18, 20, 0. Se listará Positivos: 4 Negativos: 2.

#include <iostream>
using namespace std;

int main(){
    int num, positivos = 0, negativos = 0;

    while (num != 0){
        cout << "Ingrese un numero: " << endl;
        cin >> num;

        if (num % 2 == 0){
            positivos++;
        }
        else{
            negativos--;
        }
    }

    cout << "Cerro el ciclo porque se ingreso 0" << endl;
    cout << "Positivos: " << positivos << endl;
    cout << "Negativos: " << negativos;
}