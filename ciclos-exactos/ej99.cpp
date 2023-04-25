#include <iostream>
using namespace std;

int main()
{
    int i, CantSueldosMayores_a_50mil = 0;
    float sueldo, SueldoMax = 0, SueldoMin = 0, SueldoProm, SumaDeSueldos = 0;
    const int empleados = 10;
    SueldoMax = sueldo;        
    SueldoMin = sueldo;
    for (i = 0; i < empleados; i++)
    {
        cout << "ingrese ----> " << i + 1 << ":";
        cin >> sueldo;
        if (sueldo > 50000){
            CantSueldosMayores_a_50mil++;
            SumaDeSueldos += sueldo;
        }
        if (sueldo > SueldoMax){
            SueldoMax = sueldo;
        }
        if (sueldo < SueldoMin){
            SueldoMin = sueldo;
        }
    }
    SueldoProm = SumaDeSueldos / 10;
    cout << "cantidad de sueldo maximos  : " << SueldoMax << endl;
    cout << "cantidad de sueldo minimo   : " << SueldoMin << endl;
    cout << "el sueldo promedio es  : " << SueldoProm << endl;
    cout << "cantidad de sueldo mayores a 50000 :" << CantSueldosMayores_a_50mil;
    return 0;
}