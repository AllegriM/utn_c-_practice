// 16. Hacer un programa que muestre los números primos entre el 1 y el 10000. El usuario no debe ingresar nada en este programa.

#include <iostream>
using namespace std;

int main() {
    int i, j;
    bool esPrimo = true, noEsPrimo = false;

    for(i = 1; i <= 10000; i++){
        for(j = 1; j <= i; j++){
            if(j != 1 && j != i && i % j == 0){
                esPrimo = false;
                noEsPrimo = true;
            }
            if(i % i == 0 && i % 1 == 0 && !noEsPrimo){
                esPrimo = true;
            }
        }
        if(esPrimo){
            cout << i << endl;
        }
    }    
}