// Hacer un programa para que un comercio ingrese por teclado la recaudación en pesos 
// para cada una de las cuatro semanas del mes. El programa debe listar la 
// recaudación promedio por semana y el porcentaje de recaudación por semana.

#include <iostream>
using namespace std;

int main(){
    float semana1, semana2, semana3, semana4, promedio, total;
    cout << "Ingrese lo ganado en la semana 1: " << endl; 
    cin >> semana1;
    cout << "Ingrese lo ganado en la semana 2: " << endl; 
    cin >> semana2;
    cout << "Ingrese lo ganado en la semana 3: " << endl; 
    cin >> semana3;
    cout << "Ingrese lo ganado en la semana 4: " << endl; 
    cin >> semana4;

    total = semana1 + semana2 + semana3 + semana4;
    promedio = (semana1 + semana2 + semana3 + semana4) / 4;

    cout << "El promedio por semana es de: " << promedio << endl;

    semana1 = (semana1 * 100) / total;
    semana2 = (semana2 * 100) / total;
    semana3 = (semana3 * 100) / total;
    semana4 = (semana4 * 100) / total;

    cout << "Porcentaje de recaudación de la semana 1: " << semana1 << "%" << endl;
    cout << "Porcentaje de recaudación de la semana 2: " << semana2 << "%" << endl;
    cout << "Porcentaje de recaudación de la semana 3: " << semana3 << "%" << endl;
    cout << "Porcentaje de recaudación de la semana 4: " << semana4 << "%" << endl;
}