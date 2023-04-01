// 11. Hacer un programa para ingresar cinco números y listar cuántos de esos cinco números son positivos.

#include <iostream>
using namespace std;

int main(){
    int num1, num2, num3, num4, num5, cont = 0;

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


    if (num1 > 0){
        cont = cont + 1;
    }   
    if (num2 > 0){
        cont = cont + 1;
    }
    if (num3 > 0){
        cont = cont + 1;
    }
    if (num4 > 0){
        cont = cont + 1;
    }
    if (num5 > 0){
        cont = cont + 1;
    }
    
    cout << "En total hay " << cont << " numeros positivos.";
    
    return 0;
}




