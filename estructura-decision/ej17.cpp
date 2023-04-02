// 17. Una empresa de electricidad cobra el servicio a sus clientes de acuerdo a la siguiente escala: 
// $ 10 por kilovatio (kW) por el consumo hasta los primeros 100 kW de consumo. 
// $ 12 por kW por el consumo excedente de 101 a 200 kW. 
// $ 15 por kW por el consumo excedente de 201 kW en adelante.

// Hacer un programa para que, dado el consumo en kilovatios de un determinado cliente, el programa calcule e informe el total a pagar por el mismo. 
// Ejemplo 1: Un consumo de 55 kW, se calculará: $ 10 x 55= $ 550 
// Ejemplo 2: Un consumo de 125 kW, se calculará: $ 10 x 100 + $ 12 x 25 = $1300.
// Ejemplo 3: Un consumo de 250 kW, se calculará: $ 10 x 100 + $ 12 x 100 + $ 15 x 50 = $ 2950.

#include <iostream>
using namespace std;

int main(){
    int consumo, gasto; 

    cout << "Ingrese su consumo mensual en kW: " << endl;
    cin >> consumo;

    if (consumo <= 100) {
        gasto = consumo * 10;
    }
    else if (consumo > 100 && consumo <= 200) {
        gasto = 1000 + (consumo - 100) * 12;
    }
    else {
        gasto = 2200 + (consumo - 200) * 15;
    }

    cout << "El gasto a pagar por el cliente es: $" << gasto << endl;

    return 0;

}