// Una granja vende la caja de 12 unidades a $ 100 y cada huevo suelto a $ 12.
// Hacer un programa para ingresar la cantidad de huevos que compra un cliente y mostrar por pantalla el importe total a pagar.
// Recordatorio. Por cada 12 huevos se debe calcular una caja y el excedente se calcula como suelto.

#include <iostream>
using namespace std;

int main() {
    int huevos, caja, suelto;
    float total;

    cout << "Ingrese la cantidad de huevos comprados: " << endl;
    cin >> huevos;

    caja = huevos / 12;
    suelto = huevos % 12;
    total = (caja * 100) + (suelto * 12);

    cout << "Caja/s: " << caja << endl;
    cout << "Suelto/s: " << suelto << endl;
    cout << "Total a pagar: " << total << endl;
}