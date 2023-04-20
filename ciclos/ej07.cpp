// 7. Hacer un programa que permita ingresar el sueldo de 10 empleados y determine:
// El sueldo máximo.
// El sueldo mínimo.
// El sueldo promedio.
// Cantidad de sueldos mayores a $50000.

#include <iostream>
using namespace std;

int main(){
    int sueldo, sueldoMax, sueldoMin, sueldoProm, cantSueldosMayoresACincuenta = 0, total = 0;
    
    cout << "Ingrese un sueldo: " << endl;
    cin >> sueldo;
    sueldoMax = sueldo;
    sueldoMin = sueldo;

    for (int i = 0; i < 9; i++){
        cout << "Ingrese un sueldo: " << endl;
        cin >> sueldo;
        if(sueldo > sueldoMax){
            sueldoMax = sueldo;
        }
        if(sueldo < sueldoMin){
            sueldoMin = sueldo;
        }
        if(sueldo > 50000){
            cantSueldosMayoresACincuenta++;
        }
        total += sueldo;
    }

    sueldoProm = total / 10;

    cout << "SueldoMax: " << sueldoMax;
    cout << "SueldoMin: " << sueldoMin;
    cout << "SueldoProm: " << sueldoProm;
}