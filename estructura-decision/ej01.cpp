// 1. Hacer un programa para ingresar por teclado un número y luego emitir por pantalla
//  un cartel aclaratorio indicando si el mismo es positivo, negativo o cero.

#include <iostream> 
using namespace std;

int main(){
    int numero; 
    cout << "Ingresar un numero: " << endl;
    cin >> numero;

    if(numero > 0){
        cout << numero << " es mayor a 0 y positivo";
    }
    else{
        if(numero == 0){
            cout << numero << " es igual a 0";
        }else{
            cout << numero << " es menor a 0 y negativo";
        }
    }
    return 0;
}