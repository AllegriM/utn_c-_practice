

#include <iostream>
using namespace std;

int main() {
    int frasco, pildoras, briancetamol, pintoxicilina, acidoSimonítico ;

    cout << "Ingrese la cantidad de frascos: " << endl;
    cin >> frasco; 

    pildoras = frasco * 75;
    briancetamol = pildoras * 45;
    pintoxicilina = pildoras * 2;
    acidoSimonítico = pildoras * 7;
    
    cout << "Con " << pildoras << " pildoras necesitamos " << briancetamol << " mg de Briancetamol." << endl;
    cout << "Con " << pildoras << " pildoras necesitamos " << pintoxicilina << " grs de Pintoxicilina." << endl;
    cout << "Con " << pildoras << " pildoras necesitamos " << acidoSimonítico << " mg de Ácido Simonítico." << endl;

    return 0;

}