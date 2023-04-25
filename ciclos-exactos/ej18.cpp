// 18. La cuenta corriente de la famosa cantante Lady Lara ha registrado 14 movimientos durante la semana pasada. Por cada movimiento se registró:
// Número de movimiento
// Día
// Tipo ('E' - Extracción / 'D' - Depósito)
// Importe

// Existe un registro por movimiento. Se desea calcular e informar:
// El saldo final de la cuenta.
// El porcentaje de movimientos de extracción y el porcentaje de depósito.
// El depósito de mayor importe indicando también día y número de movimiento.
// La cantidad de movimientos del día 10.

#include <iostream>
using namespace std;

int main() {
    int i, numMov, numDia, saldoFinal = 0, movExtraccion = 0, movDeposito = 0, maxDeposito = 0, diaDeposito, numMovimiento;
    float importe; 
    char tipoMov;

    for(i = 1; i <= 14; i++){
        cout << "Ingrese x registro numero de movimiento, dia, tipo ('E' o 'D') y importe: " << endl;
        cin >> numMov >> numDia >> tipoMov >> importe;

        if(i == 1 && tipoMov == 'D'){
            maxDeposito = importe;
            diaDeposito = numDia;
            numMovimiento = numMov;
        }else if(importe > maxDeposito && tipoMov == 'D'){
            maxDeposito = importe;
            diaDeposito = numDia;
            numMovimiento = numMov;
        }

        if(tipoMov == 'E'){
            saldoFinal -= importe; 
            movExtraccion++;
        }else{
            saldoFinal += importe;
            movDeposito++;
        }

    }
    movDeposito = (movDeposito * 100) / 14;
    movExtraccion = (movExtraccion * 100) / 14;

    cout << "Saldo final: " << saldoFinal << endl;
    cout << "Porcentaje de movimientos de extraccion: " << movExtraccion << "%" << endl;
    cout << "Porcentaje de movimientos de deposito: " << movDeposito << "%" << endl;
    cout << "Deposito de mayor importe: " << maxDeposito << " dia: " << diaDeposito << " numero de movimiento: " << numMovimiento << endl;
    
}



