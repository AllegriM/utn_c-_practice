
#include <iostream>
using namespace std;

int main(){
    float importe, importeConDescuento, porcentajeDescuento;
    cout << "Ingrese el importe de la venta y luego el del descuento: " << endl;
    cin >> importe;
    cin >> importeConDescuento;
    cout << "Importe sin descuento: " << importe << endl;
    cout << "Importe con descuento: " << importeConDescuento << endl;
    porcentajeDescuento = (importeConDescuento * 100) / importe; 
    cout << "Porcentaje de descuento: " << 100 - porcentajeDescuento << "%" << endl;    
}