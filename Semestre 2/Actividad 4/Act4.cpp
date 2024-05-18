/*******Presentacion*******
Nombre: Santiago Jimenez Garcia
Fecha: 09 de Febrero de 2024
Programa: Ejercicio 4
Centro Universitario de los Altos / Universidad de Guadalajara
INGENIERIA EN COMPUTACION SEGUNDO SEMESTRE
Profesor: CARLOS JAVIER CRUZ FRANCO
Descripcion:Imprimir la secuencia de Fibonacci hasta el numero indicado
***************************/
#include <iostream>
using namespace std;

int main() {
    int a, b, c, opc, term, count;

    // Ciclo principal para repetir el programa según la opción del usuario
    do {
        // Inicialización de variables
        a = 0;
        b = 1;
        c = 0;

        // Menú de opciones
        cout << "***************************" << endl;
        cout << "Opciones" << endl;
        cout << "1.- Usar For" << endl;
        cout << "2.- Usar While" << endl;
        cout << "3.- Usar Do While" << endl;
        cin >> opc;

        // Solicitar al usuario el número máximo
        cout << "Hasta que numero debe llegar: ";
        cin >> count;
        cout << "***************************" << endl;

        // Selección de la opción del usuario
        switch (opc) {
            case 1:
                // Uso del bucle for
                for (c = 0; c < count;) { // Incremento de c en el cuerpo del bucle
                    cout << c << endl;
                    c = a + b;
                    a = b;
                    b = c;
                }
                break;

            case 2:
                // Uso del bucle while
                while (c <= count) {
                    cout << c << endl;
                    c = a + b;
                    a = b;
                    b = c;
                }
                break;

            case 3:
                // Uso del bucle do-while
                do {
                    cout << c << endl;
                    c = a + b;
                    a = b;
                    b = c;
                } while (c <= count);
                break;

            default:
                // Opción inválida
                cout << "Opcion invalida" << endl;
                break;
        }

        // Preguntar al usuario si desea terminar
        cout << "***************************" << endl;
        cout << "¿Deseas continuar?" << endl;
        cout << "1.- si" << endl;
        cout << "2.- no" << endl;
        cin >> term;

    } while (term = 1); // Continuar mientras el usuario no seleccione "No"

    return 0;
}
