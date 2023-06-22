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

void exit() {
  cout << "Saliendo del juego";
};

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
  int opcion, numeroCambiasso;
  bool escaleraEncontrada = false, beneficioCangrejo = true,
       bendicionHormigaJ1 = false, bendicionHormigaJ2 = false;
  int dados[5] = {};

  for (int i = 0; i <= 4; i++) {
    if (estatuillasJ1[i] == "Hormiga") {
      cout << "El jugador " << jugador1 << " tiene la estatuilla de Hormiga"
           << endl;
      cout << "Podes elegir un numero y luego en cada tirada cambiar un numero "
              "aleatorio por ese mismo."
           << endl;
      cout << "Ingrese el numero x el que va a poder cambiar en la fase "
              "final: ";
      cin << numeroCambiasso;
      bendicionHormigaJ1 = true;
    } else if (estatuillasJ2[i] == "Hormiga") {
      cout << "El jugador " << jugador2 << " tiene la estatuilla de Hormiga"
           << endl;
      cout << "Podes elegir un numero y luego en cada tirada cambiar un numero "
              "aleatorio por ese mismo."
           << endl;
      cout << "Ingrese el numero x el que va a poder cambiar en la fase "
              "final: ";
      cin << numeroCambiasso;
      bendicionHormigaJ2 = true;
    }
  }

  cout << "---------- FASE FINAL ------------" << endl;
  cout << "JUGADOR 1" << setw(20) << "JUGADOR 2" << endl;
  cout << "ESTATUILLAS: " << setw(21) << "ESTATUILLAS: " << endl;
  for (int i = 0; i <= 4; i++) {
    cout << *estatuillasJ1[i] << setw(30) << *estatuillasJ2[i] << endl;
  }

  cout << "---------- TIRADA DE DADOS ------------" << endl;

  while (escaleraEncontrada == false) {
    if (turnoJugador1) {
      cout << "Turno de " << jugador1 << endl;

      lanzarCincoDados6Caras(dados);

      for (int i = 0; i < 5; i++) {
        cout << dados[i] << " " << endl;
      };

      for (int i = 0; i < 4; i++) {
        if (*estatuillasJ1[i] == "Cangrejo" && beneficioCangrejo) {
          // Podrá lanzar los dados dos veces en el primer tiro de la fase
          // final.
          cout << "Tenes la estatuilla de Cangrejo, podes tirar los dados "
                  "otra vez mas si queres en el primer tiro de la fase final."
               << endl;
          cout << "¿Queres tirar los dados otra vez? (1 = si, 0 = no)" << endl;
          cin >> opcion;
          if (opcion == 1) {
            lanzarCincoDados6Caras(dados);
            for (int i = 0; i < 5; i++) {
              cout << dados[i] << " " << endl;
            };
            beneficioCangrejo = false;
          } else if (opcion == 0) {
            beneficioCangrejo = false;
          }
        } else if (*estatuillasJ1[i] == "Medusa" &&
                   (dados[0] && dados[1] == dados[0] && dados[2] == dados[0] &&
                    dados[3] == dados[0] && dados[4] == dados[0] &&
                    dados[5] == dados[0])) {
          // GANA PUNTOS DE VICTORIA
        }
      }

    } else {
      cout << "Turno de " << jugador2 << endl;

      lanzarCincoDados6Caras(dados);

      for (int i = 0; i < 5; i++) {
        cout << dados[i] << " " << endl;
      };

      for (int i = 0; i < 4; i++) {
        if (*estatuillasJ2[i] == "Cangrejo" && beneficioCangrejo) {
          // Podrá lanzar los dados dos veces en el primer tiro de la fase
          // final.
          cout << "Tenes la estatuilla de Cangrejo, podes tirar los dados "
                  "otra vez mas si queres en el primer tiro de la fase final."
               << endl;
          cout << "¿Queres tirar los dados otra vez? (1 = si, 0 = no)" << endl;
          cin >> opcion;
          if (opcion == 1) {
            lanzarCincoDados6Caras(dados);
            for (int i = 0; i < 5; i++) {
              cout << dados[i] << " " << endl;
            };
            beneficioCangrejo = false;
          } else if (opcion == 0) {
            beneficioCangrejo = false;
          }
        } else if (*estatuillasJ2[i] == "Cangrejo" && beneficioCangrejo) {
          // Podrá lanzar los dados dos veces en el primer tiro de la fase
          // final.
          cout << "Tenes la estatuilla de Cangrejo, podes tirar los dados "
                  "otra vez mas si queres en el primer tiro de la fase final."
               << endl;
          cout << "¿Queres tirar los dados otra vez? (1 = si, 0 = no)" << endl;
          cin >> opcion;
          if (opcion == 1) {
            lanzarCincoDados6Caras(dados);
            for (int i = 0; i < 5; i++) {
              cout << dados[i] << " " << endl;
            };
            beneficioCangrejo = false;
          } else if (opcion == 0) {
            beneficioCangrejo = false;
          }
        }
      }
    }
  }
}

void startGame() {
  int NUM_ESTATUILLAS = 5, contadorEstatuillasObtenidas = 0,
      restarPuntosVictoriaJ1 = 0, restarPuntosVictoriaJ2 = 0,
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
       primeraVez = false;

  for (int i = 0; i < NUM_ESTATUILLAS; i++) {
    jugador1Estatuillas[i] = new string("");
    jugador2Estatuillas[i] = new string("");
  }

  cout << "Ingrese el nombre del jugador numero 1: ";
  cin >> jugador1;

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

    cout << "CONTADOR MALDICION AGUILA " << contadorMaldicionAguila << endl;
    cout << "CONTADOR ESTATUILLAS OBTENIDAS " << contadorEstatuillasObtenidas
         << endl;

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
            lanzarTresDados(tresDados);
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
              restarPuntosVictoriaJ1 += puntosMaldicionHormiga[0] +
                                        puntosMaldicionHormiga[1] +
                                        puntosMaldicionHormiga[2];
            }
            estatuillasDisponibles[0] = false;
            contadorEstatuillasObtenidas++;
          } else if (turnoJugador1 && maldicionSalamandraJ2) {
            lanzarTresDados(tresDados);
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
              cout << puntosMaldicionHormiga[0] << " "
                   << puntosMaldicionHormiga[1] << " "
                   << puntosMaldicionHormiga[2] << endl;

              cout << "Se le descontaran "
                   << puntosMaldicionHormiga[0] + puntosMaldicionHormiga[1] +
                          puntosMaldicionHormiga[2]
                   << " puntos de victoria a " << jugador2 << endl;
              restarPuntosVictoriaJ2 += puntosMaldicionHormiga[0] +
                                        puntosMaldicionHormiga[1] +
                                        puntosMaldicionHormiga[2];
            }
            estatuillasDisponibles[0] = false;
            contadorEstatuillasObtenidas++;
          } else {
            lanzarDosDados(dadosExpedicion);
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
              }
              estatuillasDisponibles[0] = false;
              contadorEstatuillasObtenidas++;
            }
          };
          if (turnoJugador1) {
            turnoJugador1 = false;
          } else {
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
            lanzarTresDados(dadosExpedicion);
            if ((dadosExpedicion[0] % 2 != 0 && dadosExpedicion[1] % 2 == 0) ||
                (dadosExpedicion[0] % 2 == 0 && dadosExpedicion[1] % 2 != 0) ||
                (dadosExpedicion[0] % 2 != 0 && dadosExpedicion[2] % 2 == 0) ||
                (dadosExpedicion[0] % 2 == 0 && dadosExpedicion[2] % 2 != 0) ||
                (dadosExpedicion[1] % 2 != 0 && dadosExpedicion[2] % 2 == 0) ||
                (dadosExpedicion[1] % 2 == 0 && dadosExpedicion[2] % 2 != 0)) {
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
            }
          } else if (turnoJugador1 && maldicionSalamandraJ2) {
            if ((dadosExpedicion[0] % 2 != 0 && dadosExpedicion[1] % 2 == 0) ||
                (dadosExpedicion[0] % 2 == 0 && dadosExpedicion[1] % 2 != 0) ||
                (dadosExpedicion[0] % 2 != 0 && dadosExpedicion[2] % 2 == 0) ||
                (dadosExpedicion[0] % 2 == 0 && dadosExpedicion[2] % 2 != 0) ||
                (dadosExpedicion[1] % 2 != 0 && dadosExpedicion[2] % 2 == 0) ||
                (dadosExpedicion[1] % 2 == 0 && dadosExpedicion[2] % 2 != 0)) {
              lanzarTresDados(dadosExpedicion);
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
            }
          } else {
            if ((dadosExpedicion[0] % 2 != 0 && dadosExpedicion[1] % 2 == 0) ||
                (dadosExpedicion[0] % 2 == 0 && dadosExpedicion[1] % 2 != 0)) {
              lanzarDosDados(dadosExpedicion);
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
                estatuillasDisponibles[1] = false;
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
              }
              estatuillasDisponibles[1] = false;
              contadorEstatuillasObtenidas++;
            }
          };
          if (turnoJugador1) {
            turnoJugador1 = false;
          } else {
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
            lanzarTresDados(dadosExpedicion);
            if ((dadosExpedicion[0] + dadosExpedicion[1] == 7) ||
                (dadosExpedicion[0] + dadosExpedicion[2] == 7) ||
                (dadosExpedicion[1] + dadosExpedicion[2] == 7)) {
              lanzarTresDados(dadosExpedicion);
              cout << "Ganaste la estatuilla de Medusa" << endl;
              jugador2Estatuillas[2] = new string("Medusa");
              maldicionMedusaJ2 = true;
              estatuillasDisponibles[2] = false;
              contadorEstatuillasObtenidas++;
            }
          } else if (turnoJugador1 && maldicionSalamandraJ2) {
            lanzarTresDados(dadosExpedicion);
            if ((dadosExpedicion[0] + dadosExpedicion[1] == 7) ||
                (dadosExpedicion[0] + dadosExpedicion[2] == 7) ||
                (dadosExpedicion[1] + dadosExpedicion[2] == 7)) {
              lanzarTresDados(dadosExpedicion);
              cout << "Ganaste la estatuilla de Medusa" << endl;
              jugador1Estatuillas[2] = new string("Medusa");
              maldicionMedusaJ1 = true;
              estatuillasDisponibles[2] = false;
              contadorEstatuillasObtenidas++;
            }
          } else {
            lanzarDosDados(dadosExpedicion);
            if (dadosExpedicion[0] + dadosExpedicion[1] == 7) {
              cout << "Ganaste la estatuilla de Medusa" << endl;
              if (turnoJugador1) {
                // El jugador pierde turno x 3 rondas
                jugador1Estatuillas[2] = new string("Medusa");
                maldicionMedusaJ1 = true;
              } else {
                // El jugador pierde turno x 3 rondas
                jugador2Estatuillas[2] = new string("Medusa");
                maldicionMedusaJ2 = true;
              }
              estatuillasDisponibles[2] = false;
              contadorEstatuillasObtenidas++;
            }
          }
          if (turnoJugador1) {
            turnoJugador1 = false;
          } else {
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
            lanzarTresDados(dadosExpedicion);
            if ((dadosExpedicion[0] == 10 && dadosExpedicion[1] == 1) ||
                (dadosExpedicion[1] == 10 && dadosExpedicion[0] == 1) ||
                (dadosExpedicion[0] == 10 && dadosExpedicion[2] == 1) ||
                (dadosExpedicion[2] == 10 && dadosExpedicion[0] == 1) ||
                (dadosExpedicion[1] == 10 && dadosExpedicion[2] == 1) ||
                (dadosExpedicion[2] == 10 && dadosExpedicion[1] == 1)) {
              cout << "Ganaste la estatuilla de Aguila" << endl;
              jugador2Estatuillas[3] = new string("Aguila");
              maldicionAguilaJ2 = true;
              estatuillasDisponibles[3] = false;
              contadorEstatuillasObtenidas++;
              maldicionAguila = true;
              primeraVez = true;
            }
          } else if (turnoJugador1 && maldicionSalamandraJ2) {
            lanzarTresDados(dadosExpedicion);
            if ((dadosExpedicion[0] == 10 && dadosExpedicion[1] == 1) ||
                (dadosExpedicion[1] == 10 && dadosExpedicion[0] == 1) ||
                (dadosExpedicion[0] == 10 && dadosExpedicion[2] == 1) ||
                (dadosExpedicion[2] == 10 && dadosExpedicion[0] == 1) ||
                (dadosExpedicion[1] == 10 && dadosExpedicion[2] == 1) ||
                (dadosExpedicion[2] == 10 && dadosExpedicion[1] == 1)) {
              cout << "Ganaste la estatuilla de Aguila" << endl;
              jugador1Estatuillas[3] = new string("Aguila");
              maldicionAguilaJ1 = true;
              estatuillasDisponibles[3] = false;
              contadorEstatuillasObtenidas++;
              maldicionAguila = true;
              primeraVez = true;
            }
          } else {
            lanzarDosDados(dadosExpedicion);
            if (dadosExpedicion[0] == 10 && dadosExpedicion[1] == 1 ||
                dadosExpedicion[1] == 10 && dadosExpedicion[0] == 1) {
              cout << "Ganaste la estatuilla de Aguila" << endl;
              if (turnoJugador1) {
                jugador1Estatuillas[3] = new string("Aguila");
                maldicionAguilaJ1 = true;
              } else {
                jugador2Estatuillas[3] = new string("Aguila");
                maldicionAguilaJ2 = true;
              }
              estatuillasDisponibles[3] = false;
              maldicionAguila = true;
              primeraVez = true;
              contadorEstatuillasObtenidas++;
            }
          }
          if (turnoJugador1) {
            turnoJugador1 = false;
          } else {
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
          lanzarDosDados(dadosExpedicion);
          if (dadosExpedicion[0] &&
              dadosExpedicion[1] == dadosExpedicion[0] + 1) {
            cout << "Ganaste la estatuilla de Salamandra" << endl;
            if (turnoJugador1) {
              jugador1Estatuillas[4] = new string("Salamandra");
              maldicionSalamandraJ1 = true;
            } else {
              jugador2Estatuillas[4] = new string("Salamandra");
              maldicionSalamandraJ2 = true;
            }
            estatuillasDisponibles[4] = false;
            contadorEstatuillasObtenidas++;
          }
          if (turnoJugador1) {
            turnoJugador1 = false;
          } else {
            turnoJugador1 = true;
          }
        };
        break;
      default:
        cout << "Opcion Invalida.";
        break;
    }

    system("cls");
    cout << "DADO 1: " << dadosExpedicion[0] << endl;
    cout << "DADO 2: " << dadosExpedicion[1] << endl;
  }

  cout << "LA FASE DE EXPEDICION HA TERMINADO!" << endl;

  faseFinal(jugador1Estatuillas, jugador2Estatuillas, restarPuntosVictoriaJ1,
            restarPuntosVictoriaJ2, jugador1, jugador2, turnoJugador1);
}

void showStatistics() {
  cout << "showStatistics";
};

void showCredits() {
  cout << "showCredits";
};

void seleccionarOpcion() {
  int opcion;

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

int main() {
  seleccionarOpcion();
};