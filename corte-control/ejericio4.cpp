// La Cámara de Exportadores de la República Argentina dispone de las
// exportaciones
//         realizadas por algunas de las industrias del país.Por cada
//         exportación
//             se registra : -Código de
//                           industria(Número entero) -
//     Código de exportación(Número entero) -
//     Continente de destino(1 - América, 2 - Europa, 3 - Asia) -
//     Total de toneladas exportadas(float) -
//     Importe
//     total(float) La información se encuentra agrupada por código de industria
//         .Para indicar el fin de la carga de una industria se ingresa un
//         código
//     de exportación igual a cero
//         .Para indicar el fin de la carga de datos se ingresa un código de
//     industria igual a cero.
// Se pide calcular e informar
// Pts
// A) Por cada industria, el total de toneladas exportadas discriminadas por
// continente. Es decir el total de toneladas exportadas a América, Europa y
// Asia. 30 B) La cantidad de industrias que hayan exportado a Europa pero no a
// Asia. 30 C) Los códigos de continente que no hayan registrado ninguna
// exportación mayor a 40 toneladas. 20 D) El nombre del continente qué más
// dinero haya abonado en total para la industria con código 5. (20 puntos)

#include <iostream>
using namespace std;

int main() {
  int codIndustria, codExportacion, continente, codIndustriaAct,
      cantIndustriasEuropa = 0, cantIndustriasAsia = 0,
      cantIndustriasAmerica = 0;
  float totalToneladas, totalToneladasEuropa = 0, totalToneladasAsia = 0,
                        totalToneladasAmerica = 0, importeTotal,
                        importeTotalEuropa = 0, importeTotalAsia = 0,
                        importeTotalAmerica = 0;
  bool isEuropa = false, isAsia = false, isAmerica = false;
  string nombreContinente;

  cout << "Ingrese el codigo de industria" << endl;
  cin >> codIndustria;

  while (codIndustria != 0) {
    }
}