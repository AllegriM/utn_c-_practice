
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