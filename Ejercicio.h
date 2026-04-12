#include <iostream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Ejercicio {
private:
    int codigoIdentificador;
    string nombreEjercicio;
    string nivelIntensidad;
    string tipoEjercicio;
    int tiempoEstimado;
    string descripcionEjecucion;
    int ultimaFecha;

public:
    Ejercicio();
    Ejercicio(int c, string n, string t, string ni, int te, string d, int u);
    virtual ~Ejercicio();

    int getCodigo();
    string getNivel();
    int getTiempo();
    int getUltimaFecha();
    string getNombre();

    void setUltimaFecha(int semana);

    void crear();
    void actualizar();
    void mostrar();
    void mostrarResumen();
};

class Cardio : public Ejercicio {
public:
    Cardio();
};

class Fuerza : public Ejercicio {
public:
    Fuerza();
};



