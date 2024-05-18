/*******Presentacion*******
Nombre: Santiago Jimenez Garcia
Fecha: 12 de Abril de 2024
Programa: Ejercicio 7
Centro Universitario de los Altos / Universidad de Guadalajara
INGENIERIA EN COMPUTACION SEGUNDO SEMESTRE
Profesor: CARLOS JAVIER CRUZ FRANCO
Descripcion:
Elaborar un programa que realice las operaciones de dos conjuntos:
Inserción de valores por parte del usuario
Pueden ser textuales o numéricos
Borrado y edición de elementos
Vaciado de conjuntos
Operaciones de Unión, Intersección, Diferencia y complemento.
Mínimo tener 5 datos en cada conjunto
***************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para llenar un conjunto con valores ingresados por el usuario.
void llenarConjunto(char conjunto[], int x) {
    for (int i = 0; i < x; i++) {
        char valor;
        cout << "Ingrese el valor para la posicion [" << i << "]: ";
        cin >> valor;
        conjunto[i] = valor;
    }
}

// Función para realizar operaciones entre dos conjuntos.
void realizarOperacion(char conjunto1[], char conjunto2[], int x, int y, int operacion) {
    vector<char> resultado;

    if (operacion == 1) {
        // Unión
        resultado.insert(resultado.end(), conjunto1, conjunto1 + x);
        resultado.insert(resultado.end(), conjunto2, conjunto2 + y);
        auto last = unique(resultado.begin(), resultado.end());
        resultado.erase(last, resultado.end());

        cout << "La union tiene " << (resultado.size()) << " elementos:\n";
        for (auto it = resultado.begin(); it != resultado.end(); ++it)
            cout << ' ' << *it;
        cout << '\n';
    } else if (operacion == 2) {
        // Intersección
        vector<char> interseccion;
        sort(conjunto1, conjunto1 + x);
        sort(conjunto2, conjunto2 + y);
        set_intersection(conjunto1, conjunto1 + x, conjunto2, conjunto2 + y, back_inserter(interseccion));

        cout << "La interseccion tiene " << (interseccion.size()) << " elementos:\n";
        for (auto it = interseccion.begin(); it != interseccion.end(); ++it)
            cout << ' ' << *it;
        cout << '\n';
    } else if (operacion == 3) {
        // Diferencia
        vector<char> diferencia;
        sort(conjunto1, conjunto1 + x);
        sort(conjunto2, conjunto2 + y);
        set_difference(conjunto1, conjunto1 + x, conjunto2, conjunto2 + y, back_inserter(diferencia));

        cout << "La diferencia tiene " << (diferencia.size()) << " elementos:\n";
        for (auto it = diferencia.begin(); it != diferencia.end(); ++it)
            cout << ' ' << *it;
        cout << '\n';
    } else if (operacion == 4) {
        // Complemento
        vector<char> complemento;
        sort(conjunto1, conjunto1 + x);
        sort(conjunto2, conjunto2 + y);
        set_difference(conjunto1, conjunto1 + x, conjunto2, conjunto2 + y, back_inserter(complemento));

        cout << "El complemento tiene " << (complemento.size()) << " elementos:\n";
        for (auto it = complemento.begin(); it != complemento.end(); ++it)
            cout << ' ' << *it;
        cout << '\n';
    }
}

// Función para mostrar los conjuntos.
void mostrarConjuntos(char conjunto1[], char conjunto2[], int x, int y) {
    cout << "Conjunto 1:\n";
    for (int i = 0; i < x; i++) {
        cout << conjunto1[i] << "\t";
    }
    cout << endl;
    cout << "Conjunto 2:\n";
    for (int i = 0; i < y; i++) {
        cout << conjunto2[i] << "\t";
    }
    cout << endl;
}

// Función para vaciar un conjunto.
void vaciarArreglo(char conjunto[], int x) {
    for (int i = 0; i < x; i++) {
        conjunto[i] = 0;
    }
}

int main() {
    int x = 5;
    int y = 5;
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
