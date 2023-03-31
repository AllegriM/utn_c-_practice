// Hacer un programa para ingresar por teclado una cantidad de minutos 
// y mostrar por pantalla a cuantas horas y minutos equivalen.

#include <iostream>
using namespace std;

int main() {

    float horas, mins;
    int minutos;

    cout << "Ingrese la cantidad de minutos: " << endl;
    cin >> minutos;

    horas = minutos / 60;
    mins = (minutos % 60);

    cout << "Horas: " << horas << endl;
    cout << "Minutos: " << mins << endl;
}