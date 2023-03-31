// Hacer un programa para ingresar una letra en mayúsculas en una variable de tipo char y 
// mostrar cuántas letras de diferencia hay en el alfabeto con respecto a la 'A'.

#include <iostream>
using namespace std;

int main() {
    char letra;
    int diferencia;

    cout << "Ingrese la letra en mayuscula: " << endl;
    cin >> letra; 

    diferencia = letra - 'A';

    cout << "La letra " << letra << " tiene " << diferencia << " letras de diferencia con respecto a la letra A." << endl;

    return 0;

}