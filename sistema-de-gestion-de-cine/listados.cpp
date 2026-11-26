#include <iostream>
#include <vector>
#include <windows.h>
#include "listados.h"
#include "funciones.h"
#include "clsArchivoPeliculas.h"
#include "clsArchivoDescuento.h"
#include "clsArchivoSocios.h"
#include "clsArchivoFormato.h"
#include "clsArchivoSalas.h"
#include "clsArchivoFunciones.h"
#include "clsArchivoCompras.h"
#include "clsArchivoDetalleEntradas.h"
using namespace std;

void listadosPeliculas()
{
    int opcion;
    while (true)
    {
        system("cls");
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                              |" << endl;
        cout << "|             LISTADOS DE PELICULAS            |" << endl;
        cout << "|                                              |" << endl;
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << "     1. LISTADO GENERAL" << endl;
        cout << "     2. ORDENADAS POR NOMBRE" << endl;
        cout << "     3. ORDENADAS POR FECHA DE ESTRENO" << endl;
        cout << "     4. ORDENADAS POR DURACION" << endl;
        cout << "     0. VOLVER" << endl;
        cout << endl;
        cout << "================================================" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << "================================================" << endl;
        system("cls");
        switch (opcion)
        {
        case 1:
            listarPeliculas();
            break;
        case 2:
            listarPeliculasPorNombre();
            break;
        case 3:
            listarPeliculasCronologico();
            break;
        case 4:
            listarPeliculasPorDuracion();
            break;
        case 0:
            return;
        }
    }
}

void listarPeliculas()
{
    ArchivoPeliculas arch;
    if (arch.contarRegistros() == 0)
    {
        cout << "No hay peliculas registradas." << endl << endl;
        system("pause");
        return;
    }
    for (int i = 0; i < arch.contarRegistros(); i++)
    {
        Pelicula obj = arch.leerRegistro(i);
        obj.mostrar();
    }
    cout << endl;
    system("pause");
}

void listarPeliculasPorNombre()
{
    ArchivoPeliculas arch;
    int cant = arch.contarRegistros();

    if (cant <= 0)
    {
        cout << "No hay peliculas registradas en el archivo." << endl;
        system("pause");
        return;
    }
    vector<Pelicula> vecPeliculas;

    for (int i = 0; i < cant; i++)
    {
        Pelicula obj = arch.leerRegistro(i);
        if (obj.getEstado())
        {
            vecPeliculas.push_back(obj);
        }
    }
    int activas = vecPeliculas.size();
    if (activas == 0)
    {
        cout << "No hay peliculas activas para ordenar." << endl;
        system("pause");
        return;
    }
    Pelicula aux;
    for (int i = 0; i < activas-1; i++)
    {
        for (int j = 0; j < activas-1; j++)
        {
            if (strcmp(vecPeliculas[j].getTitulo(), vecPeliculas[j+1].getTitulo()) > 0)
            {
                aux = vecPeliculas[j];
                vecPeliculas[j] = vecPeliculas[j+1];
                vecPeliculas[j+1] = aux;
            }
        }
    }
    cout << " ===============================================================================================================" << endl;
    cout << "                                     PELICULAS ORDENADAS POR NOMBRE     " << endl;
    cout << " ===============================================================================================================" << endl;

    for (int i = 0; i < activas; i++)
    {
        vecPeliculas[i].mostrar();
    }
    cout << endl;
    system("pause");
}

void listarPeliculasCronologico()
{
    ArchivoPeliculas arch;
    int cant = arch.contarRegistros();

    if (cant <= 0)
    {
        cout << "No hay peliculas registradas en el archivo." << endl;
        system("pause");
        return;
    }
    vector<Pelicula> vecPeliculas;

    for (int i = 0; i < cant; i++)
    {
        Pelicula obj = arch.leerRegistro(i);
        if (obj.getEstado())
        {
            vecPeliculas.push_back(obj);
        }
    }
    int activas = vecPeliculas.size();
    if (activas == 0)
    {
        cout << "No hay peliculas activas para ordenar." << endl;
        system("pause");
        return;
    }

    Pelicula aux;
    for (int i = 0; i < activas-1; i++)
    {
        for (int j = 0; j < activas-1 - i; j++)
        {
            if (vecPeliculas[j].getFechaEstreno() > vecPeliculas[j+1].getFechaEstreno())
            {
                aux = vecPeliculas[j];
                vecPeliculas[j] = vecPeliculas[j+1];
                vecPeliculas[j+1] = aux;
            }
        }
    }

    cout << " ===============================================================================================================" << endl;
    cout << "                             PELICULAS ORDENADAS POR FECHA DE ESTRENO"                                            << endl;
    cout << " ===============================================================================================================" << endl;

    for (int i = 0; i < activas; i++)
    {
        vecPeliculas[i].mostrar();
    }
    cout << endl;
    system("pause");
}

void listarPeliculasPorDuracion()
{
    ArchivoPeliculas arch;
    int cant = arch.contarRegistros();

    if (cant <= 0)
    {
        cout << "No hay peliculas registradas en el archivo." << endl;
        system("pause");
        return;
    }
    vector<Pelicula> vecPeliculas;

    for (int i = 0; i < cant; i++)
    {
        Pelicula obj = arch.leerRegistro(i);
        if (obj.getEstado())
        {
            vecPeliculas.push_back(obj);
        }
    }
    int activas = vecPeliculas.size();
    if (activas == 0)
    {
        cout << "No hay peliculas activas para ordenar." << endl;
        system("pause");
        return;
    }

    Pelicula aux;
    for (int i = 0; i < activas-1; i++)
    {
        for (int j = 0; j < activas-1 - i; j++)
        {
            if (vecPeliculas[j].getDuracion() > vecPeliculas[j+1].getDuracion())
            {
                aux = vecPeliculas[j];
                vecPeliculas[j] = vecPeliculas[j+1];
                vecPeliculas[j+1] = aux;
            }
        }
    }

    cout << " ===============================================================================================================" << endl;
    cout << "                                 PELICULAS ORDENADAS POR DURACION" << endl;
    cout << " ===============================================================================================================" << endl;

    for (int i = 0; i < activas; i++)
    {
        vecPeliculas[i].mostrar();
    }
    cout << endl;
    system("pause");
}

void listarDescuentos()
{
    ArchivoDescuento arch;
    int cant = arch.cantidadRegistros();
    if (cant == 0)
    {
        cout << "No hay registros activos." << endl;
        system("pause");
        return;
    }
    for (int i = 0; i < cant; i++)
    {
        Descuento obj = arch.leer(i);
        obj.mostrar();
    }
    cout << endl;
    system("pause");
}

void listadosSocios()
{
    int opcion;
    while (true)
    {
        system("cls");
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                              |" << endl;
        cout << "|              LISTADOS DE SOCIOS              |" << endl;
        cout << "|                                              |" << endl;
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << "     1. LISTADO GENERAL" << endl;
        cout << "     2. ORDENADOS DE FORMA ALFABETICA" << endl;
        cout << "     0. VOLVER" << endl;
        cout << endl;
        cout << "================================================" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << "================================================" << endl;
        system("cls");
        switch (opcion)
        {
        case 1:
            listarSocios();
            break;
        case 2:
            listarSociosAlfabetico();
            break;
        case 0:
            return;
            break;
        }
    }
}

void listarSocios()
{
    ArchivoSocios arch;
    int cantidad = arch.contarRegistros();

    if (cantidad == 0)
    {
        cout << "No hay socios cargados." << endl;
        system("pause");
        return;
    }
    for (int i = 0; i < cantidad; i++)
    {
        Socio obj = arch.leerRegistro(i);
        obj.mostrar();
    }
    cout << endl;
    system("pause");
}

void listarSociosAlfabetico()
{
    ArchivoSocios arch;
    int cant = arch.contarRegistros();

    if (cant <= 0)
    {
        cout << "No hay socios registrados en el archivo." << endl;
        system("pause");
        return;
    }
    vector<Socio> vecSocios;

    for (int i = 0; i < cant; i++)
    {
        Socio obj = arch.leerRegistro(i);
        if (obj.getEstado())
        {
            vecSocios.push_back(obj);
        }
    }
    int activos = vecSocios.size();
    if (activos == 0)
    {
        cout << "No hay socios activos para ordenar." << endl;
        system("pause");
        return;
    }
    Socio aux;
    for (int i = 0; i < activos-1; i++)
    {
        for (int j = 0; j < activos-1; j++)
        {
            if (strcmp(vecSocios[j].getApellido(), vecSocios[j+1].getApellido()) > 0)
            {
                aux = vecSocios[j];
                vecSocios[j] = vecSocios[j+1];
                vecSocios[j+1] = aux;
            }
        }
    }
    for (int i = 0; i < activos-1; i++)
    {
        for (int j = 0; j < activos-1; j++)
        {
            if (strcmp(vecSocios[j].getApellido(), vecSocios[j+1].getApellido()) == 0)
            {
                if (strcmp(vecSocios[j].getNombre(), vecSocios[j+1].getNombre()) > 0)
                {
                    aux = vecSocios[j];
                    vecSocios[j] = vecSocios[j+1];
                    vecSocios[j+1] = aux;
                }
            }
        }
    }
    cout << "=======================================" << endl;
    cout << "SOCIOS ORDENADOS DE FORMA ALFABETICA" << endl;
    cout << "=======================================" << endl;

    for (int i = 0; i < activos; i++)
    {
        vecSocios[i].mostrar();
    }
    cout << endl;
    system("pause");
}

void listarFormatos()
{
    ArchivoFormato arch;
    if (arch.contarRegistros() == 0)
    {
        cout << "No hay formatos registrados." << endl << endl;
        system("pause");
        return;
    }
    for (int i = 0; i < arch.contarRegistros(); i++)
    {
        Formato obj = arch.leerRegistro(i);
        obj.mostrar();
    }
    cout << endl;
    system("pause");
}

void listarSalas()
{
    ArchivoSalas arch;
    int cantidad = arch.contarRegistros();

    if (cantidad == 0)
    {
        cout << "No hay salas cargadas." << endl;
        system("pause");
        return;
    }
    for (int i = 0; i < cantidad; i++)
    {
        Sala obj = arch.leerRegistro(i);
        obj.mostrar();
    }
    cout<<endl;
    system("pause");
}

void listarButacas()
{
    ArchivoFunciones archFunciones;
    ArchivoSalas archSalas;
    ArchivoDetalleEntradas archDetalle;
    ArchivoCompras archCompras;
    int idFuncion;

    cout << "Ingrese el ID de la funcion: ";
    cin >> idFuncion;
    int posF = archFunciones.buscarRegistro(idFuncion);
    if (posF == -1)
    {
        cout << "No existe una funcion con ese ID." << endl;
        system("pause");
        return;
    }

    Funcion funcion = archFunciones.leerRegistro(posF);
    if (funcion.getEstado() == false)
    {
        cout << "La funcion seleccionada no esta activa." << endl;
        system("pause");
        return;
    }

    int idSala = funcion.getIdSala();
    int posS = archSalas.buscarRegistro(idSala);
    if (posS == -1)
    {
        cout << "No se encontro la sala asociada a la funcion." << endl;
        system("pause");
        return;
    }

    Sala sala = archSalas.leerRegistro(posS);
    int capacidadTotal = sala.getCapacidadButacas();

    system("cls");
    cout << "=================================================" << endl;
    cout << "   ESTADO DE BUTACAS - FUNCION " << idFuncion << endl;
    cout << "   SALA: " << idSala << " | CAPACIDAD TOTAL: " << capacidadTotal << endl;
    cout << "=================================================" << endl;

    int cantDetalles = archDetalle.contarRegistros();
    int ocupadas = 0;

    cout << "Butacas ocupadas: ";
    for (int j = 0; j < cantDetalles; j++)
    {
        DetalleEntrada d = archDetalle.leerRegistro(j);
        if (d.getIdFuncion() == idFuncion)
        {
            int posC = archCompras.buscarRegistro(d.getIdCompra());
            if (posC != -1 && archCompras.leerRegistro(posC).getEstado())
            {
                if (ocupadas > 0) cout << ", ";
                cout << d.getNumeroButaca();
                ocupadas++;
            }
        }
    }

    if (ocupadas == 0)
    {
        cout << "Ninguna";
    }
    cout << endl;

    int disponibles = capacidadTotal - ocupadas;
    if (disponibles < 0) disponibles = 0;

    cout << "=================================================" << endl;
    cout << "Total de butacas ocupadas:    " << ocupadas << endl;
    cout << "Total de butacas disponibles: " << disponibles << endl;
    cout << "=================================================" << endl;
    system("pause");
}

void listadosFunciones()
{
    int opcion;
    while (true)
    {
        system("cls");
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                                    |" << endl;
        cout << "|               LISTADOS DE FUNCIONES                |" << endl;
        cout << "|                                                    |" << endl;
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << "     1. LISTADO GENERAL" << endl;
        cout << "     2. ORDENADAS POR FECHA Y HORA DE PROYECCION" << endl;
        cout << "     0. VOLVER" << endl;
        cout << endl;
        cout << "=====================================================" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << "=====================================================" << endl;
        system("cls");
        switch (opcion)
        {
        case 1:
            listarFunciones();
            break;
        case 2:
            listarFuncionesCronologico();
            break;
        case 0:
            return;
        }
    }
}

void listarFunciones()
{
    ArchivoFunciones arch;
    int cant = arch.contarRegistros();
    if (cant == 0)
    {
        cout << "No hay funciones registradas." << endl;
        system("pause");
        return;
    }

    cout << "===========================================" << endl;
    cout << "        LISTADO GENERAL DE FUNCIONES         " << endl;
    cout << "===========================================" << endl;

    for (int i = 0; i < cant; i++)
    {
        Funcion obj = arch.leerRegistro(i);
        if (obj.getEstado())
        {
            obj.mostrar();
            cout << "BUTACAS DISPONIBLES: " << butacasDisponibles(obj) << endl;
            cout << "===========================================" << endl;
        }
    }
    cout << endl;
    system("pause");
}

void listarFuncionesCronologico()
{
    ArchivoFunciones arch;
    int cant = arch.contarRegistros();

    if (cant <= 0)
    {
        cout << "No hay funciones registradas en el archivo." << endl;
        system("pause");
        return;
    }
    vector<Funcion> vecFunciones;

    for (int i = 0; i < cant; i++)
    {
        Funcion obj = arch.leerRegistro(i);
        if (obj.getEstado())
        {
            vecFunciones.push_back(obj);
        }
    }
    int activas = vecFunciones.size();
    if (activas == 0)
    {
        cout << "No hay funciones activas para ordenar." << endl;
        system("pause");
        return;
    }
    Funcion aux;
    for (int i = 0; i < activas - 1; i++)
    {
        for (int j = 0; j < activas - 1 - i; j++)
        {
            if (vecFunciones[j].getFechaHora() > vecFunciones[j + 1].getFechaHora())
            {
                aux = vecFunciones[j];
                vecFunciones[j] = vecFunciones[j + 1];
                vecFunciones[j + 1] = aux;
            }
        }
    }

    system("cls");
    cout << "===========================================" << endl;
    cout << "   FUNCIONES ORDENADAS DE FORMA CRONOLOGICA " << endl;
    cout << "===========================================" << endl;

    for (int i = 0; i < activas; i++)
    {
        vecFunciones[i].mostrar();
        cout << "BUTACAS DISPONIBLES: " << butacasDisponibles(vecFunciones[i]) << endl;
        cout << "===========================================" << endl;
    }
cout << endl;
system("pause");
}

void listadosCompras()
{
    int opcion;
    while (true)
    {
        system("cls");
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|                                              |" << endl;
        cout << "|             LISTADOS DE COMPRAS              |" << endl;
        cout << "|                                              |" << endl;
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << "     1. LISTADO GENERAL" << endl;
        cout << "     2. ORDENADAS POR FECHA Y HORA" << endl;
        cout << "     0. VOLVER" << endl;
        cout << endl;
        cout << "================================================" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << "================================================" << endl;
        system("cls");
        switch (opcion)
        {
        case 1:
            listarCompras();
            break;
        case 2:
            listarComprasPorFecha();
            break;
        case 0:
            return;
            break;
        }
    }
}

void listarCompras()
{
    ArchivoCompras arch;
    ArchivoDetalleEntradas archDetalle;
    int cant = arch.contarRegistros();
    if (cant == 0)
    {
        cout << "No hay compras registradas." << endl;
        system("pause");
        return;
    }

    cout << "================================================" << endl;
    cout << "           LISTADO GENERAL DE COMPRAS           " << endl;
    cout << "================================================" << endl;

    for (int i = 0; i < cant; i++)
    {
        Compra obj = arch.leerRegistro(i);
        if (obj.getEstado())
        {
            obj.mostrar();

            int cantDetalles = archDetalle.contarRegistros();
            for (int j = 0; j < cantDetalles; j++)
            {
                DetalleEntrada d = archDetalle.leerRegistro(j);
                if (d.getIdCompra() == obj.getIdCompra())
                {
                    d.mostrar();
                    break;
                }
            }
            cout << "================================================" << endl;
        }
    }
    cout << endl;
    system("pause");
}

void listarComprasPorFecha()
{
    ArchivoCompras arch;
    ArchivoDetalleEntradas archDetalle;
    int cant = arch.contarRegistros();

    if (cant <= 0)
    {
        cout << "No hay compras registradas en el archivo." << endl;
        system("pause");
        return;
    }
    vector<Compra> vecCompras;

    for (int i = 0; i < cant; i++)
    {
        Compra obj = arch.leerRegistro(i);
        if (obj.getEstado())
        {
            vecCompras.push_back(obj);
        }
    }
    int activas = vecCompras.size();
    if (activas == 0)
    {
        cout << "No hay compras activas para ordenar." << endl;
        system("pause");
        return;
    }

    Compra aux;
    for (int i = 0; i < activas - 1; i++)
    {
        for (int j = 0; j < activas - 1 - i; j++)
        {
            if (vecCompras[j].getFecha() > vecCompras[j + 1].getFecha())
            {
                aux = vecCompras[j];
                vecCompras[j] = vecCompras[j + 1];
                vecCompras[j + 1] = aux;
            }
        }
    }

    system("cls");
    cout << "================================================" << endl;
    cout << "     COMPRAS ORDENADAS DE FORMA CRONOLOGICA     " << endl;
    cout << "================================================" << endl;

    int cantDetalles = archDetalle.contarRegistros();
    for (int i = 0; i < activas; i++)
    {
        vecCompras[i].mostrar();

        for (int j = 0; j < cantDetalles; j++)
        {
            DetalleEntrada d = archDetalle.leerRegistro(j);
            if (d.getIdCompra() == vecCompras[i].getIdCompra())
            {
                d.mostrar();
                break;
            }
        }
        cout << "================================================" << endl;
    }
    system("pause");
}
