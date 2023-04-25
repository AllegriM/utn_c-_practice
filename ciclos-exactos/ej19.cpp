// 19. Dada una lista de 10 números enteros. Calcular e informar el primer número par, el primer número primo.

#include <iostream>
using namespace std;

int main()
{
    int i, num, primerPar = 0, primerPrimo = 0;

    for (i = 1; i <= 10; i++)
    {
        cout << "Ingrese el numero " << i << ":" << endl;
        cin >> num;

        if (i == 1 && num % 2 == 0)
        {
            primerPar = num;
        }
        else if (i == 1 && num % 2 != 0)
        {
            primerPrimo = num;
        }

        if (num % 2 == 0 && primerPar == 0)
        {
            primerPar = num;
        }
        else if (num % 2 != 0 && primerPrimo == 0)
        {
            primerPrimo = num;
        }
    }

    cout << "El primer numero par es: " << primerPar << endl;
    cout << "El primer numero primo es: " << primerPrimo << endl;

    return 0;
}