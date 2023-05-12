// 9 Se dispone de la información de los exámenes rendidos por algunos
// estudiantes
//     de la UTN FRGP.Por cada registro de examen se conoce : Legajo del
//                                                            estudiante(entero)
// Código de materia(entero) Nota(float)

//         La finalización de la carga de datos se indica con un legajo de
//     estudiante mayor a 30000. Calcular e informar
//     : La nota promedio entre todos los
//       estudiantes.El legajo del estudiante con menor nota
//           .La cantidad de exámenes rendidos para la materia
//       10. El porcentaje de aprobados y no aprobados.

//       NOTA : Un examen se considera aprobado con nota
//     >= 6 NOTA
//     : Si hay varios estudiantes con la menor nota.Informar el primero de
//     ellos.

#include <iostream>
using namespace std;

int main() {
  int legajo, cod, notaTotal = 0, estudianteTotales = 0, notaBaja,
                   legajoNotaBaja, examenesDiez = 0, aprobados = 0,
                   desaprobados = 0;
  float nota, notaPromedio;
  bool primerNota = true;

  while (legajo < 30000) {
    cout << "Ingrese legajo, codigo de materia, nota alumno: " << endl;
    cin >> legajo >> cod >> nota;

    if (primerNota) {
      notaBaja = nota;
      legajoNotaBaja = legajo;
      primerNota = false;
    } else {
      if (nota < notaBaja) {
        notaBaja = nota;
        legajoNotaBaja = legajo;
      }
    }
    if (cod == 10) {
      examenesDiez++;
    }

    if (nota >= 6) {
      aprobados++;
    } else {
      desaprobados++;
    }

    notaTotal += nota;
    estudianteTotales++;
  }

  notaPromedio = notaTotal / estudianteTotales;
  float porcentajeAprobados = (aprobados * 100) / estudianteTotales;
  float porcentajeDesaprobados = (desaprobados * 100) / estudianteTotales;

  cout << "La nota promedio entre todos los estudiante es: " << notaPromedio
       << endl;
  cout << "El legajo del estudiante con menor nota: " << legajo << endl;
  cout << "La cantidad de exámenes rendidos para la materia 10: "
       << examenesDiez << endl;
  cout << "El porcentaje de aprobados: " << porcentajeAprobados
       << " y no aprobados: " << porcentajeDesaprobados << endl;
}