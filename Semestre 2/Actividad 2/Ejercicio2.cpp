/*******Presentacion*******
Nombre: Santiago Jimenez Garcia
Fecha: 24 de Enero de 2024
Programa: Actividad1
Centro Universitario de los Altos / Universidad de Guadalajara
INGENIERIA EN COMPUTACION SEGUNDO SEMESTRE
Profesor:
Descripcion:
***************************/
#include <iostream>
using namespace std;

int main(){
    int menu;
    int Numero1;
    int Numero2;
    int suma;
    char car;
    double res;
    string nombre;

    while(true)
    {
        cout << "######################################################"<<endl;
        cout << "Bienvenido al menu" << endl;
        cout << "1- Suma de numeros enteros\n" << endl;
        cout << "2- Ingresar e imprimir caracter" << endl;
        cout << "3- Division" << endl;
        cout << "4- Numero octal" << endl;
        cout << "5- Numero hexa" << endl;
        cout << "6- String" << endl;
        cout << "Ingrese una opcion del menu: ";
        cin >> menu;
        cout << "######################################################"<<endl;
        cin.ignore();

        switch(menu)
        {
            case 1:
                cout << "Ingrese los numeros a sumar: ";
                cin >> Numero1 >> Numero2;
                suma = Numero1 + Numero2;
                cout << "El total de la suma es: " << suma << endl;
                break;
            case 2:
                cout << "Ingresa el caracter a imprimir: ";
                cin >> car;
                cout << "El caracter ingresado es: " << car << endl;
                break;
            case 3:
                cout << "Ingresa el dividendo: ";
                cin >> Numero2;
                cout << "Ingresa el divisor: ";
                cin >> Numero1;
                res = static_cast<double>(Numero2) / Numero1;
                cout << "El resultado es: " << res << endl;
                break;
            case 4:
                cout << "Ingresa el numero a convertir: ";
                cin >> Numero1;
                cout << "El numero en octal es: " << oct << Numero1 << endl;
                break;
            case 5:
                cout << "Ingresa el numero a convertir: ";
                cin >> Numero1;
                cout << "El numero en hexadecimal es: " << hex << Numero1 << endl;
                break;
            case 6:
                cout << "Ingresa tu Nombre: ";
                getline(cin, nombre);
                cout << "Tu nombre es: " << nombre << endl;
                break;
            default:
                cout << "Opción inválida, por favor ingrese una opción válida." << endl;
                break;
        }
    }
    return 0;
}
