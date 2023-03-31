// Hacer un programa para ingresar por teclado una cantidad de minutos y 
// mostrar por pantalla a cuántos días, horas y minutos equivalen.

#include <iostream>
using namespace std;

int main() {
    int minutos, dias, horas, rMin; 

    cout << "Ingrese la cantidad de minutos: ";
    cin >> minutos;

    dias = minutos / 1440;
    rMin = minutos % 1440;
    horas = rMin / 60;
    minutos = rMin % 60;


    cout << dias << " dia/s." << endl;
    cout << horas << " hora/s." << endl;
    cout << minutos << " minuto/s." << endl;
}