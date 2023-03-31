// Hacer un programa para ingresar por teclado el importe de una venta 
// y el porcentaje de descuento aplicada a la misma y luego informar por pantalla el importa a pagar.

#include <iostream>
using namespace std;

int main(){
    float importe, descuento, montoDescuento, total;
    cout << "Ingrese el importe de la venta y luego el del descuento: " << endl;
    cin >> importe;
    cin >> descuento;
    cout << "El importe es de: " << importe << endl;
    cout << "El descuento es de: " << descuento << "%" << endl;
    montoDescuento = (descuento * importe) / 100;
    total = importe - montoDescuento;
    cout << "El total es de: " << total << endl;    
}