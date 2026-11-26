#ifndef CLSCOMPRA_H
#define CLSCOMPRA_H
#include "clsFechaHora.h"

class Compra
{
private:
    int _idCompra;
    int _idSocio;
    int _idSala;
    FechaHora _fecha;
    bool _estado;

public:
    Compra();
    void setIdCompra(int ID);
    void setIdSocio(int ID);
    void setIdSala(int ID);
    void setFecha(FechaHora fechaCompra);
    void setEstado(bool estado);

    int getIdCompra();
    int getIdSocio();
    int getIdSala();
    FechaHora getFecha();
    bool getEstado();

    void cargar();
    void mostrar();
};

#endif // CLSCOMPRA_H
