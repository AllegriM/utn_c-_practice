// 15. Hacer un programa para ingresar por teclado las cuatro notas de los exámenes obtenidas por un alumno y luego emitir uno solo de los cartel de acuerdo a las siguientes condiciones: 
// - “Promociona”, si obtuvo en los cuatro exámenes nota 7 o más. 
// - “Rinde examen final”, si obtuvo nota 4 o más en por lo menos tres exámenes. 
// - “Recupera Parciales”, si obtuvo nota 4 o más en por lo menos uno de los exámenes. 
// - “Recursa la materia”, si no aprobó ningún examen parcial.

#include <iostream> 
using namespace std;

int main(){

    int notas[4], sumaNotas;

    for (int i = 0; i < 4; i++){
        cout << "Ingrese la nota numero " << i << ":" << endl;
        cin >> notas[i];
    }
    
    sumaNotas = notas[0] + notas[1] + notas[2] + notas[3];

    if(notas[0] >= 7 && notas[1] >= 7 && notas[2] >= 7 && notas[3] >= 7){
        cout << "Promociona";
    }else if((notas[0] >= 4 && notas[1] >= 4 && notas[2] >= 4) || (notas[0] >= 4 && notas[1] >= 4 && notas[3] >= 4) || (notas[0] >= 4 && notas[2] >= 4 && notas[3] >= 4) || (notas[1] >= 4 && notas[2] >= 4 && notas[3] >= 4)){
        cout << "Rinde examen final";
    }else if(notas[0] >= 4 || notas[0] >= 4 || notas[1] >= 4 || notas[2] >= 4){
        cout << "Recupera Parciales";
    }else{
        cout << "Recursa la materia";
    }
}