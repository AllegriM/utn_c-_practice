// Hacer un programa para mostrar por pantalla los números del 1 al 20 salteando de a 3 elementos. Es decir: 1, 4, 7, 10, 13, 16, 19.

#include <iostream>
using namespace std;

int main() {

    for(int i = 1; i <= 20; i+=2){
        cout << i << endl;
    }
}