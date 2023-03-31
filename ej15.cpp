// La amplitud térmica es la diferencia entre la temperatura máxima y 
// la temperatura mínima en una zona y tiempo determinado. Dada la temperatura máxima 
// y la temperatura mínima de San Fernando de ayer, calcular y mostrar la amplitud térmica.

#include <iostream>
using namespace std;

int main() {
    float tempMax, tempMin, amplitudTermica;

    cout << "Ingrese la temperatura maxima: " << endl;
    cin >> tempMax; 

    cout << "Ingrese la temperatura minima: " << endl;
    cin >> tempMin; 

    amplitudTermica = tempMax - tempMin;

    cout << "Amplitud termica: " << amplitudTermica << "º";
}