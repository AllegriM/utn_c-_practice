// 4. Hacer un programa para que el usuario ingrese dos números y luego el programa muestre por pantalla los números entre el menor y el mayor de ambos. 
// Ejemplo, si el usuario ingresa 3 y 15, se mostrarán los números entre el 3 y el 15; y si el usuario ingresa 25 y 8, se mostrarán los números entre el 8 y el 25.

#include <iostream>
using namespace std;

int main(){

    int num1, num2;

    cout << "Ingrese dos numeros: " << endl;
    cin >> num1 >> num2;

    if(num1 < num2){
        for (int i = num1; i < num2; i++){
            cout << i << endl;
        }
    }else{
        for (int i = num2; i < num1; i++){
            cout << i << endl;
        }
    }

}


