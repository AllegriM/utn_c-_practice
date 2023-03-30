// 1. Hacer un programa para ingresar por teclado la cantidad de horas trabajadas por un operario
//  y el valor que se le paga por hora trabajada y listar por pantalla el sueldo que le corresponda.

#include <iostream>
using namespace std;
#include <cstdlib>

int main(){
    float horasTrabajadas, remuneracionXHora, sueldo; 
    cout << "Ingrese las horas trabajadas: " << endl;
    cin >> horasTrabajadas; 
    cout << "Ingrese las remuneracion por hora: " << endl;
    cin >> remuneracionXHora; 
    sueldo = horasTrabajadas * remuneracionXHora;
    cout << endl;
    cout << "Sueldo Final: " << sueldo << endl;
    system("pause");
}