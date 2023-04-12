// 5. Hacer un programa para ingresar un N valor que indica la cantidad de números que componen una lista 
// y luego solicitar se ingresen esos N números. Se pide informar cuantos son positivos

#include <iostream>
using namespace std;

int main() {
    int cantidadLista, num, positivos = 0;

    cout << "Ingrese los numeros que componen la lista: " << endl;

    cin >> cantidadLista;

    for(int i = 0; i < cantidadLista; i++){
        cout << "Ingrese el numero: " << endl;
        cin >> num; 
        if(num > 0){
            positivos++;
        }
    }

    cout << "Los numeros positivos son: " << positivos;
}


