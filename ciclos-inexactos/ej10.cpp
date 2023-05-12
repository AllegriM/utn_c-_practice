// 10 El festival Larapalooza, el mejor festival musical del mundo,
//     brindará una serie de conciertos distribuidos en tres jornadas distintas
//         .Se desea un programa que registre los artistas que
//             participarán.Por cada artista se registró
//     : Número de
//       artista(entero) Integrantes(entero) Jornada(1, 2 o 3) Duración del show
//       en minutos(entero)

// La información no se encuentra ordenada bajo ningún
//     criterio.La carga de datos se finaliza con un número de artista igual a
//         cero.Calcular e informar
//     : El número de artista que realice el show más largo de la
//           jornada 1. La cantidad de
//           solistas(artistas de 1 integrante) que
//       participaron en cada una de las jornadas.(se muestran tres resultados)
//           .La jornada más extensa(en minutos)
//           .Duración promedio de show por artista(se muestra un resultado)
//           .

#include <iostream>
using namespace std;

int main() {
  int numArtista, banda, jor, duracionShow, mayorDuracion, numArtistaMayorShow;
  int solistaJ1 = 0, solistaJ2 = 0, solistaJ3 = 0;
  int duracionJ1 = 0, duracionJ2 = 0, duracionJ3 = 0;
  int duracionTotal = 0, totalArtistas = 0, duracionPromedio = 0;
  bool primerArtista = true;

  cout << "Ingrese numero de artista, integrantes, jornada (1,2,3), duracion "
          "del show: "
       << endl;
  cin >> numArtista, banda, jor, duracionShow;

  while (numArtista != 0) {
    cout << "Ingrese numero de artista, integrantes, jornada (1,2,3), duracion "
            "del show: "
         << endl;
    cin >> numArtista, banda, jor, duracionShow;

    if (jor == 1) {
      mayorDuracion = duracionShow;
      numArtistaMayorShow = numArtista;
      if (duracionShow > mayorDuracion) {
        mayorDuracion = duracionShow;
        numArtistaMayorShow = numArtista;
      }
      duracionJ1 += duracionShow;
      if (banda == 1) {
        solistaJ1++;
      }
    } else if (jor == 2) {
      duracionJ2 += duracionShow;
      if (banda == 1) {
        solistaJ2++;
      }
    } else {
      duracionJ3 += duracionShow;
      if (banda == 1) {
        solistaJ3++;
      }
    }

    duracionTotal += duracionShow;
    totalArtistas++;
    // Cantidad de solistas
    primerArtista = false;
  }
  duracionPromedio = duracionTotal / totalArtistas;

  cout << "El numero de artista que realizo el show mas largo de la jornada 1 "
          "es: "
       << numArtistaMayorShow << endl;
  cout << "La cantidad de solistas que participaron en la jornada 1 es: "
       << solistaJ1 << endl;
  cout << "La cantidad de solistas que participaron en la jornada 2 es: "
       << solistaJ2 << endl;
  cout << "La cantidad de solistas que participaron en la jornada 3 es: "
       << solistaJ3 << endl;
  cout << "La duracion promedio de show por artista es: " << duracionPromedio
       << endl;
  if (duracionJ1 > duracionJ2 && duracionJ1 > duracionJ3) {
    cout << "La jornada mas extensa es la 1" << endl;
  } else if (duracionJ2 > duracionJ1 && duracionJ2 > duracionJ3) {
    cout << "La jornada mas extensa es la 2" << endl;
  } else {
    cout << "La jornada mas extensa es la 3" << endl;
  }
}