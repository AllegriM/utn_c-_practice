// Hacer un programa para ingresar el importe de una compra y el descuento a aplicar. 
// Listar por pantalla, el importe sin descuento, 
// el descuento aplicado y el importe total a cobrar.

#include <iostream>
using namespace std;

int main() {
    int importe, descuento;
    float total;

    cout << "Ingrese el importe: " << endl;
    cin >> importe; 

    cout << "Ingrese el descuento: " << endl;
    cin >> descuento; 

    descuento = (descuento * importe) / 100;
    total = importe - descuento;

    cout << "Importe: $ " << importe << endl;
    cout << "Descuento: $ " << descuento << endl;
    cout << "Total: $ " << total << endl;
}