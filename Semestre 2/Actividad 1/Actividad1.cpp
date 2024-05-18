/*******Presentacion*******
Nombre: Santiago Jimenez Garcia
Fecha: 24 de Enero de 2024
Programa: Actividad 1
Centro Universitario de los Altos / Universidad de Guadalajara
INGENIERIA EN COMPUTACION SEGUNDO SEMESTRE
Profesor: CARLOS JAVIER CRUZ FRANCO
Descripcion:Pedir e Imprimir Nombre, Edad, Lugar de residencia, Fecha de nacimiento, Carrera
Semestre
***************************/
#include <iostream>
using namespace std;

int main() {
    // Declaracion de variables
    string nombre, Residencia, fechaN, carrera;
    int edad, semestre;

    // Solicitar datos al usuario
    cout << "Ingresa tu Nombre\n";
    getline(cin, nombre);

    cout << "Ingresa tu Edad\n";
    cin >> edad;
    cin.ignore(); // Limpiar el buffer de entrada

    cout << "Ingresa tu Lugar de residencia\n";
    getline(cin, Residencia);

    cout << "Ingresa tu Fecha de nacimiento\n";
    getline(cin, fechaN);

    cout << "Ingresa tu Carrera\n";
    getline(cin, carrera);

    cout << "Ingresa tu Semestre\n";
    cin >> semestre;

    // Imprimir los datos ingresados
    cout << "\n**************************************\n";
    cout << "\nLos datos ingresados son:\n";
    cout << "Nombre: " << nombre << "\n";
    cout << "Edad: " << edad << "\n";
    cout << "Lugar de residencia: " << Residencia << "\n";
    cout << "Fecha de nacimiento: " << fechaN << "\n";
    cout << "Carrera: " << carrera << "\n";
    cout << "Semestre: " << semestre << "\n";

    return 0;
}