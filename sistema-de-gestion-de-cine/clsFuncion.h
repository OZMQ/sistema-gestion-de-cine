#ifndef CLSFUNCION_H
#define CLSFUNCION_H
#include "clsFechaHora.h"
#include "clsHora.h"

class Funcion
{
private:
    int _idFuncion;
    int _idPelicula;
    int _idSala;
    FechaHora _fechaHora;
    bool _estado;

public:
    Funcion();
    ~Funcion();
    void setIdFuncion(int idFuncion);
    void setIdPelicula(int idPelicula);
    void setIdSala(int idSala);
    void setFechaHora(FechaHora fecha);
    void setEstado(bool estado);
    int getIdFuncion();
    int getIdPelicula();
    int getIdSala();
    FechaHora getFechaHora();
    bool getEstado();
    void cargar();
    void mostrar();
    void modificar();
};

#endif
