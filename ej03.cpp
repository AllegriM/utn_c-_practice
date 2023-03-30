// 3. Una concesionaria de autos paga a los vendedores un sueldo fijo de $ 15.000 más $ 2.000 de premio por cada auto vendido. 
// Hacer un programa que permita ingresar por teclado la cantidad de autos vendidos por un vendedor y luego informar por pantalla el sueldo total a pagar.
// Ejemplo. Si la cantidad de autos vendidos fuera 4 entonces el sueldo total a pagar es de $ 23.000.

#include <iostream>
using namespace std;

int main() {
    int sueldoFijo, comision, autosVendidos;
    float sueldoFinal;
    sueldoFijo = 15000;
    comision = 2000;
    cout << "Ingrese la cantidad de autos vendidos: ";
    cin >> autosVendidos;
    sueldoFinal = sueldoFijo + (autosVendidos * comision);
    cout << "El sueldo fijo es de: " << sueldoFijo << endl;
    cout << "El total de comisiones es de: " << (comision * autosVendidos) << endl;
    cout << "El sueldo final es de: " << sueldoFinal << endl;
    return 0;
}

