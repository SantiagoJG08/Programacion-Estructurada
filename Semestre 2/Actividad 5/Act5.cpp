/*******Presentacion*******
Nombre: Santiago Jimenez Garcia
Fecha: 16 de Febrero de 2024
Programa: Ejercicio 5
Centro Universitario de los Altos / Universidad de Guadalajara
INGENIERIA EN COMPUTACION SEGUNDO SEMESTRE
Profesor: CARLOS JAVIER CRUZ FRANCO
Descripcion:Elaborar una suma de un vector con las siguientes características
-Tener máximo 10 espacios
-El usuario final debe elegir cuando entra un valor a cada posición (no es meter todos los datos)
-Mostrar lista de valores
-Mostrar sumatoria de todos los elementos
-Borrado y edición de elementos
-Vaciado de arreglo
-Puedes agregar un menú para facilitar el uso al usuario final
***************************/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numeros[10]; // Vector con 10 elementos 
    int opcion, posicion, valor, sumatoria;

    do {
        // Menú de opciones
        cout << "\n--- Menu ---\n";
        cout << "1. Ingresar valor en una posicion\n";
        cout << "2. Mostrar lista de valores\n";
        cout << "3. Mostrar sumatoria de todos los elementos\n";
        cout << "4. Borrar elemento en una posicion\n";
        cout << "5. Editar elemento en una posicion\n";
        cout << "6. Vaciar arreglo\n";
        cout << "7. Salir\n";
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese la posicion (0-9): ";
                cin >> posicion;
                cout << "Ingrese el valor: ";
                cin >> valor;
                if (posicion >= 0 && posicion < 10) {
                    numeros[posicion] = valor;
                } else {
                    cout << "Posicion invalida. Debe ser entre 0 y 9.\n";
                }
                break;
            case 2:
                cout << "Lista de valores:\n";
                for (int i = 0; i < 10; i++) {
                    cout << "Posicion " << i << ": " << numeros[i] << endl;
                }
                break;
            case 3:
                cout << "Sumatoria de todos los elementos: ";
                sumatoria = 0;
                for (int i = 0; i < 10; i++) {
                    sumatoria += numeros[i];
                }
                cout << sumatoria << endl;
                break;
            case 4:
                cout << "Ingrese la posicion a borrar (0-9): ";
                cin >> posicion;
                if (posicion >= 0 && posicion < 10) {
                    numeros[posicion] = 0;
                } else {
                    cout << "Posicion invalida. Debe ser entre 0 y 9.\n";
                }
                break;
            case 5:
                cout << "Ingrese la posicion a editar (0-9): ";
                cin >> posicion;
                cout << "Ingrese el nuevo valor: ";
                cin >> valor;
                numeros[posicion] = valor;
                break;
            case 6:
                for (int i = 0; i < 10; i++) {
                    numeros[i] = 0; // Vaciar el vector creando uno nuevo
                }
                cout << "Arreglo vaciado.\n";
                break;
            case 7:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 7);
    return 0;
}
