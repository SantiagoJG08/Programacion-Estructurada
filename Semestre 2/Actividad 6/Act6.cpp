/*******Presentacion*******
Nombre: Santiago Jimenez Garcia
Fecha: 03 de Marzo de 2024
Programa: Ejercicio 6
Centro Universitario de los Altos / Universidad de Guadalajara
INGENIERIA EN COMPUTACION SEGUNDO SEMESTRE
Profesor: CARLOS JAVIER CRUZ FRANCO
Descripcion:
Elaborar una calculadora que realice la suma, resta y multiplicación de 2 matrices. Las condiciones son la siguientes:
Matriz cuadrada mínima es de 2x2 y máxima 10x10
El valor los puede meter el usuario e indicar en qué matriz irá dicho valor
Tendrá la opción de ser llenada con valores aleatorios entre - 100  y 100
Realizar la operación que indique el usuario final
Mostrar los valores que tienen las matrices
Borrado y edición de elementos
Vaciado de matrices
***************************/
#include <iostream>
#include <random> // Se incluye la librería random para generar números aleatorios

using namespace std;

// Función para llenar una matriz con valores ingresados por el usuario
void llenarMatriz(int matriz[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int valor;
            cout << "Ingrese el valor para la posicion [" << i << "][" << j << "]: ";
            cin >> valor;
            matriz[i][j] = valor;
        }
    }
}

// Función para ingresar un valor en una posición específica de una matriz
void ingresarValor(int matriz[2][2], int fila, int columna, int valor) {
    matriz[fila][columna] = valor;
}

// Función para generar valores aleatorios en una matriz
void generarAleatorio(int matriz[2][2]) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(-100, 100);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matriz[i][j] = dis(gen);
        }
    }
}

// Función para realizar una operación (suma, resta o multiplicación) entre dos matrices
void realizarOperacion(int matriz1[2][2], int matriz2[2][2], int operacion) {
    int resultado = 0; // Initialize the result variable
    if (operacion == 1) {
        // Suma
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                resultado += matriz1[i][j] + matriz2[i][j]; // Realizar la suma
            }
        }
        cout << "Resultado de la suma: " << resultado << endl;
    } else if (operacion == 2) {
        // Resta
        int resta;
        cout << "Elige el minuendo:\n";
        cout << "1. matriz1-matriz2\n";
        cout << "2. matriz2-matriz1\n";
        cin >> resta;
        if (resta == 1) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    resultado += matriz1[i][j] - matriz2[i][j]; // Realizar resta matriz1-matriz2
                }
            }
        } else if (resta == 2) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    resultado += matriz2[i][j] - matriz1[i][j]; // Realizar resta matriz2-matriz1
                }
            }
        } else {
            cout << "Opcion invalida.\n";
        }
        cout << "Resultado de la resta: " << resultado << endl;
    } else if (operacion == 3) {
        // Multiplicacion
        int resultado[2][2] = {{0, 0}, {0, 0}};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    resultado[i][j] += matriz1[i][k] * matriz2[k][j];
                }
            }
        }
        cout << "Resultado de la multiplicacion:\n";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << resultado[i][j] << "\t";
            }
            cout << endl;
        }
    } else {
        cout << "Operacion invalida.\n";
    }
}

// Función para mostrar las dos matrices
void mostrarMatrices(int matriz1[2][2], int matriz2[2][2]) {
    cout << "Matriz 1:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matriz1[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Matriz 2:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matriz2[i][j] << "\t";
        }
        cout << endl;
    }
}

// Función para borrar un elemento en una posición específica de una matriz
void borrar(int matriz[2][2], int fila, int columna) {
    matriz[fila][columna] = 0; // Para borrar, se coloca 0 en la posición
}

// Función para vaciar una matriz (llenarla con ceros)
void vaciarArreglo(int matriz[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matriz[i][j] = 0;
        }
    }
}

int main() {
    // Se inicializan las dos matrices 2x2 con ceros
    int matriz1[2][2] = {{0, 0}, {0, 0}};
    int matriz2[2][2] = {{0, 0}, {0, 0}};
    int opcion, fila, columna, valor;

    do {
        // Menú de opciones
        cout << "\n=================================\n";
        cout << "\t--- Menu ---\n";
        cout << "1. Llenar matriz\n";
        cout << "2. Ingresar valor en una posicion\n";
        cout << "3. Aleatorio\n";
        cout << "4. Realizar operacion\n";
        cout << "5. Mostrar matricez\n";
        cout << "6. Borrar o editar elemento en una posicion\n";
        cout << "7. Vaciar arreglo\n";
        cout << "8. Salir\n";
        cout << "Ingrese opcion: ";
        cin >> opcion;
        cout << "========================\n";
        switch (opcion) {
            case 1:
                // Llenar matriz por medio de un for
                int matriz;
                cout << "Elegir matriz:\n";
                cout << "1. para matriz1\n";
                cout << "2. para matriz2\n";
                cin >> matriz;
                if (matriz == 1) {
                    llenarMatriz(matriz1);
                } else if (matriz == 2) {
                    llenarMatriz(matriz2);
                } else {
                    cout << "Matriz invalida.\n";
                }
                break;
            case 2:
                // Ingresar valor en una posicion
                int matriz_pos;
                cout << "Elegir matriz:\n";
                cout << "1. para matriz1\n";
                cout << "2. para matriz2\n";
                cin >> matriz_pos;
                if (matriz_pos == 1 || matriz_pos == 2) {
                    cout << "Ingrese la fila (0-1): ";
                    cin >> fila;
                    cout << "Ingrese la columna (0-1): ";
                    cin >> columna;
                    cout << "Ingrese el valor: ";
                    cin >> valor;
                    if (matriz_pos == 1) {
                        ingresarValor(matriz1, fila, columna, valor);
                    } else {
                        ingresarValor(matriz2, fila, columna, valor);
                    }
                } else {
                    cout << "Matriz invalida.\n";
                }
                break;
            case 3:
                // Aleatorio
                int matriz_rand;
                cout << "Elegir matriz:\n";
                cout << "1. para matriz1\n";
                cout << "2. para matriz2\n";
                cin >> matriz_rand;
                if (matriz_rand == 1) {
                    generarAleatorio(matriz1);
                } else if (matriz_rand == 2) {
                    generarAleatorio(matriz2);
                } else {
                    cout << "Matriz invalida.\n";
                }
                break;
            case 4:
                // Realizar operacion
                int operacion;
                cout << "Seleccione la operacion a realizar:\n";
                cout << "1. Suma\n";
                cout << "2. Resta\n";
                cout << "3. Multiplicacion\n";
                cin >> operacion;
                realizarOperacion(matriz1, matriz2, operacion);
                break;
            case 5:
                // Mostrar matrices
                mostrarMatrices(matriz1, matriz2);
                break;
            case 6:
                // Borrar o editar elemento en una posicion
                int matriz_borrar;
                cout << "Elegir matriz:\n";
                cout << "1. para matriz1\n";
                cout << "2. para matriz2\n";
                cin >> matriz_borrar;
                cout << "Ingrese la fila (0-1): ";
                cin >> fila;
                cout << "Ingrese la columna (0-1): ";
                cin >> columna;
                if (matriz_borrar == 1) {
                    borrar(matriz1, fila, columna);
                } else if (matriz_borrar == 2) {
                    borrar(matriz2, fila, columna);
                } else {
                    cout << "Matriz invalida.\n";
                }
                break;
            case 7:
                // Vaciar arreglo
                int matriz_vaciar;
                cout << "Elegir matriz:\n";
                cout << "1. para matriz1\n";
                cout << "2. para matriz2\n";
                cin >> matriz_vaciar;
                if (matriz_vaciar == 1) {
                    vaciarArreglo(matriz1);
                } else if (matriz_vaciar == 2) {
                    vaciarArreglo(matriz2);
                } else {
                    cout << "Matriz invalida.\n";
                }
                break;
            case 8:
                // Salir
                break;
            default:
                cout << "Opcion invalida.\n";
                break;
        }

    } while (opcion != 8);

    return 0;
}