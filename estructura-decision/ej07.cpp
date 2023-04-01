// 7. Hacer un programa para ingresar por teclado tres números 
// e informar con una leyenda aclaratoria si los tres son todos distintos entre sí, caso contrario no emitir nada.
//  Ayuda: Si A es distinto de B y B es distinto de C, eso no signica que A y C sean distintos. Ejemplo: A=8, B=6 y C=8.

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

    if (num1 != num2 && num2 != num3 && num1 != num3){
        cout << "A, B y C son diferentes entre si";
    }else{
        cout << "Alguno de todos ellos es igual entre si.";
    }

}

