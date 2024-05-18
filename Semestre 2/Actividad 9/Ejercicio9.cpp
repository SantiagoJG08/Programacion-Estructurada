/*******Presentacion*******
Nombre: Santiago Jimenez Garcia
Fecha: 02 de Mayo de 2024
Programa: Ejercicio 9
Centro Universitario de los Altos / Universidad de Guadalajara
INGENIERIA EN COMPUTACION SEGUNDO SEMESTRE
Profesor: CARLOS JAVIER CRUZ FRANCO
Descripcion:
-Crea un programa que te permita ingresar al menos 5 datos a un arreglo
-Deberás mostrar los datos que se encuentran en el arreglo
-Para mostrar los datos no debes implementar ciclos
-Deberás crear una función recursiva para que muestre los datos que están guardado dentro del arreglo
***************************/
#include <iostream>
using namespace std;

void ingresarDatos(int arreglo[], int indice, int tamano) {
    if (indice < tamano) {
        cout << "Ingrese el dato " << (indice + 1) << ": ";
        cin >> arreglo[indice];
        ingresarDatos(arreglo, indice + 1, tamano);
    }
}

void mostrarElementos(int arreglo[], int indice, int tamano) {
    if (indice < tamano) {
        cout << arreglo[indice] << endl;
        mostrarElementos(arreglo, indice + 1, tamano);
    }
}

int main() {
    const int tamano = 5;
    int arreglo[tamano];

    ingresarDatos(arreglo, 0, tamano);

    cout << "Los datos ingresados son:" << endl;
    mostrarElementos(arreglo, 0, tamano);

    return 0;
}

