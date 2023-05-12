// La clínica San Simón Protector dispone de la información de los últimos
// turnos de sus enfermeros/as. Por cada turno trabajado por un enfermero se
// registró la siguiente información:

// Legajo del enfermero/a (entero entre 1000 y 15000)
// Número de turno (entero)
// Horario ('M' - Mañana, 'T' - Tarde, 'N' - Noche)
// Cantidad de horas trabajadas en el turno (entero mayor a cero)

// La información se encuentra agrupada por legajo de enfermero. No todos los
// enfermeros trabajaron la misma cantidad de turnos. Para indicar el fin de los
// registros de un enfermero se ingresa un número de turno igual a cero. Para
// indicar el fin del lote de datos se ingresa un legajo de enfermero negativo.

// Notas
// Cada turno consiste en 8 horas.
// Las horas excedentes se consideran horas extras.
// Por ejemplo: Si un enfermero trabajó 12 horas en un turno, realizó 8 hs
// regulares y 4 hs extra. En cambio, si trabajó 6 horas en un turno: realizó 6
// hs regulares y 0 hs extra.

// A)Por cada enfermero, el promedio de horas trabajadas por turno en el horario
// de la noche. 30
// B)La cantidad total de horas extras realizadas entre todos
// los enfermeros. 20
// C)La cantidad de enfermeros que realizaron al menos un
// turno en los tres horarios (mañana, tarde y noche). 30
// D)El horario (mañana,
// tarde o noche) que haya registrado menor cantidad de horas trabajadas 20
// Aclaraciones
// Sólo habrá un horario que haya registrado la menor cantidad de horas
// trabajadas.

#include <iostream>
using namespace std;

int main() {
  int numLegajo = 0, numTurno, cantHorasTrabajadas, cantHorasNoche = 0,
      cantTurnosNoche = 0, cantHorasExtras = 0, cantEnfermeros = 0,
      cantEnfermeros3Turnos = 0, cantHorasManana = 0, cantHorasTarde = 0,
      cantHorasMin = 0;
  int totalHorasMañana = 0, totalHorasTarde = 0, totalHorasNoche = 0;
  char horario;
  const int HORAS_TURNO = 8;
  bool turnoMananaTrabajado = false, turnoTardeTrabajado = false,
       turnoNocheTrabajado = false;

  while (numLegajo >= 0) {
    cout << "Ingrese el numero de legajo" << endl;
    cin >> numLegajo;

    if (numLegajo >= 0) {
      cout << "************Legajo************: " << numLegajo << endl;

      cout << "Ingrese numero de turno: ";
      cin >> numTurno;

      while (numTurno != 0) {
        cout << "Ingrese el horario" << endl;
        cin >> horario;
        cout << "Ingrese la cantidad de horas" << endl;
        cin >> cantHorasTrabajadas;
        if (cantHorasTrabajadas > HORAS_TURNO) {
          cantHorasExtras += (cantHorasTrabajadas - HORAS_TURNO);
        }
        switch (horario) {
          case 'M':
            turnoMananaTrabajado = true;
            totalHorasMañana += cantHorasTrabajadas;
            break;
          case 'T':
            turnoTardeTrabajado = true;
            totalHorasTarde += cantHorasTrabajadas;
            break;
          case 'N':
            turnoNocheTrabajado = true;
            cantHorasNoche += cantHorasTrabajadas;
            totalHorasNoche += cantHorasTrabajadas;
            cantTurnosNoche++;
            break;
          default:
            cout << "Horario incorrecto" << endl;
            break;
        }
        cout << "Ingrese el numero de turno" << endl;
        cin >> numTurno;
      }
      if (cantTurnosNoche > 0) {
        cout << "***Promedio horas trabajadas a la noche*** => "
             << cantHorasNoche / cantTurnosNoche << endl;
      } else {
        cout << "***Promedio horas trabajadas a la noche*** => 0" << endl;
      }
      if (turnoMananaTrabajado && turnoTardeTrabajado && turnoNocheTrabajado) {
        cantEnfermeros3Turnos++;
      }
      turnoMananaTrabajado = false;
      turnoTardeTrabajado = false;
      turnoNocheTrabajado = false;
      cantEnfermeros++;
    }
    cantHorasNoche = 0;
    cantTurnosNoche = 0;
  }
  if ((totalHorasMañana < totalHorasTarde &&
       totalHorasMañana < totalHorasNoche) ||
      totalHorasMañana == 0) {
    cout << "***Horario con menos horas trabajadas*** => mañana" << endl;

  } else if ((totalHorasTarde < totalHorasMañana &&
              totalHorasTarde < totalHorasNoche) ||
             totalHorasTarde == 0) {
    cout << "***Horario con menos horas trabajadas*** => tarde" << endl;
  } else {
    cout << "***Horario con menos horas trabajadas*** => noche" << endl;
  }

  cout << "***Total horas extras*** => " << cantHorasExtras << endl;
  cout << "***Cantidad enfermeros triple turno*** => " << cantEnfermeros3Turnos
       << endl;
  return 0;
}