// 8 Hacer un programa que permita ingresar el legajo y sueldo de 10 empleados y determine:
// El legajo del empleado con mayor sueldo

#include <iostream>
using namespace std;

int main() {
    int i, sueldo, maxSueldo, legajo, legajoMaxSueldo;

    cout << "Ingrese el legajo del empleado 00:" << endl;
    cin >> legajo;
    cout << "Ingrese el sueldo del empleado 00:" << endl;
    cin >> sueldo;

    maxSueldo = sueldo;
    legajoMaxSueldo = legajo;

    for (i = 0; i < 10; i++){
        cout << "Ingrese el legajo del empleado " << i+1 << ":" << endl;
        cin >> legajo;
        cout << "Ingrese el sueldo del empleado " << i+1 << ":" << endl;
        cin >> sueldo;

        if(sueldo > maxSueldo){
            maxSueldo = sueldo;
            legajoMaxSueldo = legajo;
        }
    }

    cout << "El sueldo mas alto es: " << maxSueldo << endl;
    cout << "El legajo del sueldo mas alto es: " << legajoMaxSueldo;

    return 0;
}


