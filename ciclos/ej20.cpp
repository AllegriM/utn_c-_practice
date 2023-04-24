// 20. Se dispone de la información de los últimos 19 partidos del futbolista Diego Armando Laradona. Por cada partido se registró:
// Número de partido
// Minutos jugados
// Tarjetas amarillas
// Tarjetas rojas
// Goles

// Existe un registro para cada partido. Los mismos se encuentran ordenados por número de partido. Se pide calcular e informar:
// La cantidad de partidos que no jugó (partidos con minutos igual a cero)
// La cantidad de partidos que jugó por completo (minutos >= 90)
// El promedio de tarjetas recibidas por partido.
// El número de partido en el que haya convertido mayor cantidad de goles. Indicar también los goles convertidos.
// La mejor racha de partidos convirtiendo goles. Se debe mostrar la mayor cantidad de partidos consecutivos en los que haya convertido.

#include <iostream>
using namespace std;

int main()
{
    int i, numPartido, minutosJugados, tarjetasAmarillas, tarjetasRojas, goles, cantPartidosNoJugados = 0, cantPartidosCompletos = 0, cantTarjetas = 0, maxGoles = 0, numPartidoMaxGoles = 0, golesConsecutivos = 0, maxGolesConsecutivos = 0;

    for (i = 1; i <= 19; i++)
    {
        cout << "Ingrese número de partido " << i << ":" << endl;
        cin >> numPartido;
        cout << "Ingrese minutos jugados: " << endl;
        cin >> minutosJugados;
        cout << "Ingrese tarjetas amarillas: " << endl;
        cin >> tarjetasAmarillas;
        cout << "Ingrese tarjetas rojas: " << endl;
        cin >> tarjetasRojas;
        cout << "Ingrese goles: " << endl;
        cin >> goles;

        if (minutosJugados == 0)
        {
            cantPartidosNoJugados++;
        }

        if (minutosJugados >= 90)
        {
            cantPartidosCompletos++;
        }

        cantTarjetas += tarjetasAmarillas + tarjetasRojas;

        if (goles > maxGoles)
        {
            maxGoles = goles;
            numPartidoMaxGoles = numPartido;
        }

        if (goles > 0)
        {
            golesConsecutivos++;
        }
        else
        {
            if (golesConsecutivos > maxGolesConsecutivos)
            {
                maxGolesConsecutivos = golesConsecutivos;
            }
            golesConsecutivos = 0;
        }

        if (i == 19)
        {
            cout << "Cantidad de partidos no jugados: " << cantPartidosNoJugados << endl;
            cout << "Cantidad de partidos completos: " << cantPartidosCompletos << endl;
            cout << "Promedio de tarjetas recibidas por partido: " << cantTarjetas / 19 << endl;
            cout << "Número de partido en el que haya convertido mayor cantidad de goles: " << numPartidoMaxGoles << " goles: " << maxGoles << endl;
            cout << "Mejor racha de partidos convirtiendo goles: " << maxGolesConsecutivos << endl;
        }
    }
}