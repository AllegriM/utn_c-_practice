// 6. Hacer un programa para ingresar por teclado tres números y 
// luego determinar e informar con una leyenda aclaratoria si los tres son iguales entre sí, caso contrario no emitir nada.
//  Ayuda: Si A es igual a B y B es igual a C, entonces A y C son iguales.

#include <iostream>
using namespace std;

int main(){
    int num1, num2, num3;

    cout << "Ingrese el numero 1: " << endl;
    cin >> num1;

    cout << "Ingrese el numero 2: " << endl;
    cin >> num2;

    cout << "Ingrese el numero 3: " << endl;
    cin >> num3;

    if (num1 == num2 && num2 == num3){
        cout << "A, B y C son iguales entre si";
    }else{
        cout << "NO son todos iguales.";
    }

}