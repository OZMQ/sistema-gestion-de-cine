#include <iostream>
#include "clsCompra.h"
#include "clsArchivoCompras.h"
#include "clsArchivoSocios.h"
#include "clsArchivoSalas.h"

using namespace std;

Compra::Compra()
{
    _idCompra = 0;
    _idSocio = 0;
    _idSala = 0;
    _fecha = FechaHora();
    _estado = true;
}

void Compra::setIdCompra(int ID)
{
    _idCompra = ID;
}

void Compra::setIdSocio(int ID)
{
    _idSocio = ID;
}

void Compra::setIdSala(int ID)
{
    _idSala = ID;
}

void Compra::setFecha(FechaHora fechaCompra)
{
    _fecha = fechaCompra;
}

void Compra::setEstado(bool estado)
{
    _estado = estado;
}

int Compra::getIdCompra()
{
    return _idCompra;
}

int Compra::getIdSocio()
{
    return _idSocio;
}

int Compra::getIdSala()
{
    return _idSala;
}

FechaHora Compra::getFecha()
{
    return _fecha;
}

bool Compra::getEstado()
{
    return _estado;
}

void Compra::cargar()
{
    ArchivoCompras arcCompras;
    ArchivoSocios arcSocios;
    ArchivoSalas arcSalas;

    do
    {
        cout << "ID Compra: ";
        cin >> _idCompra;

        if (_idCompra <= 0)
        {
            cout << "Error, el ID de la compra tiene que ser mayor a 0, intente de nuevo." << endl;
        }
        else if (arcCompras.buscarRegistro(_idCompra) != -1 || arcCompras.buscarRegistroInactivo(_idCompra) != -1)
        {
            cout << "Error, ya existe una compra registrada con ese ID, intente de nuevo." << endl;
            _idCompra = 0;
        }
    }
    while (_idCompra <= 0);

    do
    {
        cout << "ID Socio: ";
        cin >> _idSocio;

        if (_idSocio <= 0)
        {
            cout << "Error, el ID del socio tiene que ser mayor a 0, intente de nuevo." << endl;
        }
        else
        {
            int posSocio = arcSocios.buscarRegistro(_idSocio);
            if (posSocio == -1 || arcSocios.leerRegistro(posSocio).getEstado() == false)
            {
                cout << "Error, no existe un socio activo con ese ID, intente de nuevo." << endl;
                _idSocio = 0;
            }
        }
    }
    while (_idSocio <= 0);

    do
    {
        cout << "ID Sala: ";
        cin >> _idSala;

        if (_idSala <= 0)
        {
            cout << "Error, el ID de la sala tiene que ser mayor a 0, intente de nuevo." << endl;
        }
        else
        {
            int posSala = arcSalas.buscarRegistro(_idSala);
            if (posSala == -1 || arcSalas.leerRegistro(posSala).getEstado() == false)
            {
                cout << "Error, no existe una sala activa con ese ID, intente de nuevo." << endl;
                _idSala = 0;
            }
        }
    }
    while (_idSala <= 0);

    _fecha.fechaHoraActual();
    _estado = true;
}

void Compra::mostrar()
{
    if (_estado == false) return;

    cout << "ID Compra: " << _idCompra << endl;

    ArchivoSocios archs;
    int posS = archs.buscarRegistro(_idSocio);
    if (posS != -1)
    {
        Socio s = archs.leerRegistro(posS);
        cout << "ID Socio: " << _idSocio << " | Socio: " << s.getNombre() << " " << s.getApellido() << endl;
    }

    cout << "ID Sala: " << _idSala << endl;
    cout << "Fecha y Hora de Compra: ";
    _fecha.Mostrar();
    cout << endl;
}
