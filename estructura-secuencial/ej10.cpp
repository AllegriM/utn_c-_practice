// Hacer un programa para ingresar por teclado una cantidad de horas y 
// mostrar por pantalla a cuantos días y horas equivalen.

#include <iostream>
using namespace std;

int main() {

    int dias, horas;

    cout << "Ingrese la cantidad de horas: " << endl;
    cin >> horas;

    dias = horas / 24;
    horas = (horas % 24);

    cout << dias << " dias." << endl;
    cout << horas << " horas."  << endl;
}