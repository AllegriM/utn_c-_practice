#include <iostream>
using namespace std;
int main() {
  int NroSuc, NroArt, Cv, AntNroSuc;
  float Pu, TotalVendido;
  cout << "Ingrese numero de sucursal: ";
  cin >> NroSuc;
  cout << "Ingrese numero de articulo: ";
  cin >> NroArt;
  cout << "Ingrese la cantidad vendida: ";
  cin >> Cv;
  cout << "Ingrese el precio unitario ";
  cin >> Pu;
  while (NroSuc != 0) {
    AntNroSuc = NroSuc;
    TotalVendido = 0;
    while (AntNroSuc == NroSuc) {
      TotalVendido += Cv * Pu;
      cout << endl << endl << "Ingrese numero de sucursal: ";
      cin >> NroSuc;
      cout << "Ingrese numero de articulo: ";
      cin >> NroArt;
      cout << "Ingrese la cantidad vendida: ";
      cin >> Cv;
      cout << "Ingrese el precio unitario ";
      cin >> Pu;
    }
    cout << endl
         << endl
         << "El numero de sucursal " << AntNroSuc
         << " tuvo un importe total vendido de : " << TotalVendido;
  }
  return 0;
}