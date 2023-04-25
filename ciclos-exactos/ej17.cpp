// 17. Una estación meteorológica registró una muestra climática de los últimos 15 días. Por cada día registró:
// Número de día (entero)
// Temperatura (float)
// Milímetros de lluvia (float)
// Visibilidad en km (float)

// Hay un registro por cada día. La información se encuentra ordenada por día. Se pide calcular e informar:
// El número de día que se haya registrado la temperatura máxima.
// La amplitud térmica de todo el período.
// La cantidad de días con neblina.
// Mostrar "Quincena lluviosa" si hubo más días de lluvia que días sin lluvia. Mostrar "Quincena húmeda" si llovió al menos un tercio de los días. De lo contrario mostrar "Quincena seca".

// NOTA: La amplitud térmica es la diferencia entre la temperatura máxima y la temperatura mínima.
// NOTA: Se considera neblina a una visibilidad menor a 2 km.

#include <iostream>
using namespace std;

int main(){
    int dia, cantDiaLluvia = 0, cantDiasNeblina = 0, i, numeroDia, amplitudTermica;
    float temperatura, lluvia, visibilidad, maxTemp, minTemp;

    for (i = 1; i <= 15; i++){
        cout << "Ingrese número de día " << i << ":" << endl;
        cin >> dia;
        cout << "Ingrese temperatura: " << endl;
        cin >> temperatura;        
        cout << "Ingrese milímetros de lluvia: " << endl;
        cin >> lluvia;        
        cout << "Ingrese visibilidad en km: " << endl;
        cin >> visibilidad; 

        if(i == 0){
            maxTemp = temperatura;
            minTemp = temperatura;
        }

        if(temperatura > maxTemp){
            maxTemp = temperatura;
            numeroDia = dia;
        }

        if(temperatura < minTemp){
            minTemp = temperatura;
        }
        
        if(visibilidad < 2){
            cantDiasNeblina++;
        }

        if(lluvia > 0){
            cantDiaLluvia++;
        }

        if(i==15){
            amplitudTermica = maxTemp - minTemp;
            cout << "Cantidad dias con neblina: " << cantDiasNeblina << endl;
            cout << "Amplitud termica: " << amplitudTermica << endl;
            cout << "Dia con mayor temperatura: " << numeroDia << endl;
            if(cantDiaLluvia >= 15){
                cout << "Quincena lluviosa";
            }else if(cantDiaLluvia<=5){
                cout << "Quincena húmeda";
            }else{
                cout << "Quincena seca";
            }
        }
    }
}