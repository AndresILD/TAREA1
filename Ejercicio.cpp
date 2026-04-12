#include "Ejercicio.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;
Ejercicio::Ejercicio() {}

Ejercicio::Ejercicio(int c, string n, string t, string ni, int te, string d, int u) {
    codigoIdentificador = c;
    nombreEjercicio = n;
    tipoEjercicio = t;
    nivelIntensidad = ni;
    tiempoEstimado = te;
    descripcionEjecucion = d;
    ultimaFecha = u;
}

Ejercicio::~Ejercicio() {}

int Ejercicio::getCodigo() { return codigoIdentificador; }
string Ejercicio::getNivel() { return nivelIntensidad; }
int Ejercicio::getTiempo() { return tiempoEstimado; }
int Ejercicio::getUltimaFecha() { return ultimaFecha; }
string Ejercicio::getNombre() { return nombreEjercicio; }

void Ejercicio::setUltimaFecha(int semana) { ultimaFecha = semana; }

void Ejercicio::crear() {
    cout << "Codigo Identificador: "; cin >> codigoIdentificador;
    cout << "Nombre del ejercicio: "; getline(cin >> ws, nombreEjercicio);
    cout << "Tipo: "; getline(cin, tipoEjercicio);
    cout << "Nivel de Intensidad: "; getline(cin, nivelIntensidad);
    cout << "Tiempo en min: "; cin >> tiempoEstimado;
    cout << "Descripcion: "; getline(cin >> ws, descripcionEjecucion);
    cout << "Semana uso: "; cin >> ultimaFecha;
}

void Ejercicio::actualizar() {
    cout << "Nuevo nombre: "; getline(cin >> ws, nombreEjercicio);
    cout << "Nuevo nivel: "; getline(cin, nivelIntensidad);
    cout << "Nuevo tiempo: "; cin >> tiempoEstimado;
    cout << "Nueva descripcion: "; getline(cin >> ws, descripcionEjecucion);
}

void Ejercicio::mostrar() {
    cout << "ID: " << codigoIdentificador << endl;
    cout << "Nombre: " << nombreEjercicio << endl;
    cout << "Nivel: " << nivelIntensidad << endl;
    cout << "Tiempo: " << tiempoEstimado << endl;
}

void Ejercicio::mostrarResumen() {
    cout << nombreEjercicio << " (" << tiempoEstimado << " min)" << endl;
}

Cardio::Cardio() : Ejercicio() {
    tipoEjercicio = "Cardio";
}

Fuerza::Fuerza() : Ejercicio() {
    tipoEjercicio = "Fuerza";
}
