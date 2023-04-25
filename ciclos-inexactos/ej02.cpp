// 2. Hacer un programa para ingresar una lista de números que finaliza cuando se ingresa un cero,
// luego informar el máximo.
// Ejemplo: 5, 10, 20, 8, 25, 13, 35, -8, -5, 20, 0. Se listará Máximo 35.
// Ejemplo: 5, 10, 20, 8, 55, 13, 55, -8, -5, 20, 0. Se listará Máximo 55.
// Ejemplo: -5, -10, -20, -8, -55, -13, -55, -8, -15, -20, 0. Se listará Máximo -5.

#include <iostream> 
using namespace std;

int main() {
    int n, max; 

    cout << "Ingrese un numero: " << endl;
    cin >> n; 

    max = n;

    while(n != 0){
        cout << "Ingrese un numero: " << endl;
        cin >> n; 

        if(n > max){
            max = n;
        }
    }

    cout << "El clico finalizo porque se ingreso un 0" << endl;
    cout << "El numero maximo del ciclo fue: "  << max;

}