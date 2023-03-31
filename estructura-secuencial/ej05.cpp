// Un comercio vende tres marcas de alfajores distintas A, B y C. 
// Hacer un programa para ingresar por teclado la cantidad de alfajores vendidos de cada una de las tres marcas 
// y luego se informe el porcentaje de ventas para cada una de ellas.

#include <iostream>
using namespace std;

int main() {
    float A, B, C; 
    float porcentajeA, porcentajeB, porcentajeC;
    cout << "Ingrese la cantidad de alfajores A vendidos: " << endl; 
    cin >> A;
    cout << "Ingrese la cantidad de alfajores B vendidos: " << endl; 
    cin >> B;
    cout << "Ingrese la cantidad de alfajores C vendidos: " << endl; 
    cin >> C;
    porcentajeA = (A / (A + B + C)) * 100;
    porcentajeB = (B / (A + B + C)) * 100;
    porcentajeC = (C / (A + B + C)) * 100;
    cout << "El porcentaje de A vendidos es de: " << porcentajeA << "%" << endl; 
    cout << "El porcentaje de B vendidos es de: " << porcentajeB << "%" << endl; 
    cout << "El porcentaje de C vendidos es de: " << porcentajeC << "%" << endl; 
}