// 6. Hacer un programa para ingresar una lista de 10 números, 
// luego informar cuántos son positivos, cuántos son negativos, y cuántos iguales a cero.

#include <iostream>
using namespace std;

int main(){
    int n, pos = 0, neg = 0, cero = 0;

    for(int i = 0; i < 10; i++){
        cin >> n;
        if(n > 0){
            pos++;
        }else if(n < 0){
            neg++;
        }else{
            cero++;
        }
    }
    cout << "Positivos: " << pos << " ,Negativos: " << neg << " ,Ceros: " << cero;

}