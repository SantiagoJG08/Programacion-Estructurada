#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
#include <algorithm>

using namespace std;

// Estructura que define un Alumno
struct Alumno {
    string nombre;  // Nombre del alumno
    string carrera; // Carrera del alumno
    vector<string> materias; // Materias del alumno
    vector<float> calificaciones; // Calificaciones del alumno
};

// Declaración de funciones
void agregarAlumno();
void editarAlumno();
void borrarAlumno();
void mostrarMenu();
void guardarAlumnos();
void cargarAlumnos();
void imprimirAlumnos();
void capturarCalificaciones(Alumno &alumno);
float calcularPromedio(const Alumno &alumno);
string determinarEstado(float promedio);

// Vector global que almacena todos los alumnos
vector<Alumno> alumnos;

// Función que muestra el menú principal
void mostrarMenu() {
    int opcion;
    do {
        cout << "==============================================================" << endl;
        cout << "Menu:" << endl;
        cout << "1. Agregar alumno" << endl;
        cout << "2. Editar alumno" << endl;
        cout << "3. Borrar alumno" << endl;
        cout << "4. Mostrar alumnos" << endl;
        cout << "5. Salir" << endl;
        cout << "==============================================================" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada

        // Selección de opción en el menú
        switch (opcion) {
        case 1:
            agregarAlumno();
            break;
        case 2:
            editarAlumno();
            break;
        case 3:
            borrarAlumno();
            break;
        case 4:
            imprimirAlumnos();
            break;
        case 5:
            guardarAlumnos();
            cout << "==============================================================" << endl;
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "==============================================================" << endl;
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);
}

// Función para agregar un nuevo alumno
void agregarAlumno() {
    Alumno nuevoAlumno;
    cout << "==============================================================" << endl;
    cout << "Ingrese el nombre del alumno: ";
    getline(cin, nuevoAlumno.nombre);
    cout << "==============================================================" << endl;
    cout << "Ingrese la carrera del alumno: ";
    getline(cin, nuevoAlumno.carrera);
    capturarCalificaciones(nuevoAlumno); // Captura las calificaciones del alumno
    alumnos.push_back(nuevoAlumno); // Agrega el nuevo alumno al vector
}

// Función para capturar las calificaciones de un alumno
void capturarCalificaciones(Alumno &alumno) {
    string materia;
    float calificacion;
    char continuar;

    do {
        cout << "==============================================================" << endl;
        cout << "Ingrese una materia: ";
        getline(cin, materia);
        alumno.materias.push_back(materia);
        cout << "==============================================================" << endl;
        cout << "Ingrese la calificacion de " << materia << ": ";
        cin >> calificacion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
        alumno.calificaciones.push_back(calificacion);
        cout << "==============================================================" << endl;
        cout << "Desea ingresar otra materia y calificacion? (s/n): ";
        cin >> continuar;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada

    } while (continuar == 's' || continuar == 'S');
}

// Función para editar un alumno existente
void editarAlumno() {
    string nombre;
    cout << "==============================================================" << endl;
    cout << "Ingrese el nombre del alumno que desea editar: ";
    getline(cin, nombre);

    bool encontrado = false;

    // Editar en el archivo de texto
    ifstream archivoEntrada("alumnos.txt");
    ofstream archivoTemporal("temp.txt");

    if (archivoEntrada.is_open() && archivoTemporal.is_open()) {
        string linea;
        while (getline(archivoEntrada, linea)) {
            if (linea.find("Nombre: ") != string::npos && linea.substr(8) == nombre) {
                // Encontrar al alumno, solicitar nuevas entradas
                encontrado = true;
                Alumno alumnoNuevo;
                alumnoNuevo.nombre = nombre;
                cout << "==============================================================" << endl;
                cout << "Ingrese la nueva carrera del alumno: ";
                getline(cin, alumnoNuevo.carrera);
                capturarCalificaciones(alumnoNuevo); // Capturar las nuevas materias y calificaciones
                // Escribir los datos del alumno actualizados en el archivo temporal
                archivoTemporal << "Nombre: " << alumnoNuevo.nombre << endl;
                archivoTemporal << "Carrera: " << alumnoNuevo.carrera << endl;
                archivoTemporal << "Materias y Califcaciones: " << endl;
                for (size_t i = 0; i < alumnoNuevo.materias.size(); ++i) {
                    archivoTemporal << alumnoNuevo.materias[i] << ": " << alumnoNuevo.calificaciones[i] << endl;
                }
                archivoTemporal << "Promedio: ";
                float promedio = calcularPromedio(alumnoNuevo);
                archivoTemporal << fixed << setprecision(2) << promedio << " (" << determinarEstado(promedio) << ")" << endl;
                // Ignorar las líneas correspondientes al alumno antiguo
                for (int i = 0; i < 4; ++i) {
                    getline(archivoEntrada, linea);
                }
            } else {
                archivoTemporal << linea << endl;
            }
        }

        archivoEntrada.close();
        archivoTemporal.close();

        // Si se encontró y editó el alumno, reemplazar el archivo original
        if (encontrado) {
            remove("alumnos.txt");
            rename("temp.txt", "alumnos.txt");
            cout << "Alumno editado correctamente en el archivo." << endl;
        } else {
            remove("temp.txt");
            cout << "Alumno no encontrado en el archivo." << endl;
        }
    } else {
        cout << "Error: no se pudo abrir el archivo." << endl;
    }

    // Editar en la memoria del programa
    for (auto &alumno : alumnos) {
        if (alumno.nombre == nombre) {
            encontrado = true;
            cout << "==============================================================" << endl;
            cout << "Ingrese la nueva carrera del alumno: ";
            getline(cin, alumno.carrera);
            alumno.materias.clear();        // Limpiar las materias existentes
            alumno.calificaciones.clear();  // Limpiar las calificaciones existentes
            capturarCalificaciones(alumno); // Capturar las nuevas materias y calificaciones
            cout << "Alumno editado correctamente en la memoria del programa." << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Alumno no encontrado en la memoria del programa." << endl;
    }
}

// Función para borrar un alumno existente
void borrarAlumno() {
    string nombre;
    cout << "==============================================================" << endl;
    cout << "Ingrese el nombre del alumno que desea borrar: ";
    getline(cin, nombre);

    bool encontrado = false;

    // Eliminar del archivo de texto
    ifstream archivoEntrada("alumnos.txt");
    ofstream archivoTemporal("temp.txt");

    if (archivoEntrada.is_open() && archivoTemporal.is_open()) {
        string linea;
        while (getline(archivoEntrada, linea)) {
            if (linea.find("Nombre: ") != string::npos && linea.substr(8) == nombre) {
                // Ignorar las líneas correspondientes al alumno a borrar
                for (int i = -1; i < 6; ++i) {
                    getline(archivoEntrada, linea);
                }
                encontrado = true;
            } else {
                archivoTemporal << linea << endl;
            }
        }

        archivoEntrada.close();
        archivoTemporal.close();

        // Si se encontró y borró el alumno, reemplazar el archivo original
        if (encontrado) {
            remove("alumnos.txt");
            rename("temp.txt", "alumnos.txt");
            cout << "Alumno borrado correctamente del archivo." << endl;
        } else {
            remove("temp.txt");
            cout << "Alumno no encontrado en el archivo." << endl;
        }
    } else {
        cout << "Error: no se pudo abrir el archivo." << endl;
    }

    // Eliminar de la memoria del programa
    auto it = remove_if(alumnos.begin(), alumnos.end(), [&](const Alumno &alumno) {
        return alumno.nombre == nombre;
    });

    if (it != alumnos.end()) {
        alumnos.erase(it, alumnos.end());
        cout << "Alumno borrado correctamente de la memoria del programa." << endl;
    } else {
        cout << "Alumno no encontrado en la memoria del programa." << endl;
    }
}

// Función para guardar los alumnos en un archivo
void guardarAlumnos() {
    ofstream archivo("alumnos.txt", ios::app);
    if (archivo.is_open()) {
        for (const auto &alumno : alumnos) {
            archivo << "==============================================================" << endl;
            archivo << "Nombre: " << alumno.nombre << endl;
            archivo << "Carrera: " << alumno.carrera << endl;
            archivo << "Materias y Calificaciones:" << endl;
            for (size_t i = 0; i < alumno.materias.size(); ++i) {
                archivo << alumno.materias[i] << ": " << alumno.calificaciones[i] << endl;
            }
            float promedio = calcularPromedio(alumno);
            archivo << "Promedio: " << fixed << setprecision(2) << promedio << " (" << determinarEstado(promedio) << ")" << endl;
            archivo << "==============================================================" << endl;
            archivo << endl;
        }
        archivo.close();
        cout << "Alumnos guardados en el archivo 'alumnos.txt'." << endl;
    } else {
        cout << "No se pudo abrir el archivo para guardar." << endl;
    }
}

// Función para cargar los alumnos desde un archivo
void cargarAlumnos() {
    ifstream archivo("alumnos.txt");
    if (archivo.is_open()) {
        Alumno alumno;
        string linea;
        while (getline(archivo, linea)) {
            if (linea.find("Nombre: ") != string::npos) {
                if (linea.size() > 8)
                    alumno.nombre = linea.substr(8);
            } else if (linea.find("Carrera: ") != string::npos) {
                if (linea.size() > 9)
                    alumno.carrera = linea.substr(9);
            } else if (linea.find(":") != string::npos) {
                size_t pos = linea.find(":");
                if (pos != string::npos && pos + 2 < linea.size()) {
                    alumno.materias.push_back(linea.substr(0, pos));
                    alumno.calificaciones.push_back(stof(linea.substr(pos + 2)));
                }
            } else if (linea.find("Promedio:") != string::npos) {
                alumnos.push_back(alumno);
                alumno.materias.clear();
                alumno.calificaciones.clear();
            }
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para cargar." << endl;
    }
}

// Función para calcular el promedio de calificaciones de un alumno
float calcularPromedio(const Alumno &alumno) {
    float suma = 0;
    for (float calificacion : alumno.calificaciones) {
        suma += calificacion;
    }
    return suma / alumno.calificaciones.size();
}

// Función para determinar el estado de un alumno basado en su promedio
string determinarEstado(float promedio) {
    if (promedio < 60) {
        return "Reprobado";
    } else if (promedio >= 60 && promedio < 80) {
        return "Regular";
    } else if (promedio >= 80 && promedio < 90) {
        return "Muy bien";
    } else {
        return "Excelente";
    }
}

// Función para imprimir la lista de alumnos
void imprimirAlumnos() {
    cout << "==============================================================" << endl;
    cout << "Lista de alumnos:" << endl;
    for (const auto &alumno : alumnos) {
        cout << alumno.nombre << endl;
    }
}
