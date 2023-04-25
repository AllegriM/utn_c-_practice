// 3. Hacer un programa para que el usuario ingrese un número positivo y que luego se muestren por pantalla los números entre el 1 y el número ingresado por el usuario. 
// Ejemplo. Si el usuario ingresa 15, se mostrarán los números entre el 1 y el 15.

#include <iostream>
using namespace std;

int main() {
    
    int numero; 
    cin >> numero;
    cout << "Tu numero es: " << numero << " y hay esta cantidad de numero entre 1 y " << numero << endl; 
    for(int i = 1; i < numero; i++){
        cout << i << endl; 
    }

}



