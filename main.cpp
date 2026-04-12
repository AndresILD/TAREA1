#include <vector>
#include <iostream>
#include <string>
#include "Ejercicio.h"

using namespace std;

int main() {
    vector<Ejercicio*> catalogo;
    int opcion;
    int semanaActual = 2;

    cout << "\n----- MENU -----\n";
    cout << "1. Crear ejercicio\n";
    cout << "2. Actualizar ejercicio\n";
    cout << "3. Eliminar ejercicio\n";
    cout << "4. Mostrar ejercicio\n";
    cout << "5. Buscar por nivel\n";
    cout << "6. Generar rutina\n";
    cout << "0. Salir\n";
    cout << "Opcion: ";
    cin >> opcion;

    while(opcion != 0) {

        switch(opcion) {

        case 1: {
            int tipo;
            cout << "Tipo (1.Cardio, 2.Fuerza): ";
            cin >> tipo;

            Ejercicio* e;
            if(tipo == 1) {
                e = new Cardio();
            } else {
                e = new Fuerza();
            }

            e->crear();
            catalogo.push_back(e);
            break;
        }

        case 2: {
            int id;
            cout << "ID a actualizar: ";
            cin >> id;

            for(size_t i = 0; i < catalogo.size(); i++) {
                if(catalogo[i]->getCodigo() == id) {
                    catalogo[i]->actualizar();
                }
            }
            break;
        }

        case 3: {
            int id;
            cout << "ID a eliminar: ";
            cin >> id;

            for(size_t i = 0; i < catalogo.size(); i++) {
                if(catalogo[i]->getCodigo() == id) {
                    delete catalogo[i];
                    catalogo.erase(catalogo.begin() + i);
                    cout << "Eliminado correctamente\n";
                    break;
                }
            }
            break;
        }

        case 4: {
            int id;
            cout << "ID a mostrar: ";
            cin >> id;

            for(size_t i = 0; i < catalogo.size(); i++) {
                if(catalogo[i]->getCodigo() == id) {
                    catalogo[i]->mostrar();
                }
            }
            break;
        }

        case 5: {
            string nivel;
            cout << "Nivel: ";
            cin.ignore();
            getline(cin, nivel);

            for(size_t i = 0; i < catalogo.size(); i++) {
                if(catalogo[i]->getNivel() == nivel) {
                    catalogo[i]->mostrarResumen();
                }
            }
            break;
        }

        case 6: {
            string nivel;
            int cantidad, total = 0, cont = 0;
            vector<Ejercicio*> rutina;

            cout << "Nivel: ";
            cin.ignore();
            getline(cin, nivel);

            cout << "Cantidad: ";
            cin >> cantidad;

            for(size_t i = 0; i < catalogo.size(); i++) {
                if(catalogo[i]->getNivel() == nivel &&
                   catalogo[i]->getUltimaFecha() != semanaActual - 1) {

                    rutina.push_back(catalogo[i]);
                    total += catalogo[i]->getTiempo();
                    catalogo[i]->setUltimaFecha(semanaActual);
                    cont++;

                    if(cont == cantidad) break;
                }
            }

            cout << "\n--- RUTINA ---\n";
            for(size_t i = 0; i < rutina.size(); i++) {
                rutina[i]->mostrarResumen();
            }

            cout << "Total: " << total << " min\n";
            break;
        }

        default:
            cout << "Opcion invalida\n";
        }

        cout << "\n----- MENU -----\n";
        cout << "1. Crear ejercicio\n";
        cout << "2. Actualizar ejercicio\n";
        cout << "3. Eliminar ejercicio\n";
        cout << "4. Mostrar ejercicio\n";
        cout << "5. Buscar por nivel\n";
        cout << "6. Generar rutina\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
    }

    for(size_t i = 0; i < catalogo.size(); i++) {
        delete catalogo[i];
    }

    return 0;
}
