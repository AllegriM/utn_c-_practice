// 2. Hacer un programa que solicite por teclado que se ingresen dos números y luego guardarlos en dos variables distintas. 
// A continuación se deben intercambiar mutuamente los valores en ambas variables y mostrarlos por pantalla.
// Ejemplo: Suponiendo que se ingresan 3 y 8 como valores y que la variables usadas son A y B, entonces A=3 y B=8, pero luego debe quedar A=8 y B=3.

#include <iostream>
using namespace std;

int main() {
    float num1, num2;
    cout << "Ingrese dos numeros" << endl;
    cin >> num1;
    cin >> num2;  
    cout << "El valor de num 1 es: " << num1 << endl;
    cout << "El valor de num 2 es: " << num2 << endl;
    float num3 = num1;
    num1 = num2;
    num2 = num3;
    cout << "El valor de num 1 es: " << num1 << endl;
    cout << "El valor de num 2 es: " << num2 << endl;
}   