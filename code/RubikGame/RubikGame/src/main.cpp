#include <iostream>
#include <conio.h>  // Para _getch()
#include "Rubik.h"

using namespace std;

// Función para mostrar las instrucciones al usuario
void mostrarInstrucciones() {
    cout << "Instrucciones:" << endl;
    cout << "'T' - Rotar la cara superior (Top)" << endl;
    cout << "'B' - Rotar la cara inferior (Bottom)" << endl;
    cout << "'L' - Rotar la cara izquierda (Left)" << endl;
    cout << "'R' - Rotar la cara derecha (Right)" << endl;
    cout << "'M' - Rotar la fila del medio (Middle)" << endl;
    cout << "'U' - Rotar la fila superior (Arriba)" << endl;
    cout << "'D' - Rotar la fila inferior (Abajo)" << endl;
    cout << "'Q' - Salir del programa" << endl;
}

// Funcion para limpiar la pantalla
void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Funcion para leer una tecla sin esperar Enter
char leerTecla() {
    return _getch();
}

int main() {
    Rubik cubito;
    char opcion;

    // Mostrar las instrucciones al usuario
    mostrarInstrucciones();

    cout << "Presiona una tecla para realizar una rotación (o 'Q' para salir):" << endl;

    do {
        opcion = leerTecla();  // Leer una tecla sin necesidad de Enter

        // Limpiar la pantalla antes de mostrar el nuevo estado
        limpiarPantalla();

        // Realizar la rotación según la tecla presionada
        switch (opcion) {
        case 'T':
            cubito.rotarTop();
            break;
        case 'B':
            cubito.rotarBottom();
            break;
        case 'L':
            cubito.rotarIzquierda();
            break;
        case 'R':
            cubito.rotarDerecha();
            break;
        case 'M':
            cubito.rotarMed();
            break;
        case 'U':
            cubito.rotarArriba();
            break;
        case 'D':
            cubito.rotarAbajo();
            break;
        case 'Q':
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida. Por favor, ingrese una tecla entre 'T' y 'Q'." << endl;
            break;
        }

        // Mostrar el estado del cubo despues de realizar la rotacion
        if (opcion != 'Q') {
            cubito.imprimiRubik();
        }

    } while (opcion != 'Q');

    return 0;
}
