// 2. Hacer un programa para ingresar por teclado dos números y luego informar
// por pantalla con un cartel aclaratorio si el primer número es múltiplo del segundo. 

#include <iostream>
using namespace std;

int main() {
    int num1, num2; 

    cout << "Ingresar el numero 1: " << endl;
    cin >> num1;

    cout << "Ingresar el numero 2: " << endl;
    cin >> num2;

    if((num1 % num2) == 0){
        cout << "El numero " << num1 << " es multiplo del numero " << num2; 
    }else{
        cout << "No son multiplos";
    }
    return 0;
}