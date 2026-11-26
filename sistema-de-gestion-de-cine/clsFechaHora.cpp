#include <iostream>
#include <iomanip>
#include "clsFechaHora.h"
using namespace std;

FechaHora::FechaHora(int a, int m, int d, int h, int min)
{
    anio = a;
    mes = m;
    dia = d;
    hora = h;
    minutos = min;
}

FechaHora::~FechaHora()
{
}

void FechaHora::fechaHoraActual()
{
    time_t t = time(nullptr);
    tm* ahora = localtime(&t);

    anio = ahora->tm_year + 1900;
    mes = ahora->tm_mon + 1;
    dia = ahora->tm_mday;
    hora = ahora->tm_hour;
    minutos = ahora->tm_min;
}

void FechaHora::setAnio(int a) { anio = a; }
void FechaHora::setMes(int m) { mes = m; }
void FechaHora::setDia(int d) { dia = d; }
void FechaHora::setHora(int h) { hora = h; }
void FechaHora::setMinutos(int min) { minutos = min; }

int FechaHora::getAnio() { return anio; }
int FechaHora::getMes() { return mes; }
int FechaHora::getDia() { return dia; }
int FechaHora::getHora() { return hora; }
int FechaHora::getMinutos() { return minutos; }

void FechaHora::Cargar()
{
    bool fechaInvalida;
    do
    {
        cout << "Ingrese fecha (dd mm aaaa): ";
        cin >> dia >> mes >> anio;
        fechaInvalida = (dia <= 0 || dia > 31 ||
                         mes <= 0 || mes > 12 ||
                         anio < 0);
        if (fechaInvalida)
        {
            cout << "Fecha incorrecta, intente de nuevo." << endl;
        }
        else
        {
            bool horaInvalida;
            do
            {
                cout << "Ingrese hora (hh mm): ";
                cin >> hora >> minutos;
                horaInvalida = (hora < 0 || hora > 23 ||
                                minutos < 0 || minutos > 59);
                if (horaInvalida)
                {
                    cout << "Hora incorrecta, intente de nuevo." << endl;
                }
            } while (horaInvalida);
        }
    } while (fechaInvalida);
}

void FechaHora::Mostrar()
{
    cout << setfill('0')
         << setw(2) << dia << "/"
         << setw(2) << mes << "/"
         << anio << " "
         << setw(2) << hora << ":"
         << setw(2) << minutos
         << setfill(' ');
}

bool FechaHora::operator==(FechaHora fh)
{
    return anio == fh.anio &&
           mes == fh.mes &&
           dia == fh.dia &&
           hora == fh.hora &&
           minutos == fh.minutos;
}

bool FechaHora::operator>(FechaHora fh)
{
    if (anio != fh.anio) return anio > fh.anio;
    if (mes != fh.mes) return mes > fh.mes;
    if (dia != fh.dia) return dia > fh.dia;
    if (hora != fh.hora) return hora > fh.hora;
    return minutos > fh.minutos;
}

bool FechaHora::operator<(FechaHora fh)
{
    if (anio != fh.anio) return anio < fh.anio;
    if (mes != fh.mes) return mes < fh.mes;
    if (dia != fh.dia) return dia < fh.dia;
    if (hora != fh.hora) return hora < fh.hora;
    return minutos < fh.minutos;
}
