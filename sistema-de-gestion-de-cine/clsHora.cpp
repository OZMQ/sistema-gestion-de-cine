#include <iostream>
#include <iomanip>
#include "clsHora.h"

using namespace std;

Hora::Hora(int h, int m)
{
    hora = h;
    minutos = m;
}

void Hora::horaActual()
{
    time_t t = time(nullptr);
    tm* ahora = localtime(&t);

    hora = ahora->tm_hour;
    minutos = ahora->tm_min;
}

void Hora::setHora(int h)
{
    hora = h;
}

void Hora::setMinutos(int m)
{
    minutos = m;
}

int Hora::getHora()
{
    return hora;
}

int Hora::getMinutos()
{
    return minutos;
}

void Hora::Cargar()
{
    do
    {
        cin >> hora >> minutos;
        if (hora < 0 || hora > 23 || minutos < 0 || minutos > 59)
        {
            cout << "Hora incorrecta, intente de nuevo." << endl;
        }
    }
    while (hora < 0 || hora > 23 || minutos < 0 || minutos > 59);
}

void Hora::Mostrar()
{
    cout << setfill('0') << setw(2) << hora << ":" << setw(2) << minutos;
    cout << setfill(' ');
}

bool Hora::operator==(Hora h)
{
    return hora == h.hora && minutos == h.minutos;
}

Hora::~Hora()
{
}

bool Hora::operator>(Hora h)
{
    if (hora > h.hora) return true;
    if (hora == h.hora && minutos > h.minutos) return true;
    return false;
}

bool Hora::operator<(Hora h)
{
    if (hora < h.hora) return true;
    if (hora == h.hora && minutos < h.minutos) return true;
    return false;
}
