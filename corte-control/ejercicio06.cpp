// Una casa de ventas de libros con varias sucursales registró las ventas
// durante el mes anterior en un lote de registros.

// Para cada venta se registraron los siguientes datos:
// Sucursal de la venta (1 a 20)
// Número del vendedor que efectuó la venta (1 a 150)
// Día de la venta (1 a 31)
// Importe de la venta
// Tipo de Cliente ("U"= Universitario, "N"= No Universitario )
// Editorial del libro("A"= Alvarez, "B"= Benitez, "P"= Perez)
// El lote finaliza con un registro con importe igual a cero.
// Los datos se ingresan agrupados por sucursal.
// A partir de esta información se pide determinar e informar:
// a) La comisión total pagada a todos los vendedores en
//  el mes para cada sucursal.
// b) La cantidad total vendida de libros por cada
//  sucursal y discriminado por cada editorial. Se deberán mostrar tres
//  cantidades por sucursal.
// c) El número de vendedor que haya efectuado la
//  venta individual de mayor importe, informando en qué sucursal trabaja y el
//  día en que se realizó esa venta. Se esperan los datos de un único vendedor.
//  Considerar que la comisión es un 10% del importe
//  de la venta si se trata de un libro de la editorial Alvarez, un 12% para
//  Benitez y un 15% para Perez.

#include <iostream>
using namespace std;

int main() {
  int sucursal, vendedor, dia, sucursalAct,
      ventasA = 0, ventasB = 0, ventasP = 0, ventasTotal = 0, vendedorMayor,
      diaMayor, sucursalMayor;

  bool primeraVez = true;
  float importe = 0, comision = 0, comTotal = 0, importeMayor = 0;
  char tipoCliente, editorial;
  const int MAX_SUCURSAL = 4;

  cout << "Ingrese la sucursal" << endl;
  cin >> sucursal;
  cout << "Ingrese el importe" << endl;
  cin >> importe;
  cout << "Ingrese el vendedor" << endl;
  cin >> vendedor;
  cout << "Ingrese el dia" << endl;
  cin >> dia;
  cout << "Ingrese el tipo de cliente" << endl;
  cin >> tipoCliente;
  cout << "Ingrese la editorial" << endl;
  cin >> editorial;

  sucursalAct = sucursal;
  for (int i = 1; sucursalAct <= MAX_SUCURSAL; i++) {
    cout << "Iteracion numero ====> " << i << endl;
    while (importe != 0) {
      cout << "Ingrese el vendedor" << endl;
      cin >> vendedor;
      cout << "Ingrese el dia" << endl;
      cin >> dia;
      cout << "Ingrese el tipo de cliente" << endl;
      cin >> tipoCliente;
      cout << "Ingrese la editorial" << endl;
      switch (editorial) {
        case 'A':
          /* code */
          comision = 0;
          comision = importe * 0.1;
          comTotal += importe;
          ventasA++;
          break;
        case 'B':
          /* code */
          comision = 0;
          comision = importe * 0.12;
          comTotal += importe;
          ventasB++;
          break;
        case 'P':
          /* code */
          comision = 0;
          comision = importe * 0.15;
          comTotal += importe;
          ventasP++;
          break;
        default:
          break;
      }
      ventasTotal = ventasA + ventasB + ventasP;

      if (primeraVez) {
        importeMayor = importe;
        vendedorMayor = vendedor;
        diaMayor = dia;
        sucursalMayor = sucursal;
      } else if (importe > importeMayor) {
        importeMayor = importe;
        vendedorMayor = vendedor;
        diaMayor = dia;
        sucursalMayor = sucursal;
        primeraVez = false;
      }

      cout << "Ventas A: " << ventasA << endl;
      cout << "Ventas B: " << ventasB << endl;
      cout << "Ventas P: " << ventasP << endl;

      cout << "Ingrese la sucursal" << endl;
      cin >> sucursal;
      cout << "Ingrese el importe" << endl;
      cin >> importe;
    }

    ventasA = 0;
    ventasB = 0;
    ventasP = 0;
  }

  cout << "Vendedor mayor de todos: " << vendedorMayor << endl
       << "Dia mayor de todos: " << diaMayor << endl
       << "Sucursal mayor de todos: " << sucursalMayor << endl;

  return 0;
}
