#include <iostream>
using namespace std;

int main() {
  int pointer_variable = 15;
  //   Guardo la direccion del espacio en memoria
  int* pointer_to_multiply = &pointer_variable;
  //   Agarro el valor de ese espacio en memoria
  int multiplied_number = *pointer_to_multiply * 2;

  string nombre = "Hello bro";

  cout << nombre[8] << endl;
  cout << multiplied_number << endl;
}