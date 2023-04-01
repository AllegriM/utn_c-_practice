// 10. Hacer un programa para ingresar cinco números y listar el máximo de ellos.

#include <iostream>
using namespace std;

int main(){
    int num1, num2, num3, num4, num5;

    cout << "Ingrese el numero 1: " << endl;
    cin >> num1;

    cout << "Ingrese el numero 2: " << endl;
    cin >> num2;

    cout << "Ingrese el numero 3: " << endl;
    cin >> num3;

    cout << "Ingrese el numero 4: " << endl;
    cin >> num4;
    
    cout << "Ingrese el numero 5: " << endl;
    cin >> num5;

    if (num1 > num2 && num1 > num3 && num1 > num4 && num1 >> num5){
        cout << num1 << " es mas grande que " << num2 << " ," << num3 << " ," << num4 << " y " << num5;
    }else{
        if(num2 > num1 && num2 > num3 && num2 > num4 && num2 > num5){
            cout << num2 << " es mas grande que " << num1 << " ," << num3 << " ," << num4 << " y " << num5;
        }else{
            if(num3 > num1 && num3 > num2 && num3 > num4 && num3 > num4){
                cout << num3 << " es mas grande que " << num1 << " ," << num2 << " ," << num4 << " y " << num5;
            }else{
                if(num4 > num1 && num4 > num2 && num4 > num3 && num4 > num5){
                    cout << num4 << " es mas grande que " << num1 << " ," << num2 << " ," << num3 << " y " << num5;
                }else{
                    cout << num5 << " es mas grande que " << num1 << " ," << num2 << " ," << num3 << " y " << num4;
                }
            }
        }
    }
}


