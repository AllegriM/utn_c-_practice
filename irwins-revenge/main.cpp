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
#include <iostream>
using namespace std;

void exit() {
  cout << "Saliendo del juego";
};

void lanzarDosDados(int dados[]) {
  const int CANT_DADOS = 2;

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

void startGame() {
  int NUM_ESTATUILLAS = 5, contadorEstatuillasObtenidas = 0;
  string jugador1, jugador2;
  string jugador1Estatuillas[5] = {}, jugador2Estatuillas[5] = {};
  int opcion, dadosFaseFinal[5] = {}, dadosExpedicion[2] = {},
              dadoOrdenJugadores[2] = {};
  bool estatuillasDisponibles[NUM_ESTATUILLAS] = {true, true, true, true, true};
  string estatuillas[NUM_ESTATUILLAS] = {"Hormiga", "Cangrejo", "Medusa",
                                         "Aguila", "Salamandra"};
  bool opcionElegida = false, turnoJugador1 = false;

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

  //  FASE DE EXPEDICION
  cout << "\n IRWIN'S REVENGE - FASE DE EXPEDICION \n "
          "----------------------------------------------------------------"
          "----"
       << endl;

  while (contadorEstatuillasObtenidas != 5) {
    cout << jugador1 << ": \n ESTATUILLAS: " << endl;
    for (int i = 0; i <= 4; i++) {
      cout << jugador1Estatuillas[i] << "\n";
    }
    cout << jugador2 << ": \n ESTATUILLAS: " << endl;
    for (int i = 0; i <= 4; i++) {
      cout << jugador2Estatuillas[i] << "\n";
    }
    cout << "---------------------- \n\n" << endl;

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
        cout << "ESTATUILLA OBJETIVO: Hormiga" << endl;
        cout
            << "CONDICION DE OBTENCION: Al menos dos dados deben ser menores a "
               "5."
            << endl;
        lanzarDosDados(dadosExpedicion);
        if (dadosExpedicion[0] < 5 && dadosExpedicion[1] < 5) {
          cout << "Ganaste la estatuilla de Hormiga" << endl;
          if (turnoJugador1) {
            jugador1Estatuillas[0] = "Hormiga";
          } else {
            jugador2Estatuillas[0] = "Hormiga";
          }
          estatuillasDisponibles[0] = false;
          contadorEstatuillasObtenidas++;
        }
        if (turnoJugador1) {
          turnoJugador1 = false;
        } else {
          turnoJugador1 = true;
        }

        break;
      case 2:
        cout << "ESTATUILLA OBJETIVO: Cangrejo" << endl;
        cout << "CONDICION DE OBTENCION: Uno de sus dados debe ser par y otro "
                "de "
                "sus dados impar."
             << endl;
        lanzarDosDados(dadosExpedicion);
        if ((dadosExpedicion[0] % 2 != 0 && dadosExpedicion[1] % 2 == 0) ||
            (dadosExpedicion[0] % 2 == 0 && dadosExpedicion[1] % 2 != 0)) {
          cout << "Ganaste la estatuilla de Cangrejo" << endl;
          if (turnoJugador1) {
            jugador1Estatuillas[1] = "Cangrejo";
          } else {
            jugador2Estatuillas[1] = "Cangrejo";
          }
          estatuillasDisponibles[1] = false;
          contadorEstatuillasObtenidas++;
        }
        if (turnoJugador1) {
          turnoJugador1 = false;
        } else {
          turnoJugador1 = true;
        }
        break;
      case 3:
        cout << "ESTATUILLA OBJETIVO: Medusa" << endl;
        cout << "CONDICION DE OBTENCION: La suma de dos de los dados lanzados "
                "debe dar exactamente siete."
             << endl;
        lanzarDosDados(dadosExpedicion);
        if (dadosExpedicion[0] + dadosExpedicion[1] == 7) {
          cout << "Ganaste la estatuilla de Medusa" << endl;
          if (turnoJugador1) {
            jugador1Estatuillas[2] = "Medusa";
          } else {
            jugador2Estatuillas[2] = "Medusa";
          }
          estatuillasDisponibles[2] = false;
          contadorEstatuillasObtenidas++;
        }
        if (turnoJugador1) {
          turnoJugador1 = false;
        } else {
          turnoJugador1 = true;
        }

        break;
      case 4:
        cout << "ESTATUILLA OBJETIVO: Aguila" << endl;
        cout << "CONDICION DE OBTENCION: Dos de los dados lanzados deberan "
                "devolver los numeros 1 y 10."
             << endl;
        lanzarDosDados(dadosExpedicion);
        if (dadosExpedicion[0] == 10 && dadosExpedicion[1] == 1 ||
            dadosExpedicion[1] == 10 && dadosExpedicion[0] == 1) {
          cout << "Ganaste la estatuilla de Aguila" << endl;
          if (turnoJugador1) {
            jugador1Estatuillas[3] = "Aguila";
          } else {
            jugador2Estatuillas[3] = "Aguila";
          }
          estatuillasDisponibles[3] = false;
          contadorEstatuillasObtenidas++;
        }
        if (turnoJugador1) {
          turnoJugador1 = false;
        } else {
          turnoJugador1 = true;
        }

        break;
      case 5:
        cout << "ESTATUILLA OBJETIVO: Salamandra" << endl;
        cout << "CONDICION DE OBTENCION: Los dados lanzados deben ser "
                "consecutivos. Por ejemplo: (1 y 2) (2 y 3) (9 y 10)."
             << endl;
        lanzarDosDados(dadosExpedicion);
        if (dadosExpedicion[0] &&
            dadosExpedicion[1] == dadosExpedicion[0] + 1) {
          cout << "Ganaste la estatuilla de Salamandra" << endl;
          if (turnoJugador1) {
            jugador1Estatuillas[4] = "Salamandra";
          } else {
            jugador2Estatuillas[4] = "Salamandra";
          }
          estatuillasDisponibles[4] = false;
          contadorEstatuillasObtenidas++;
        }
        if (turnoJugador1) {
          turnoJugador1 = false;
        } else {
          turnoJugador1 = true;
        }

        break;
      default:
        cout << "Opcion Invalida.";
        break;
    }

    cout << "DADO 1: " << dadosExpedicion[0] << endl;
    cout << "DADO 2: " << dadosExpedicion[1] << endl;
  }
};

void showStatistics() {
  cout << "showStatistics";
};

void showCredits() {
  cout << "showCredits";
};

void seleccionarOpcion() {
  int opcion;

  cout << "IRWIN'S REVENGE \n -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  "
          "\n "
          "1 - JUGAR PARA DOS JUGADORES \n 2 - ESTADISTICAS \n 3 - CREDITOS "
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
  string steve[5], irwin[5];
  seleccionarOpcion();
}