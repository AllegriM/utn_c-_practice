// 9. Hacer un programa para ingresar tres números y listar el máximo de ellos.

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

    if (num1 > num2 && num1 > num3){
        cout << num1 << " es mas grande que " << num2 << " y " << num3;
    }else{
        if(num2 > num1 && num2 > num3){
            cout << num2 << " es mas grande que " << num1 << " y " << num3;
        }else{
            cout << num3 << " es mas grande que " << num2 << " y " << num1;
        }
    }
}



