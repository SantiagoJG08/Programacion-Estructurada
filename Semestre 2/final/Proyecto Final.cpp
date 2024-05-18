/***********Presentacion.***********
 * Nombre: Angel ALexis Serrano Hernandez, Santiago Jimenes Garcia.
 * Fecha: 17/05/2024
 * Programa: Proyecto final.cpp
 * CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSDAD DE GUADALAJARA.
 * INGENIERIA EN COMPUTACION / 2DO SEMESTRE.
 * Profesor: Carlos Javier Cruz Franco.
 * Descripccion: Simulacion de Base de datos
 *************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
#include <algorithm>
#include "libreria.cpp"

using namespace std;

int main()
{
    cargarAlumnos();
    mostrarMenu();
    return 0;
}