// Hacer un programa para ingresar por teclado la cantidad de asientos disponibles en un avión y 
// la cantidad de pasajes ocupados y luego calcular e informar el porcentaje de ocupación y
//  el porcentaje de no ocupación del mismo.

#include <iostream>
using namespace std;

int main(){
    int asientosDisponibles;
    float pasajesOcupados, porcentajeOcupacion, porcentajeNoOcupacion;
    cout << "Ingrese la cantidad de asientos Disponibles: " << endl;
    cin >> asientosDisponibles;
    cout << "Ingrese los pasajes ocupados: " << endl;    
    cin >> pasajesOcupados;
    porcentajeOcupacion = (pasajesOcupados / asientosDisponibles) * 100;
    porcentajeNoOcupacion = 100 - porcentajeOcupacion;
    cout << "El porcentaje de ocupacion es de: " << porcentajeOcupacion << "%" << endl;    
    cout << "El porcentaje de disponibilidad es de: " << porcentajeNoOcupacion << "%" << endl;   
}