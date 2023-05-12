#include <iostream>

using namespace std;

int main() {
  setlocale(LC_ALL, "Spanish");

  int codpar, numv, tiempo,
      desca = 0, i, b = 0, total, menortiempo = 0, totaltiempo = 0, ganador,
      cantipart = 0, partinodesca = 0, provueldesca = 0, provueltasnodes = 0;

  cout << "Ingrese código de participante" << endl;

  cin >> codpar;

  while (codpar > 0) {
    int condes = 0, cuartav = 0;

    for (i = 0; i < 4; i++) {
      cout << "Ingrese número de vuelta 1-2-3-o 4" << endl;

      cin >> numv;

      cout << "Ingrese tiempo en minutos" << endl;

      cin >> tiempo;

      cout << "Ingrese descalificado si-1 o no-2" << endl;

      cin >> desca;

      totaltiempo += tiempo;

      if (desca == 1) {
        condes++;
      }

      if (numv == 4 && desca == 2) {
        cuartav++;
      }
    }

    if (condes == 0) {
      cout << "Porcentaje de vueltas NO descalificadas 100% " << endl;  // D

      cout << "Porcentaje de vueltas descalificadas 0% " << endl;  // D

    } else {
      provueldesca = (condes * 100) / 4;

      cout << "Porcentaje de vueltas descalificadas " << provueldesca
           << endl;  // D

      total = 4 - condes;

      provueltasnodes = (total * 100) / 4;

      cout << "Porcentaje de vueltas NO descalificadas " << provueltasnodes
           << endl;
    }  // D

    if (cuartav == 1) {
      partinodesca++;
    }

    if (b == 0 && condes == 0) {
      menortiempo = totaltiempo;

      b = 1;

      ganador = codpar;
    }

    else if (b == 1 && condes == 0) {
      if (totaltiempo < menortiempo) {
        menortiempo = totaltiempo;

        ganador = codpar;
      }
    }

    if (condes >= 1) {
      cantipart++;
    }

    cout << endl;

    cout << "Ingrese código de participante" << endl;

    cin >> codpar;
  }

  cout << "El ganador de competencia es el número " << ganador
       << " en un tiempo de " << menortiempo << " minutos" << endl;  // A

  cout << "Cantidad de participantes descalificados al menos una vez "
       << cantipart << endl;  // B

  cout << "Cantidad de participantes NO descalificados en la última vuelta "
       << partinodesca << endl;  // C

  system("pause>nul");

  return 0;
}