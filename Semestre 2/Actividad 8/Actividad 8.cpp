/*******Presentacion*******
Nombre: Santiago Jimenez Garcia
Fecha: 12 de Abril de 2024
Programa: Ejercicio 8
Centro Universitario de los Altos / Universidad de Guadalajara
INGENIERIA EN COMPUTACION SEGUNDO SEMESTRE
Profesor: CARLOS JAVIER CRUZ FRANCO
Descripcion:

***************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int x = 5;
int y = 5;

#include "lib.cpp"

int main() {

    int opcion;
    char conjunto1[x];
    char conjunto2[y];

    do {
        // Menú de opciones
        cout << "\n--- Menu ---\n";
        cout << "1. Llenar conjunto\n";
        cout << "2. Mostrar lista de valores\n";
        cout << "3. Realizar operacion de conjuntos\n";
        cout << "4. Vaciar conjunto\n";
        cout << "5. Salir\n";
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Llenar conjunto
                cout << "Elegir conjunto:\n";
                cout << "1. para el conjunto 1\n";
                cout << "2. para el conjunto 2\n";
                int conjunto;
                cin >> conjunto;
                if (conjunto == 1) {
                    llenarConjunto(conjunto1, x);
                } else if (conjunto == 2) {
                    llenarConjunto(conjunto2, y);
                } else {
                    cout << "Conjunto invalido.\n";
                }
                break;
            case 2:
                // Mostrar lista de valores
                mostrarConjuntos(conjunto1, conjunto2, x, y);
                break;
            case 3:
                // Realizar operacion de conjuntos
                cout << "Elige la operacion a realizar:\n";
                cout << "1.- Union\n";
                cout << "2.- Interseccion\n";
                cout << "3.- Diferencia\n";
                cout << "4.- Complemento\n";
                int operacion;
                cin >> operacion;
                realizarOperacion(conjunto1, conjunto2, x, y, operacion);
                break;
            case 4:
                // Vaciar conjunto
                cout << "Elegir conjunto:\n";
                cout << "1. para conjunto 1\n";
                cout << "2. para conjunto 2\n";
                cin >> conjunto;
                if (conjunto == 1) {
                    vaciarArreglo(conjunto1, x);
                } else if (conjunto == 2) {
                    vaciarArreglo(conjunto2, y);
                } else {
                    cout << "Conjunto invalido.\n";
                }
                cout << "Conjunto vaciado.\n";
                break;
            case 5:
                // Salir
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}
