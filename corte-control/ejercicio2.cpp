// Una zapatería dispone de la información de los calzados vendidos en el primer
// cuatrimestre de 2023 en sus 10 sucursales. Por cada venta se registra:

// Sucursal (número entero)
// Mes (1 a 4)
// Tipo de calzado ('Z' - Zapatos, 'X' - Zapatillas, 'P' - Pantuflas, 'O' -
// Ojotas)
// Número de talle (entero)
// Importe (float)

// Todas las sucursales han registrado ventas. La información se encuentra
// agrupada por sucursal. Para indicar el fin de la carga de datos de una
// sucursal se ingresa un código de sucursal igual a cero. Se pide calcular e
// informar:

// Aclaraciones...
// Una venta solamente registra un tipo de calzado.
// Solamente habrá un tipo de calzado que haya totalizado la mayor cantidad de
// dinero en total en concepto de ventas.

// Se pide calcular e informar:
// A)Por cada sucursal, el promedio de importe de los calzados de talle 40.
// B)La cantidad de sucursales que vendieron zapatos pero no pantuflas.
// C)El tipo de calzado que haya totalizado más dinero en concepto de ventas
// D)Los tipos de calzados que haya vendido la sucursal número 50. Se deben
// listar los nombres de los tipos de calzados vendidos sin repetir.

#include <iostream>
using namespace std;

int main() {
  int numSucursal, numTalle, mes, numSucursalAct, cantTalle40 = 0,
                                                  cantSucursalesZapateras = 0;
  int totalZ = 0, totalP = 0, totalO = 0, totalX = 0;
  bool isTotalZ = false, isTotalP = false, isTotalO = false, istotalX = false;
  int pantuflas = 0, zapatos = 0;
  float importe, importeTalle40 = 0;
  char tipoCalzado;

  for (int i = 1; i <= 10; i++) {
    cout << "Ingrese el numero de sucursal" << endl;
    cin >> numSucursal;
    while (numSucursal != 0) {
      cout << "Ingrese el mes" << endl;
      cin >> mes;
      cout << "Ingrese el tipo de calzado" << endl;
      cin >> tipoCalzado;
      switch (tipoCalzado) {
        case 'Z':
          cout << "Ingrese el numero de talle" << endl;
          cin >> numTalle;
          cout << "Ingrese el importe" << endl;
          cin >> importe;
          totalZ += importe;

          if (numTalle = 40) {
            importeTalle40 += importe;
            cantTalle40++;
          }
          zapatos++;
          break;
        case 'X':
          cout << "Ingrese el numero de talle" << endl;
          cin >> numTalle;
          cout << "Ingrese el importe" << endl;
          cin >> importe;
          totalX += importe;

          if (numTalle = 40) {
            importeTalle40 += importe;
            cantTalle40++;
          }
          break;
        case 'P':
          cout << "Ingrese el numero de talle" << endl;
          cin >> numTalle;
          cout << "Ingrese el importe" << endl;
          cin >> importe;
          totalP += importe;

          if (numTalle = 40) {
            importeTalle40 += importe;
            cantTalle40++;
          }
          pantuflas++;
          break;
        case 'O':
          cout << "Ingrese el numero de talle" << endl;
          cin >> numTalle;
          cout << "Ingrese el importe" << endl;
          cin >> importe;
          totalO += importe;

          if (numTalle = 40) {
            importeTalle40 += importe;
            cantTalle40++;
          }
          break;
        default:
          cout << "No existe" << endl;
          break;
      }

      cout << "Ingrese el numero de sucursal" << endl;
      cin >> numSucursal;
    }
    if (totalZ > totalO && totalZ > totalP && totalZ > totalX) {
      isTotalZ = true;
    } else {
      isTotalZ = false;
    }
    if (totalX > totalO && totalX > totalP && totalX > totalP) {
      istotalX = true;
    } else {
      istotalX = false;
    }
    if (totalP > totalO && totalP > totalZ && totalP > totalX) {
      isTotalP = true;
    } else {
      isTotalP = false;
    }
    if (totalO > totalP && totalO > totalZ && totalO > totalX) {
      isTotalO = true;
    } else {
      isTotalO = false;
    }
    // Examinar los booleanos para ver cual es el mayor
    if (isTotalZ) {
      cout << "El tipo de calzado que mas vendio fue Zapatos" << endl;
    } else if (isTotalP) {
      cout << "El tipo de calzado que mas vendio fue Pantuflas" << endl;
    } else if (isTotalO) {
      cout << "El tipo de calzado que mas vendio fue Ojotas" << endl;
    } else if (istotalX) {
      cout << "El tipo de calzado que mas vendio fue Zapatillas" << endl;
    }
    cout << "Promedio importe calzado talle 40: "
         << importeTalle40 / cantTalle40 << endl;
    if (pantuflas == 0 && zapatos != 0) {
      cantSucursalesZapateras++;
      cout << "Cantidad de Zapateros: " << cantSucursalesZapateras << endl;
    } else {
      cout << "NO ES ZAPATERO" << endl;
    }
    pantuflas = 0;
    zapatos = 0;
    importeTalle40 = 0;
    cantTalle40 = 0;
  }
}