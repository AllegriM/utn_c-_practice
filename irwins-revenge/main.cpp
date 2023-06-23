// Antes de comenzar la fase de expediciOn los jugadores deberán tirar un dado
// de diez caras.

// Quien obtenga el dado menor comienza.

// Si ambos obtuvieron el mismo número deberán tirar de nuevo hasta que alguno
// de ellos obtenga el dado más chico.

// Hay cinco estatuillas, la idea es obtener la mayor cantidad y son las
// siguientes:
// Arena → Cangrejo
// Tierra → Hormiga
// Agua → Medusa
// Aire → Águila
// Fuego → Salamandra

// La Fase de ExpediciOn termina cuando no quedan estatuillas en juego.
// A partir de ese momento, comienza la Fase Final siendo el primero en tirar
// aquel jugador que haya obtenido más estatuillas.

#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <iostream>
using namespace std;

int puntosVictoriaJ1 = 0, puntosVictoriaJ2 = 0, restarPuntosVictoriaJ1 = 0,
    restarPuntosVictoriaJ2 = 0;

void exit() {
  cout << "Saliendo del juego";
};

bool verificarEscaleraCuatro(int dados[5]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4 - i; j++) {
      if (dados[j] > dados[j + 1]) {
        int temp = dados[j];
        dados[j] = dados[j + 1];
        dados[j + 1] = temp;
      }
    }
  }

  // Verificar si hay una escalera de 4 números
  int contador = 1;
  for (int i = 1; i < 5; i++) {
    if (dados[i] == dados[i - 1] + 1)
      contador++;
    else if (dados[i] != dados[i - 1])
      contador = 1;

    if (contador == 4)
      return true;
  }

  return false;
}

bool verificarEscalera(int dados[5]) {
  bool estanPresentes[6] = {false};
  // [2, 5, 3, 6, 4]
  for (int i = 0; i < 5; i++) {
    int valor = dados[i];

    if (estanPresentes[valor - 1]) {
      return false;
    }

    estanPresentes[valor - 1] = true;
  }
  int contador = 0;
  for (int i = 0; i < 6; i++) {
    if (estanPresentes[i]) {
      contador++;
      if (contador == 5) {
        return true;  // Hay 5 valores consecutivos, es una escalera
      }
    } else {
      contador = 0;
    }
  }

  return false;
}

int lanzarUnDado() {
  int dado;

  srand(time(NULL));

  // Hago la tirada del dado y obtengo un numero
  dado = 1 + rand() % (11 - 1);

  return dado;
}

void lanzarDosDados(int dados[]) {
  const int CANT_DADOS = 2;

  srand(time(NULL));

  for (int i = 0; i < CANT_DADOS; i++) {
    // Hago la tirada del dado y obtengo un numero
    dados[i] = 1 + rand() % (11 - 1);
  }
}

void lanzarTresDados(int dados[]) {
  const int CANT_DADOS = 3;

  srand(time(NULL));

  for (int i = 0; i < CANT_DADOS; i++) {
    // Hago la tirada del dado y obtengo un numero
    dados[i] = 1 + rand() % (11 - 1);
  }
}

void lanzarCincoDados(int dados[]) {
  const int CANT_DADOS = 5;

  srand(time(NULL));

  for (int i = 0; i < CANT_DADOS; i++) {
    // Hago la tirada del dado y obtengo un numero
    dados[i] = 1 + rand() % (11 - 1);
  }
}

void lanzarCincoDados6Caras(int dados[]) {
  const int CANT_DADOS = 5;

  srand(time(NULL));

  for (int i = 0; i < CANT_DADOS; i++) {
    // Hago la tirada del dado y obtengo un numero
    dados[i] = 1 + rand() % (7 - 1);
  }
}

void faseFinal(string** estatuillasJ1,
               string** estatuillasJ2,
               int restarPuntosVictoriaJ1,
               int restarPuntosVictoriaJ2,
               string jugador1,
               string jugador2,
               bool turnoJugador1) {
  int opcion, numeroCambiasso, numeroEliminado, numeroNuevo, numeroHormiga,
      opcionHormiga;
  bool escaleraEncontrada = false, beneficioCangrejo = true,
       bendicionHormigaJ1 = false, bendicionHormigaJ2 = false,
       poseeEstatuillasJ1 = true, poseeEstatuillasJ2 = true;
  int dados[5] = {};

  for (int i = 0; i <= 4; i++) {
    if (*estatuillasJ1[i] == "Hormiga") {
      cout << "El jugador " << jugador1 << " tiene la estatuilla de Hormiga"
           << endl;
      cout << jugador1
           << " elegi un numero y luego en cada tirada cambiar un numero "
              "aleatorio por ese mismo."
           << endl;
      cout << "Ingrese el numero x el que va a poder cambiar en la fase "
              "final: ";
      cin >> numeroCambiasso;
      bendicionHormigaJ1 = true;
    } else if (*estatuillasJ2[i] == "Hormiga") {
      cout << "El jugador " << jugador2 << " tiene la estatuilla de Hormiga"
           << endl;
      cout << jugador2
           << " elegi un numero y luego en cada tirada podes cambiar un numero "
              "aleatorio por ese mismo."
           << endl;
      cout << "Ingrese el numero x el que va a poder cambiar en la fase "
              "final: ";
      cin >> numeroCambiasso;
      bendicionHormigaJ2 = true;
    }
  }

  cout << "---------- FASE FINAL ------------" << endl;
  cout << jugador1 << setw(20) << jugador2 << endl;
  cout << "ESTATUILLAS: " << setw(21) << "ESTATUILLAS: " << endl;
  for (int i = 0; i <= 4; i++) {
    cout << *estatuillasJ1[i] << setw(30) << *estatuillasJ2[i] << endl;
  }

  cout << "---------- COMIENZO FASE FINAL ------------" << endl;

  while (escaleraEncontrada == false) {
    if (turnoJugador1) {
      cout << "Turno de " << jugador1 << endl;

      lanzarCincoDados6Caras(dados);

      for (int i = 0; i < 5; i++) {
        cout << dados[i] << " ";
      };
      cout << endl;

      bool tengoEscalera = verificarEscalera(dados);

      if (tengoEscalera) {
        cout << "Tenes escalera! GANASTE LA FASE FINAL" << endl;
        if (poseeEstatuillasJ1) {
          puntosVictoriaJ1 += 10;
        } else {
          puntosVictoriaJ1 += 50;
        }
        escaleraEncontrada = true;
      }

      if (bendicionHormigaJ1) {
        cout << "Al tener la estatuilla Hormiga podes cambiar un numero por el "
                "numero que elegiste antes."
             << endl;
        cout << "Queres cambiar algun numero por el " << numeroCambiasso
             << "? (1 = si 0 = no) " << endl;
        cin >> opcionHormiga;
        if (opcionHormiga == 1) {
          cout
              << "Elegi la posicion del numero que queres cambiar: 1) 2) 3) 4) "
                 "5) por el numero "
              << numeroCambiasso << endl;
          for (int i = 0; i < 5; i++) {
            cout << i + 1 << ") " << dados[i] << endl;
          }
          cin >> numeroHormiga;
          dados[numeroHormiga - 1] = numeroCambiasso;
        } else if (opcionHormiga == 0) {
          cout << "No cambias ningun numero" << endl;
        }
      }

      for (int i = 0; i < 5; i++) {
        if (*estatuillasJ1[i] == "Cangrejo" && beneficioCangrejo &&
            !tengoEscalera) {
          cout << "Tenes la estatuilla de Cangrejo, podes tirar los dados "
                  "otra vez mas SOLO POR ESTE TURNO."
               << endl;
          cout << "¿Queres tirar los dados otra vez? (1 = si, 0 = no)" << endl;
          cin >> opcion;
          if (opcion == 1) {
            lanzarCincoDados6Caras(dados);
            for (int i = 0; i < 5; i++) {
              cout << dados[i] << " ";
            };
            cout << endl;
            bool tengoEscalera = verificarEscalera(dados);
            if (tengoEscalera) {
              cout << "Tenes escalera! GANASTE LA FASE FINAL" << endl;
              if (poseeEstatuillasJ1) {
                puntosVictoriaJ1 += 10;
              } else {
                puntosVictoriaJ1 += 50;
              }
              escaleraEncontrada = true;
            }
            beneficioCangrejo = false;
          } else if (opcion == 0) {
            beneficioCangrejo = false;
          }
        }
        if (*estatuillasJ1[i] == "Aguila" && !tengoEscalera) {
          // Permite cambiar un dado por otro
          cout << "Tenes la estatuilla de Aguila, podes cambiar un dado por "
                  "otro."
               << endl;
          cout << "¿Queres cambiar uno de los dados? (1 = si, 0 = no) ";
          cin >> opcion;
          if (opcion == 1) {
            cout << "¿Que dado queres cambiar? Seleccione la posicion 1) 2) "
                    "3) "
                    "4) 5)"
                 << endl;
            for (int i = 0; i < 5; i++) {
              cout << i + 1 << ") " << dados[i] << endl;
            }
            cin >> numeroEliminado;
            cout << "Se va a cambiar el dado " << dados[numeroEliminado - 1]
                 << " por: ";
            cin >> numeroNuevo;
            dados[numeroEliminado - 1] = numeroNuevo;
            bool esEscalera = verificarEscalera(dados);
            if (*estatuillasJ1[i] == "Salamandra") {
              bool esEscaleraCuatro = verificarEscaleraCuatro(dados);
              if (esEscaleraCuatro) {
                cout << "Tenes escalera! GANASTE LA FASE FINAL" << endl;
                if (poseeEstatuillasJ1) {
                  puntosVictoriaJ1 += 10;
                } else {
                  puntosVictoriaJ1 += 50;
                }
                escaleraEncontrada = true;
              }
            }
            if (tengoEscalera) {
              cout << "Tenes escalera! GANASTE LA FASE FINAL" << endl;
              if (poseeEstatuillasJ1) {
                puntosVictoriaJ1 += 10;
              } else {
                puntosVictoriaJ1 += 50;
              }
              escaleraEncontrada = true;
            }
          } else if (opcion == 0) {
            cout << "No se cambia ningun dado." << endl;
          }
        }
        if (*estatuillasJ1[i] == "Medusa" &&
            (dados[0] && dados[1] == dados[0] && dados[2] == dados[0] &&
             dados[3] == dados[0] && dados[4] == dados[0] &&
             dados[5] == dados[0]) &&
            !tengoEscalera) {
          cout << "Al tener la estatuilla de Medusa y formaste una escalera de "
                  "5 dados iguales"
               << endl;
          tengoEscalera = true;
          if (tengoEscalera) {
            cout << "Tenes escalera! GANASTE LA FASE FINAL" << endl;
            if (poseeEstatuillasJ1) {
              puntosVictoriaJ1 += 10;
            } else {
              puntosVictoriaJ1 += 50;
            }
            escaleraEncontrada = true;
          }
        }
        if (*estatuillasJ1[i] == "Salamandra" && !tengoEscalera) {
          bool esEscalera = verificarEscaleraCuatro(dados);
          if (esEscalera) {
            cout
                << "Al tener la estatuilla de Salamandra, ganaste la fase "
                   "final con una escalera de 4 dados consecutivos entre los 5 "
                   "dados."
                << endl;
            escaleraEncontrada = true;
          }
        }
      }

      tengoEscalera = verificarEscalera(dados);

      if (tengoEscalera) {
        cout << "Tenes escalera! GANASTE LA FASE FINAL" << endl;
        if (poseeEstatuillasJ1) {
          puntosVictoriaJ1 += 10;
        } else {
          puntosVictoriaJ1 += 50;
        }
        escaleraEncontrada = true;
      }

      puntosVictoriaJ1 -= 1;
      turnoJugador1 = false;
      system("pause");
    } else {
      cout << "Turno de " << jugador2 << endl;

      lanzarCincoDados6Caras(dados);

      for (int i = 0; i < 5; i++) {
        cout << dados[i] << " ";
      };
      cout << endl;

      bool tengoEscalera = verificarEscalera(dados);

      if (tengoEscalera) {
        cout << "Tenes escalera! GANASTE LA FASE FINAL" << endl;
        if (poseeEstatuillasJ2) {
          puntosVictoriaJ2 += 10;
        } else {
          puntosVictoriaJ2 += 50;
        }
        escaleraEncontrada = true;
      }

      if (bendicionHormigaJ2) {
        cout << "Al tener la estatuilla Hormiga podes cambiar un numero por el "
                "numero que elegiste antes."
             << endl;
        cout << "Queres cambiar algun numero por el " << numeroCambiasso
             << "? (1 = si 0 = no)" << endl;
        cin >> opcionHormiga;
        if (opcionHormiga == 1) {
          cout
              << "Elegi la posicion del numero que queres cambiar: 1) 2) 3) 4) "
                 "5) por el numero "
              << numeroCambiasso << endl;
          for (int i = 0; i < 5; i++) {
            cout << i + 1 << ") " << dados[i] << endl;
          }
          cin >> numeroHormiga;
          dados[numeroHormiga - 1] = numeroCambiasso;
        } else if (opcionHormiga == 0) {
          cout << "No cambias ningun numero" << endl;
        }
      }

      for (int i = 0; i < 5; i++) {
        if (*estatuillasJ2[i] == "Cangrejo" && beneficioCangrejo &&
            !tengoEscalera) {
          cout << "Tenes la estatuilla de Cangrejo, podes tirar los dados "
                  "otra vez mas SOLO POR ESTE TURNO."
               << endl;
          cout << "¿Queres tirar los dados otra vez? (1 = si, 0 = no)" << endl;
          cin >> opcion;
          if (opcion == 1) {
            lanzarCincoDados6Caras(dados);
            for (int i = 0; i < 5; i++) {
              cout << dados[i] << " ";
            };
            cout << endl;
            bool tengoEscalera = verificarEscalera(dados);
            beneficioCangrejo = false;
          } else if (opcion == 0) {
            beneficioCangrejo = false;
          }
        }
        if (*estatuillasJ2[i] == "Medusa" &&
            (dados[0] && dados[1] == dados[0] && dados[2] == dados[0] &&
             dados[3] == dados[0] && dados[4] == dados[0] &&
             dados[5] == dados[0]) &&
            !tengoEscalera) {
          cout << "Al tener la estatuilla de Medusa y formaste una escalera de "
                  "5 dados iguales"
               << endl;
          tengoEscalera = true;
          if (tengoEscalera) {
            cout << "Tenes escalera! GANASTE LA FASE FINAL" << endl;
            if (poseeEstatuillasJ2) {
              puntosVictoriaJ2 += 10;
            } else {
              puntosVictoriaJ2 += 50;
            }
            escaleraEncontrada = true;
          }
        }
        if (*estatuillasJ2[i] == "Aguila" && !tengoEscalera) {
          // Permite cambiar un dado por otro
          cout << "Tenes la estatuilla de Aguila, podes cambiar un dado por "
                  "otro."
               << endl;
          cout << "¿Queres cambiar uno de los dados? (1 = si, 0 = no)";
          cin >> opcion;
          cout << endl;
          if (opcion == 1) {
            cout << "¿Que dado queres cambiar? Seleccione la posicion 1) 2) "
                    "3) "
                    "4) 5)"
                 << endl;
            for (int i = 0; i < 5; i++) {
              cout << i + 1 << ") " << dados[i] << endl;
            }
            cin >> numeroEliminado;
            cout << "Se va a cambiar el dado " << dados[numeroEliminado - 1]
                 << " por: ";
            cin >> numeroNuevo;
            cout << endl;
            dados[numeroEliminado - 1] = numeroNuevo;
            bool tengoEscalera = verificarEscalera(dados);
          } else if (opcion == 0) {
            cout << "No se cambia ningun dado." << endl;
            system("pause");
          }
        }
        if (*estatuillasJ2[i] == "Salamandra" && !tengoEscalera) {
          bool esEscalera = verificarEscaleraCuatro(dados);
          if (esEscalera) {
            cout
                << "Al tener la estatuilla de Salamandra, ganaste la fase "
                   "final con una escalera de 4 dados consecutivos entre los 5 "
                   "dados."
                << endl;
            cout << "Tenes escalera! GANASTE LA FASE FINAL" << endl;
            if (poseeEstatuillasJ2) {
              puntosVictoriaJ2 += 10;
            } else {
              puntosVictoriaJ2 += 50;
            }
            escaleraEncontrada = true;
          }
        }
      }

      tengoEscalera = verificarEscalera(dados);

      if (tengoEscalera) {
        cout << "Tenes escalera! GANASTE LA FASE FINAL" << endl;
        if (poseeEstatuillasJ1) {
          puntosVictoriaJ1 += 10;
        } else {
          puntosVictoriaJ1 += 50;
        }
        escaleraEncontrada = true;
      }
      puntosVictoriaJ2 -= 1;
      turnoJugador1 = true;
      system("pause");
    }
  }
}

void startGame() {
  int NUM_ESTATUILLAS = 5, contadorEstatuillasObtenidas = 0,
      contadorMaldicionMedusa = 0, contadorMaldicionAguila = 0;
  string jugador1, jugador2;
  string *jugador1Estatuillas[5] = {}, *jugador2Estatuillas[5] = {};
  int opcion, dadosFaseFinal[5] = {}, dadosExpedicion[2] = {},
              dadoOrdenJugadores[2] = {}, puntosMaldicionCangrejo = 0,
              puntosMaldicionHormiga[3] = {}, tresDados[3] = {};
  bool estatuillasDisponibles[NUM_ESTATUILLAS] = {true, true, true, true, true};
  string estatuillas[NUM_ESTATUILLAS] = {"Hormiga", "Cangrejo", "Medusa",
                                         "Aguila", "Salamandra"};
  bool turnoJugador1 = false, maldicionMedusaJ1 = false,
       maldicionMedusaJ2 = false, maldicionAguila = false,
       maldicionAguilaJ1 = false, maldicionAguilaJ2 = false,
       maldicionSalamandraJ1 = false, maldicionSalamandraJ2 = false,
       primeraVez = false, admin = false;

  bool primerIntentoHormigaJ1 = true, primerIntentoHormigaJ2 = true,
       primerIntentoCangrejoJ1 = true, primerIntentoCangrejoJ2 = true,
       primerIntentoMedusaJ1 = true, primerIntentoMedusaJ2 = true,
       primerIntentoAguilaJ1 = true, primerIntentoAguilaJ2 = true,
       primerIntentoSalamandraJ1 = true, primerIntentoSalamandraJ2 = true;

  for (int i = 0; i < NUM_ESTATUILLAS; i++) {
    jugador1Estatuillas[i] = new string("");
    jugador2Estatuillas[i] = new string("");
  }

  cout << "Ingrese el nombre del jugador numero 1: ";
  cin >> jugador1;

  if (jugador1 == "LAB1" || jugador1 == "lab1") {
    admin = true;
  }

  cout << "Ingrese el nombre del jugador numero 2: ";
  cin >> jugador2;

  // SORTEO ORDEN JUGADORES

  lanzarDosDados(dadoOrdenJugadores);
  cout << jugador1 << " lanza un dado y sale: " << dadoOrdenJugadores[0]
       << endl;
  cout << jugador2 << " lanza un dado y sale: " << dadoOrdenJugadores[1]
       << endl;

  while (dadoOrdenJugadores[0] == dadoOrdenJugadores[1]) {
    cout << "Se repite porque fue empate" << endl;
    system("pause");
    lanzarDosDados(dadoOrdenJugadores);
    cout << jugador1 << " lanza un dado y sale: " << dadoOrdenJugadores[0]
         << endl;
    cout << jugador2 << " lanza un dado y sale: " << dadoOrdenJugadores[1]
         << endl;
  }

  if (dadoOrdenJugadores[0] < dadoOrdenJugadores[1]) {
    cout << "El primero en jugar es " << jugador1 << endl;
    turnoJugador1 = true;
  } else if (dadoOrdenJugadores[1] < dadoOrdenJugadores[0]) {
    cout << "El primero en jugar es " << jugador2 << endl;
    turnoJugador1 = false;
  }

  system("pause");

  //  FASE DE EXPEDICION
  cout << "\n IRWIN'S REVENGE - FASE DE EXPEDICION \n "
          "----------------------------------------------------------------"
          "----"
       << endl;

  while (contadorEstatuillasObtenidas != 5) {
    cout << jugador1 << setw(20) << jugador2 << endl;
    cout << "ESTATUILLAS: " << setw(21) << "ESTATUILLAS: " << endl;

    for (int i = 0; i <= 4; i++) {
      if (*jugador1Estatuillas[i] != "") {
        cout << *jugador1Estatuillas[i] << endl;
      }
    }

    for (int i = 0; i <= 4; i++) {
      if (*jugador2Estatuillas[i] != "") {
        cout << setw(30) << *jugador2Estatuillas[i] << endl;
      }
    }

    cout << "\n\n ---------------------- \n\n" << endl;

    if ((maldicionMedusaJ1 || maldicionMedusaJ2) &&
        contadorMaldicionMedusa == 3) {
      maldicionMedusaJ1 = false;
      maldicionMedusaJ2 = false;
    }

    if (maldicionMedusaJ1) {
      turnoJugador1 = false;
    } else if (maldicionMedusaJ2) {
      turnoJugador1 = true;
    }

    if (maldicionMedusaJ1 || maldicionMedusaJ2) {
      contadorMaldicionAguila = 0;
      contadorMaldicionMedusa++;
    }

    if ((!maldicionMedusaJ1 && !maldicionMedusaJ2) && maldicionAguila &&
        !primeraVez && contadorMaldicionAguila < 2) {
      contadorMaldicionAguila++;
    } else if (maldicionAguila && contadorMaldicionAguila == 2) {
      contadorMaldicionAguila = 0;
    }

    if (maldicionAguilaJ1 && primeraVez && contadorMaldicionAguila == 0) {
      turnoJugador1 = false;
      primeraVez = false;
      contadorMaldicionAguila++;
    } else if (maldicionAguilaJ1 && !primeraVez &&
               contadorMaldicionAguila == 0) {
      turnoJugador1 = true;
    } else if (maldicionAguilaJ1 && !primeraVez &&
               contadorMaldicionAguila != 0) {
      turnoJugador1 = false;
    }

    if (maldicionAguilaJ2 && primeraVez && contadorMaldicionAguila == 0) {
      turnoJugador1 = true;
      primeraVez = false;
      contadorMaldicionAguila++;
    } else if (maldicionAguilaJ2 && !primeraVez &&
               contadorMaldicionAguila == 0) {
      turnoJugador1 = false;
    } else if (maldicionAguilaJ2 && !primeraVez &&
               contadorMaldicionAguila != 0) {
      turnoJugador1 = true;
    }

    // ORDEN TURNOS
    if (turnoJugador1) {
      cout << "---> TURNO DE: " << jugador1 << endl;
    } else {
      cout << "---> TURNO DE: " << jugador2 << endl;
    }

    for (int i = 0; i < NUM_ESTATUILLAS; i++) {
      if (estatuillasDisponibles[i]) {
        cout << i + 1 << ") " << estatuillas[i] << endl;
      }
    };

    cout << "Seleccione la estatuilla que quiere escoger: ";
    cin >> opcion;

    switch (opcion) {
      case 1:
        if (estatuillasDisponibles[0]) {
          cout << "ESTATUILLA OBJETIVO: Hormiga" << endl;
          cout << "CONDICION DE OBTENCION: Al menos dos dados deben ser "
                  "menores a "
                  "5."
               << endl;
          if (!turnoJugador1 && maldicionSalamandraJ1) {
            if (admin) {
              cin >> tresDados[0] >> tresDados[1] >> tresDados[2];
            } else {
              lanzarTresDados(tresDados);
            }
            cout << "DADO 1: " << tresDados[0] << endl;
            cout << "DADO 2: " << tresDados[1] << endl;
            cout << "DADO 3: " << tresDados[2] << endl;
            if ((tresDados[0] < 5 && tresDados[1] < 5) ||
                (tresDados[1] < 5 && tresDados[2] < 5) ||
                (tresDados[0] < 5 && tresDados[2] < 5)) {
              jugador2Estatuillas[0] = new string("Hormiga");
              cout << "Ganaste la estatuilla de Hormiga" << endl;
              cout << jugador1
                   << " tira tres dados de diez caras y el valor obtenido son "
                      "los puntos de victoria que le descuenta a "
                   << jugador2 << " al final de la partida." << endl;
              system("pause");
              lanzarTresDados(puntosMaldicionHormiga);
              cout << "Se le descontaran "
                   << puntosMaldicionHormiga[0] + puntosMaldicionHormiga[1] +
                          puntosMaldicionHormiga[2]
                   << " puntos de victoria a " << jugador2 << endl;
              restarPuntosVictoriaJ2 += puntosMaldicionHormiga[0] +
                                        puntosMaldicionHormiga[1] +
                                        puntosMaldicionHormiga[2];
              estatuillasDisponibles[0] = false;
              contadorEstatuillasObtenidas++;
              if (primerIntentoHormigaJ2) {
                puntosVictoriaJ2 += 10;
                puntosVictoriaJ1 -= 3;
              } else {
                puntosVictoriaJ2 += 5;
                puntosVictoriaJ1 -= 3;
              }
            }
          } else if (turnoJugador1 && maldicionSalamandraJ2) {
            if (admin) {
              cin >> tresDados[0] >> tresDados[1] >> tresDados[2];
            } else {
              lanzarTresDados(tresDados);
            }
            cout << "DADO 1: " << tresDados[0] << endl;
            cout << "DADO 2: " << tresDados[1] << endl;
            cout << "DADO 3: " << tresDados[2] << endl;
            if ((tresDados[0] < 5 && tresDados[1] < 5) ||
                (tresDados[1] < 5 && tresDados[2] < 5) ||
                (tresDados[0] < 5 && tresDados[2] < 5)) {
              jugador1Estatuillas[0] = new string("Hormiga");
              cout << "Ganaste la estatuilla de Hormiga" << endl;
              cout << jugador2
                   << " tira tres dados de diez caras y el valor obtenido son "
                      "los puntos de victoria que le descuenta a "
                   << jugador1 << " al final de la partida." << endl;
              system("pause");
              lanzarTresDados(puntosMaldicionHormiga);
              cout << "Se le descontaran "
                   << puntosMaldicionHormiga[0] + puntosMaldicionHormiga[1] +
                          puntosMaldicionHormiga[2]
                   << " puntos de victoria a " << jugador1 << endl;
              restarPuntosVictoriaJ1 += puntosMaldicionHormiga[0] +
                                        puntosMaldicionHormiga[1] +
                                        puntosMaldicionHormiga[2];
              estatuillasDisponibles[0] = false;
              contadorEstatuillasObtenidas++;
              if (primerIntentoHormigaJ1) {
                puntosVictoriaJ1 += 10;
                puntosVictoriaJ2 -= 3;
              } else {
                puntosVictoriaJ1 += 5;
                puntosVictoriaJ2 -= 3;
              }
            }
          } else {
            if (admin) {
              cin >> dadosExpedicion[0] >> dadosExpedicion[1];
            } else {
              lanzarDosDados(dadosExpedicion);
            }
            cout << "DADO 1: " << dadosExpedicion[0] << endl;
            cout << "DADO 2: " << dadosExpedicion[1] << endl;
            if (dadosExpedicion[0] < 5 && dadosExpedicion[1] < 5) {
              cout << "Ganaste la estatuilla de Hormiga" << endl;
              if (turnoJugador1) {
                jugador1Estatuillas[0] = new string("Hormiga");
                cout << jugador2
                     << " tira dos dados de diez caras y el valor "
                        "obtenido "
                        "son los puntos de victoria que le descuenta a "
                     << jugador1 << " al final de la partida." << endl;
                system("pause");
                lanzarDosDados(puntosMaldicionHormiga);

                cout << "Se le descontaran "
                     << puntosMaldicionHormiga[0] + puntosMaldicionHormiga[1]
                     << " puntos de victoria a " << jugador1 << endl;
                restarPuntosVictoriaJ1 +=
                    puntosMaldicionHormiga[0] + puntosMaldicionHormiga[1];
                if (primerIntentoHormigaJ1) {
                  puntosVictoriaJ1 += 10;
                  puntosVictoriaJ2 -= 3;

                } else {
                  puntosVictoriaJ1 += 5;
                  puntosVictoriaJ2 -= 3;
                }
              } else {
                jugador2Estatuillas[0] = new string("Hormiga");
                cout << jugador1
                     << " tira dos dados de diez caras y el valor "
                        "obtenido "
                        "son los puntos de victoria que le descuenta a "
                     << jugador2 << " al final de la partida." << endl;
                system("pause");
                lanzarDosDados(puntosMaldicionHormiga);
                cout << "Se le descontaran "
                     << puntosMaldicionHormiga[0] + puntosMaldicionHormiga[1]
                     << " puntos de victoria a " << jugador2 << endl;
                restarPuntosVictoriaJ2 +=
                    puntosMaldicionHormiga[0] + puntosMaldicionHormiga[1];
                if (primerIntentoHormigaJ2) {
                  puntosVictoriaJ2 += 10;
                  puntosVictoriaJ1 -= 3;
                } else {
                  puntosVictoriaJ2 += 5;
                  puntosVictoriaJ1 -= 3;
                }
              }
              estatuillasDisponibles[0] = false;
              contadorEstatuillasObtenidas++;
            }
          };
          if (turnoJugador1) {
            primerIntentoHormigaJ1 = false;
            turnoJugador1 = false;
          } else {
            primerIntentoHormigaJ2 = false;
            turnoJugador1 = true;
          }
        }
        break;
      case 2:
        if (estatuillasDisponibles[1]) {
          cout << "ESTATUILLA OBJETIVO: Cangrejo" << endl;
          cout << "CONDICION DE OBTENCION: Uno de sus dados debe ser "
                  "par "
                  "y otro "
                  "de "
                  "sus dados impar."
               << endl;
          if (!turnoJugador1 && maldicionSalamandraJ1) {
            if (admin) {
              cin >> tresDados[0] >> tresDados[1] >> tresDados[2];
            } else {
              lanzarTresDados(tresDados);
            }
            cout << "DADO 1: " << tresDados[0] << endl;
            cout << "DADO 2: " << tresDados[1] << endl;
            cout << "DADO 3: " << tresDados[2] << endl;
            if ((tresDados[0] % 2 != 0 && tresDados[1] % 2 == 0) ||
                (tresDados[0] % 2 == 0 && tresDados[1] % 2 != 0) ||
                (tresDados[0] % 2 != 0 && tresDados[2] % 2 == 0) ||
                (tresDados[0] % 2 == 0 && tresDados[2] % 2 != 0) ||
                (tresDados[1] % 2 != 0 && tresDados[2] % 2 == 0) ||
                (tresDados[1] % 2 == 0 && tresDados[2] % 2 != 0)) {
              cout << "Ganaste la estatuilla de Cangrejo" << endl;
              jugador2Estatuillas[1] = new string("Cangrejo");
              cout << jugador1
                   << " tira un dado de diez caras y el valor obtenido "
                      "son los puntos de victoria que le descuenta a "
                   << jugador2 << " al final de la partida." << endl;
              system("pause");
              puntosMaldicionCangrejo = lanzarUnDado();
              cout << "Se le descontaran " << puntosMaldicionCangrejo
                   << " puntos de victoria a " << jugador2 << endl;
              restarPuntosVictoriaJ2 += puntosMaldicionCangrejo;
              estatuillasDisponibles[1] = false;
              contadorEstatuillasObtenidas++;
              if (primerIntentoCangrejoJ2) {
                puntosVictoriaJ2 += 10;
                puntosVictoriaJ1 -= 3;

              } else {
                puntosVictoriaJ2 += 5;
                puntosVictoriaJ1 -= 3;
              }
            }
          } else if (turnoJugador1 && maldicionSalamandraJ2) {
            if (admin) {
              cin >> tresDados[0] >> tresDados[1] >> tresDados[2];
            } else {
              lanzarTresDados(tresDados);
            }
            cout << "DADO 1: " << tresDados[0] << endl;
            cout << "DADO 2: " << tresDados[1] << endl;
            cout << "DADO 3: " << tresDados[2] << endl;
            if ((tresDados[0] % 2 != 0 && tresDados[1] % 2 == 0) ||
                (tresDados[0] % 2 == 0 && tresDados[1] % 2 != 0) ||
                (tresDados[0] % 2 != 0 && tresDados[2] % 2 == 0) ||
                (tresDados[0] % 2 == 0 && tresDados[2] % 2 != 0) ||
                (tresDados[1] % 2 != 0 && tresDados[2] % 2 == 0) ||
                (tresDados[1] % 2 == 0 && tresDados[2] % 2 != 0)) {
              cout << "Ganaste la estatuilla de Cangrejo" << endl;
              jugador1Estatuillas[1] = new string("Cangrejo");
              cout << jugador2
                   << " tira un dado de diez caras y el valor obtenido "
                      "son los puntos de victoria que le descuenta a "
                   << jugador1 << " al final de la partida." << endl;
              system("pause");
              puntosMaldicionCangrejo = lanzarUnDado();
              cout << "Se le descontaran " << puntosMaldicionCangrejo
                   << " puntos de victoria a " << jugador1 << endl;
              restarPuntosVictoriaJ1 += puntosMaldicionCangrejo;
              estatuillasDisponibles[1] = false;
              contadorEstatuillasObtenidas++;
              if (primerIntentoCangrejoJ1) {
                puntosVictoriaJ1 += 10;
                puntosVictoriaJ2 -= 3;
              } else {
                puntosVictoriaJ1 += 5;
                puntosVictoriaJ2 -= 3;
              }
            }
          } else {
            if (admin) {
              cin >> dadosExpedicion[0] >> dadosExpedicion[1];
            } else {
              lanzarDosDados(dadosExpedicion);
            }
            cout << "DADO 1: " << dadosExpedicion[0] << endl;
            cout << "DADO 2: " << dadosExpedicion[1] << endl;
            if ((dadosExpedicion[0] % 2 != 0 && dadosExpedicion[1] % 2 == 0) ||
                (dadosExpedicion[0] % 2 == 0 && dadosExpedicion[1] % 2 != 0)) {
              if (turnoJugador1) {
                jugador1Estatuillas[1] = new string("Cangrejo");
                cout << jugador2
                     << " tira un dado de diez caras y el valor obtenido "
                        "son los puntos de victoria que le descuenta a "
                     << jugador1 << " al final de la partida." << endl;
                system("pause");
                puntosMaldicionCangrejo = lanzarUnDado();
                cout << "Se le descontaran " << puntosMaldicionCangrejo
                     << " puntos de victoria a " << jugador1 << endl;
                restarPuntosVictoriaJ1 += puntosMaldicionCangrejo;
                if (primerIntentoCangrejoJ1) {
                  puntosVictoriaJ1 += 10;
                  puntosVictoriaJ2 -= 3;

                } else {
                  puntosVictoriaJ1 += 5;
                  puntosVictoriaJ2 -= 3;
                }
              } else {
                jugador2Estatuillas[1] = new string("Cangrejo");
                cout << jugador1
                     << " tira un dado de diez caras y el valor obtenido "
                        "son los puntos de victoria que le descuenta a "
                     << jugador2 << " al final de la partida." << endl;
                system("pause");
                puntosMaldicionCangrejo = lanzarUnDado();
                cout << "Se le descontaran " << puntosMaldicionCangrejo
                     << " puntos de victoria a " << jugador2 << endl;
                restarPuntosVictoriaJ2 += puntosMaldicionCangrejo;
                if (primerIntentoCangrejoJ2) {
                  puntosVictoriaJ2 += 10;
                  puntosVictoriaJ1 -= 3;

                } else {
                  puntosVictoriaJ2 += 5;
                  puntosVictoriaJ1 -= 3;
                }
              }
              estatuillasDisponibles[1] = false;
              contadorEstatuillasObtenidas++;
            }
          };
          if (turnoJugador1) {
            primerIntentoCangrejoJ1 = false;
            turnoJugador1 = false;
          } else {
            primerIntentoCangrejoJ2 = false;
            turnoJugador1 = true;
          }
        }
        break;
      case 3:
        if (estatuillasDisponibles[2]) {
          cout << "ESTATUILLA OBJETIVO: Medusa" << endl;
          cout << "CONDICION DE OBTENCION: La suma de dos de los dados "
                  "lanzados "
                  "debe dar exactamente siete."
               << endl;
          if (!turnoJugador1 && maldicionSalamandraJ1) {
            if (admin) {
              cin >> tresDados[0] >> tresDados[1] >> tresDados[2];
            } else {
              lanzarTresDados(tresDados);
            }
            cout << "DADO 1: " << tresDados[0] << endl;
            cout << "DADO 2: " << tresDados[1] << endl;
            cout << "DADO 3: " << tresDados[2] << endl;
            if ((tresDados[0] + tresDados[1] == 7) ||
                (tresDados[0] + tresDados[2] == 7) ||
                (tresDados[1] + tresDados[2] == 7)) {
              cout << "Ganaste la estatuilla de Medusa" << endl;
              jugador2Estatuillas[2] = new string("Medusa");
              maldicionMedusaJ2 = true;
              estatuillasDisponibles[2] = false;
              contadorEstatuillasObtenidas++;
              if (primerIntentoMedusaJ2) {
                puntosVictoriaJ2 += 10;
                puntosVictoriaJ1 -= 3;

              } else {
                puntosVictoriaJ2 += 5;
                puntosVictoriaJ1 -= 3;
              }
            }
          } else if (turnoJugador1 && maldicionSalamandraJ2) {
            if (admin) {
              cin >> tresDados[0] >> tresDados[1] >> tresDados[2];
            } else {
              lanzarTresDados(tresDados);
            }
            cout << "DADO 1: " << tresDados[0] << endl;
            cout << "DADO 2: " << tresDados[1] << endl;
            cout << "DADO 3: " << tresDados[2] << endl;
            if ((tresDados[0] + tresDados[1] == 7) ||
                (tresDados[0] + tresDados[2] == 7) ||
                (tresDados[1] + tresDados[2] == 7)) {
              cout << "Ganaste la estatuilla de Medusa" << endl;
              jugador1Estatuillas[2] = new string("Medusa");
              maldicionMedusaJ1 = true;
              estatuillasDisponibles[2] = false;
              contadorEstatuillasObtenidas++;
              if (primerIntentoMedusaJ1) {
                puntosVictoriaJ1 += 10;
                puntosVictoriaJ2 -= 3;

              } else {
                puntosVictoriaJ1 += 5;
                puntosVictoriaJ2 -= 3;
              }
            }
          } else {
            if (admin) {
              cin >> dadosExpedicion[0] >> dadosExpedicion[1];
            } else {
              lanzarDosDados(dadosExpedicion);
            }
            cout << "DADO 1: " << dadosExpedicion[0] << endl;
            cout << "DADO 2: " << dadosExpedicion[1] << endl;
            if (dadosExpedicion[0] + dadosExpedicion[1] == 7) {
              cout << "Ganaste la estatuilla de Medusa" << endl;
              if (turnoJugador1) {
                // El jugador pierde turno x 3 rondas
                jugador1Estatuillas[2] = new string("Medusa");
                maldicionMedusaJ1 = true;
                if (primerIntentoMedusaJ1) {
                  puntosVictoriaJ1 += 10;
                  puntosVictoriaJ2 -= 3;

                } else {
                  puntosVictoriaJ1 += 5;
                  puntosVictoriaJ2 -= 3;
                }
              } else {
                // El jugador pierde turno x 3 rondas
                jugador2Estatuillas[2] = new string("Medusa");
                maldicionMedusaJ2 = true;
                if (primerIntentoMedusaJ2) {
                  puntosVictoriaJ2 += 10;
                  puntosVictoriaJ1 -= 3;

                } else {
                  puntosVictoriaJ2 += 5;
                  puntosVictoriaJ1 -= 3;
                }
              }
              estatuillasDisponibles[2] = false;
              contadorEstatuillasObtenidas++;
            }
          }
          if (turnoJugador1) {
            primerIntentoMedusaJ1 = false;
            turnoJugador1 = false;
          } else {
            primerIntentoMedusaJ2 = false;
            turnoJugador1 = true;
          }
        };
        break;
      case 4:
        if (estatuillasDisponibles[3]) {
          cout << "ESTATUILLA OBJETIVO: Aguila" << endl;
          cout << "CONDICION DE OBTENCION: Dos de los dados lanzados "
                  "deberan "
                  "devolver los numeros 1 y 10."
               << endl;
          if (!turnoJugador1 && maldicionSalamandraJ1) {
            if (admin) {
              cin >> tresDados[0] >> tresDados[1] >> tresDados[2];
            } else {
              lanzarTresDados(tresDados);
            }
            cout << "DADO 1: " << tresDados[0] << endl;
            cout << "DADO 2: " << tresDados[1] << endl;
            cout << "DADO 3: " << tresDados[2] << endl;
            if ((tresDados[0] == 10 && tresDados[1] == 1) ||
                (tresDados[1] == 10 && tresDados[0] == 1) ||
                (tresDados[0] == 10 && tresDados[2] == 1) ||
                (tresDados[2] == 10 && tresDados[0] == 1) ||
                (tresDados[1] == 10 && tresDados[2] == 1) ||
                (tresDados[2] == 10 && tresDados[1] == 1)) {
              cout << "Ganaste la estatuilla de Aguila" << endl;
              jugador2Estatuillas[3] = new string("Aguila");
              maldicionAguilaJ2 = true;
              estatuillasDisponibles[3] = false;
              contadorEstatuillasObtenidas++;
              maldicionAguila = true;
              primeraVez = true;
              if (primerIntentoAguilaJ2) {
                puntosVictoriaJ2 += 10;
                puntosVictoriaJ1 -= 3;

              } else {
                puntosVictoriaJ2 += 5;
                puntosVictoriaJ1 -= 3;
              }
            }
          } else if (turnoJugador1 && maldicionSalamandraJ2) {
            if (admin) {
              cin >> tresDados[0] >> tresDados[1] >> tresDados[2];
            } else {
              lanzarTresDados(tresDados);
            }
            cout << "DADO 1: " << tresDados[0] << endl;
            cout << "DADO 2: " << tresDados[1] << endl;
            cout << "DADO 3: " << tresDados[2] << endl;
            if ((tresDados[0] == 10 && tresDados[1] == 1) ||
                (tresDados[1] == 10 && tresDados[0] == 1) ||
                (tresDados[0] == 10 && tresDados[2] == 1) ||
                (tresDados[2] == 10 && tresDados[0] == 1) ||
                (tresDados[1] == 10 && tresDados[2] == 1) ||
                (tresDados[2] == 10 && tresDados[1] == 1)) {
              cout << "Ganaste la estatuilla de Aguila" << endl;
              jugador1Estatuillas[3] = new string("Aguila");
              maldicionAguilaJ1 = true;
              estatuillasDisponibles[3] = false;
              contadorEstatuillasObtenidas++;
              maldicionAguila = true;
              primeraVez = true;
              if (primerIntentoAguilaJ1) {
                puntosVictoriaJ1 += 10;
                puntosVictoriaJ2 -= 3;

              } else {
                puntosVictoriaJ1 += 5;
                puntosVictoriaJ2 -= 3;
              }
            }
          } else {
            if (admin) {
              cin >> dadosExpedicion[0] >> dadosExpedicion[1];
            } else {
              lanzarDosDados(dadosExpedicion);
            }
            cout << "DADO 1: " << dadosExpedicion[0] << endl;
            cout << "DADO 2: " << dadosExpedicion[1] << endl;
            if (dadosExpedicion[0] == 10 && dadosExpedicion[1] == 1 ||
                dadosExpedicion[1] == 10 && dadosExpedicion[0] == 1) {
              cout << "Ganaste la estatuilla de Aguila" << endl;
              if (turnoJugador1) {
                jugador1Estatuillas[3] = new string("Aguila");
                maldicionAguilaJ1 = true;
                if (primerIntentoAguilaJ1) {
                  puntosVictoriaJ1 += 10;
                  puntosVictoriaJ2 -= 3;

                } else {
                  puntosVictoriaJ1 += 5;
                  puntosVictoriaJ2 -= 3;
                }
              } else {
                jugador2Estatuillas[3] = new string("Aguila");
                maldicionAguilaJ2 = true;
                if (primerIntentoAguilaJ2) {
                  puntosVictoriaJ2 += 10;
                  puntosVictoriaJ1 -= 3;

                } else {
                  puntosVictoriaJ2 += 5;
                  puntosVictoriaJ1 -= 3;
                }
              }
              estatuillasDisponibles[3] = false;
              maldicionAguila = true;
              primeraVez = true;
              contadorEstatuillasObtenidas++;
            }
          }
          if (turnoJugador1) {
            primerIntentoAguilaJ1 = false;
            turnoJugador1 = false;
          } else {
            primerIntentoAguilaJ2 = false;
            turnoJugador1 = true;
          }
        };
        break;
      case 5:
        if (estatuillasDisponibles[4]) {
          cout << "ESTATUILLA OBJETIVO: Salamandra" << endl;
          cout << "CONDICION DE OBTENCION: Los dados lanzados deben ser "
                  "consecutivos. Por ejemplo: (1 y 2) (2 y 3) (9 y 10)."
               << endl;
          if (admin) {
            cin >> dadosExpedicion[0] >> dadosExpedicion[1];
          } else {
            lanzarDosDados(dadosExpedicion);
          }
          cout << "DADO 1: " << dadosExpedicion[0] << endl;
          cout << "DADO 2: " << dadosExpedicion[1] << endl;
          if (dadosExpedicion[0] &&
              dadosExpedicion[1] == dadosExpedicion[0] + 1) {
            cout << "Ganaste la estatuilla de Salamandra" << endl;
            if (turnoJugador1) {
              jugador1Estatuillas[4] = new string("Salamandra");
              maldicionSalamandraJ1 = true;
              if (primerIntentoSalamandraJ1) {
                puntosVictoriaJ1 += 10;
                puntosVictoriaJ2 -= 3;

              } else {
                puntosVictoriaJ1 += 5;
                puntosVictoriaJ2 -= 3;
              }
            } else {
              jugador2Estatuillas[4] = new string("Salamandra");
              maldicionSalamandraJ2 = true;
              if (primerIntentoSalamandraJ2) {
                puntosVictoriaJ2 += 10;
                puntosVictoriaJ1 -= 3;

              } else {
                puntosVictoriaJ2 += 5;
                puntosVictoriaJ1 -= 3;
              }
            }
            estatuillasDisponibles[4] = false;
            contadorEstatuillasObtenidas++;
          }
          if (turnoJugador1) {
            primerIntentoSalamandraJ1 = false;
            turnoJugador1 = false;
          } else {
            primerIntentoSalamandraJ2 = false;
            turnoJugador1 = true;
          }
        };
        break;
      default:
        cout << "Opcion Invalida.";
        break;
    }
  }

  cout << "LA FASE DE EXPEDICION HA TERMINADO!" << endl;

  faseFinal(jugador1Estatuillas, jugador2Estatuillas, restarPuntosVictoriaJ1,
            restarPuntosVictoriaJ2, jugador1, jugador2, turnoJugador1);
}

void showStatistics() {
  cout << "Los puntos de victoria del JUGADOR 1"
       << " son: " << puntosVictoriaJ1 << endl;
  cout << "Los puntos de victoria del JUGADOR 2"
       << " son: " << puntosVictoriaJ2 << endl;
};

void showCredits() {
  cout << "showCredits";
};

void seleccionarOpcion() {
  int opcion = 4;

  while (opcion != 0) {
    cout << "IRWIN'S REVENGE \n -- -- -- -- -- -- -- -- -- -- -- -- -- "
            "-- --  "
            "\n "
            "1 - JUGAR PARA DOS JUGADORES \n 2 - ESTADISTICAS \n 3 - "
            "CREDITOS "
            "\n "
            "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- \n 0 - SALIR \n"
         << endl;

    cout << "Elegir la opcion a ejecutar: ";
    cin >> opcion;

    switch (opcion) {
      case 0:
        exit();
        break;
      case 1:
        startGame();
        break;
      case 2:
        showStatistics();
        break;
      case 3:
        showCredits();
        break;

      default:
        cout << "Esa opcion no existe." << endl;
        seleccionarOpcion();
        break;
    }
  }
}

int main() {
  seleccionarOpcion();
};