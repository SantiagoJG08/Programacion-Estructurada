/*******Presentacion*******
Nombre: Santiago Jimenez Garcia
Fecha: 02 de Febrero de 2024
Programa: Actividad 3
Centro Universitario de los Altos / Universidad de Guadalajara
INGENIERIA EN COMPUTACION SEGUNDO SEMESTRE
Profesor: CARLOS JAVIER CRUZ FRANCO
Descripcion: Si el número es mayor a 0 y menor a 500, subir de 5 en 5, 100 veces.
Si el número es mayor a 500 y menor a 1000, subir el número de 10 en 10, 50 veces
Si el número es mayor a 1000, “No se puede calcular el valor”.
Debe hacer un ciclo en donde pregunte si desea terminar el programa.
Contar con las veces que realizó una operación.

***************************/
#include <iostream>

using namespace std;

int main() {
    int numero;
    int numero1;
    int num = 0;
    int Veces = 0;
    int term;

    do {
        // Solicitar un número al usuario
        cout << "Ingrese un numero: ";
        cin >> numero1;

        // Verificar las condiciones y realizar las operaciones correspondientes
        if (numero1 > 0 && numero1 < 500) {
            for (int i = 0; i < 100; ++i) {
                numero += 5;
                cout << numero << endl;
            }
        } else if (numero1 > 500 && numero1 < 1000) {
            for (int i = 0; i < 50; ++i) {
                num += 10;
                cout << num << endl;
            }
        } else if (numero1 > 1000 && numero1<0) {
            cout << "No se puede calcular el valor." << endl;
        }
        Veces++;
        cout<<"deseas terminar"<<endl;
        cout<<"1.- No"<<endl;
        cout<<"2.- Si"<<endl;
        cin>>term;
    } while (term<2);

    // Mostrar el número final y la cantidad de operaciones realizadas
    cout << "Veces utilizado: " << Veces << endl;

    return 0;
}
