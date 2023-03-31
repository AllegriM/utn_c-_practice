// Hacer un programa para un cajero automático para ingresar un importe a retirar y 
// convertir el mismo en la cantidad de billetes de $ 1.000, $ 500, $ 200 y $ 100 a entregar.

#include <iostream>
using namespace std;

int main() {
    int importe, billeteMil, billeteQuini, billeteDoscientos, billeteCien;

    cout << "Ingrese el importe: " << endl;
    cin >> importe; 

    billeteMil = importe / 1000;
    billeteQuini = (importe % 1000) / 500;
    billeteDoscientos = (importe % 500) / 200;
    billeteCien = (importe % 200) / 100;

    cout << billeteMil << " billetes de 1000 " << endl;
    cout << billeteQuini << " billetes de 500 " << endl;
    cout << billeteDoscientos << " billetes de 200 " << endl;
    cout << billeteCien << " billetes de 100 " << endl;
}