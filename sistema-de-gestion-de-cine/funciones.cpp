#include <iostream>
#include <windows.h>
#include <ctime>
#include <iomanip>
#include "funciones.h"
#include "clsArchivoDescuento.h"
#include "clsArchivoPeliculas.h"
#include "clsArchivoSalas.h"
#include "clsArchivoSocios.h"
#include "clsArchivoFunciones.h"
#include "clsArchivoFormato.h"
#include "clsArchivoCompras.h"
#include "clsArchivoDetalleEntradas.h"
#include <vector>
using namespace std;

// ----------------------------------
//UTILIDAD
void cargarCadena(const char* mensaje, char* palabra, int tam)
{
    cout << mensaje;
    if (cin.peek() == '\n')
    {
        cin.ignore();
    }
    cin.getline(palabra, tam);
    while (palabra[0] == '\0')
    {
        cout << "Campo obligatorio. " << mensaje;
        if (cin.peek() == '\n')
        {
            cin.ignore();
        }
        cin.getline(palabra, tam);
    }
}

//-------------------------------------------
// UTILIDADES PERO PARA BUTACAS
int butacasOcupadas(int idFuncion)
{
    ArchivoDetalleEntradas archD;
    ArchivoCompras archC;
    int ocupadas = 0;

    for (int i = 0; i < archD.contarRegistros(); i++)
    {
        DetalleEntrada detalle = archD.leerRegistro(i);

        if (detalle.getIdFuncion() == idFuncion)
        {
            int pos = archC.buscarRegistro(detalle.getIdCompra());
            if (pos != -1 && archC.leerRegistro(pos).getEstado())
            {
                ocupadas++;
            }
        }
    }
    return ocupadas;
}

int butacasDisponibles(Funcion f)
{
    ArchivoSalas arc;
    int pos = arc.buscarRegistro(f.getIdSala());
    if (pos == -1) return 0;

    int capacidad = arc.leerRegistro(pos).getCapacidadButacas();
    return capacidad - butacasOcupadas(f.getIdFuncion());
}

bool codigoValido(const char *codigo)
{
    if (codigo == NULL || strlen(codigo) != 6)
    {
        return false;
    }

    return (codigo[0] == 'F' && codigo[1] >= '0' && codigo[1] <= '9' && codigo[2] >= '0' && codigo[2] <= '9' && codigo[3] == 'B' && codigo[4] >= '0' && codigo[4] <= '9' && codigo[5] >= '0' && codigo[5] <= '9');
}

//-------------------------------------------
//PELICULAS

void cargarPelicula()
{
    ArchivoPeliculas arch;
    Pelicula obj;
    obj.cargar();
    if (arch.guardarRegistro(obj))
    {
        cout << endl;
        cout << "¡Registro exitoso!" << endl;
    }
    else
    {
        cout << endl;
        cout << "Error al guardar el archivo." << endl;
    }
    system("pause");
}

void modificarPelicula()
{
    int idBuscado;
    cout << "Ingrese ID de pelicula a modificar: ";
    cin >> idBuscado;

    ArchivoPeliculas arch;
    int pos = arch.buscarPorID(idBuscado);
    if (pos == -1)
    {
        cout << "No existe registro activo con el ID " << idBuscado << "." << endl;
        system("pause");
        return;
    }

    Pelicula obj = arch.leerRegistro(pos);
    obj.modificar();

    if (arch.modificarRegistro(obj, pos))
    {
        cout << "¡Registro modificado con exito." << endl;
    }
    else
    {
        cout << "Error al intentar guardar los cambios." << endl;
    }
    system("pause");
}

void cambiarEstadoPelicula()
{
    int idBuscado;
    cout << "Ingrese el ID a modificar su estado: ";
    cin >> idBuscado;

    ArchivoPeliculas arch;
    int pos = arch.buscarPorIDInactivo(idBuscado);
    if (pos == -1)
    {
        cout << "No se encontro un registro con el ID " << idBuscado << "." << endl;
        system("pause");
        return;
    }
    Pelicula obj = arch.leerRegistro(pos);
    if (obj.getEstado() == false)
    {
        cout << "La pelicula previamente dada de baja ha vuelto a ser activada." << endl;
        obj.setEstado(true);
    }
    else
    {
        obj.setEstado(false);
    }

    if (arch.modificarRegistro(obj, pos))
    {
        cout << "Estado de pelicula " << idBuscado << " modificado correctamente." << endl;
    }
    else
    {
        cout << "Error al intentar actualizar el archivo." << endl;
    }
    system("pause");
}

//-------------------------------------------
//DESCUENTOS

void cargarDescuento()
{
    ArchivoDescuento arch;
    Descuento obj;
    obj.cargar();
    if (arch.guardar(obj))
    {
        cout << endl;
        cout << "¡Registro exitoso!" << endl;
    }
    else
    {
        cout << endl;
        cout << "Error al guardar el archivo." << endl;
    }
    system("pause");
}

void modificarDescuento()
{
    int idBuscado;
    cout << "Ingrese el ID del descuento a modificar: ";
    cin >> idBuscado;
    ArchivoDescuento arch;
    int pos = arch.buscarPorID(idBuscado);
    if (pos == -1)
    {
        cout << "No hay descuentos activos con el ID " << idBuscado << "." << endl;
        system("pause");
        return;
    }
    Descuento obj = arch.leer(pos);
    obj.modificar();
    if (arch.modificar(obj, pos))
    {
        cout << "¡Registro modificado con exito!" << endl;
    }
    else
    {
        cout << "Error al modificar el archivo." << endl;
    }
    system("pause");
}

void cambiarEstadoDescuento()
{
    int idBuscado;
    cout << "Ingrese el ID del descuento a modificar su estado: ";
    cin >> idBuscado;

    ArchivoDescuento arch;
    int pos = arch.buscarPorIDInactivo(idBuscado);
    if (pos == -1)
    {
        cout << "No hay descuento activo con el ID " << idBuscado << "." << endl;
        system("pause");
        return;
    }

    Descuento obj = arch.leer(pos);
    if (obj.getEstado() == false)
    {
        cout << "El descuento previamente dado de baja ha vuelto a ser activado." << endl;
        obj.setEstado(true);
    }
    else
    {
        obj.setEstado(false);
    }

    if (arch.modificar(obj, pos))
    {
        cout << "Estado de descuento " << idBuscado << " modificado correctamente." << endl;
    }
    else
    {
        cout << "Error al intentar actualizar el archivo." << endl;
    }
    system("pause");
}

//-------------------------------------------
//SOCIOS

void cargarSocio()
{
    ArchivoSocios arch;
    Socio obj;

    obj.cargar();
    if (arch.grabarRegistro(obj))
    {
        cout << "Socio cargado correctamente." << endl;
    }
    else
    {
        cout << "Error al guardar el socio." << endl;
    }
    system("pause");
}

void modificarSocio()
{
    ArchivoSocios arch;
    int id;
    cout << "ID del socio a modificar: ";
    cin >> id;
    int pos = arch.buscarRegistro(id);
    if (pos == -1)
    {
        cout << "No existe un socio con ese ID." << endl;
        system("pause");
        return;
    }

    Socio obj = arch.leerRegistro(pos);
    cout << "1. DNI" << endl;
    cout << "2. NOMBRE" << endl;
    cout << "3. APELLIDO" << endl;
    cout << "0. CANCELAR" << endl;

    int opcion;
    cout << "Que desea modificar: ";
    cin >> opcion;

    char texto[30];
    int dni;
    switch (opcion)
    {
    case 1:
        cout << "NUEVO DNI: ";
        cin >> dni;
        while (dni < 1000000 || dni > 99999999)
        {
            cout << "Error, el DNI debe tener 7 u 8 digitos. Ingresar nuevamente: ";
            cin >> dni;
        }
        obj.setDni(dni);
        break;
    case 2:
        cargarCadena("NUEVO NOMBRE: ", texto, 30);
        obj.setNombre(texto);
        break;
    case 3:
        cargarCadena("NUEVO APELLIDO: ", texto, 30);
        obj.setApellido(texto);
        break;
    default:
        cout << "No se modifico nada." << endl;
        system("pause");
        return;
    }

    if (arch.modificarRegistro(obj, pos))
    {
        cout << "Socio modificado correctamente." << endl;
    }
    else
    {
        cout << "Error al modificar el socio." << endl;
    }
    system("pause");
}

void cambiarEstadoSocio()
{
    ArchivoSocios arch;
    int id;

    cout << "ID del socio a modificar estado: ";
    cin >> id;

    int pos = arch.buscarRegistroInactivo(id);
    if (pos == -1)
    {
        cout << "No existe un socio con ese ID." << endl;
        system("pause");
        return;
    }

    Socio obj = arch.leerRegistro(pos);
    if (obj.getEstado() == false)
    {
        cout << "El socio previamente dado de baja ha vuelto a ser activado." << endl;
        obj.setEstado(true);
    }
    else
    {
        obj.setEstado(false);
    }

    if (arch.modificarRegistro(obj, pos))
    {
        cout << "Estado de socio " << id << " modificado correctamente." << endl;
    }
    else
    {
        cout << "Error al intentar actualizar el archivo." << endl;
    }
    system("pause");
}

//-------------------------------------------
//FORMATOS

void cargarFormato()
{
    ArchivoFormato arch;
    Formato obj;
    obj.cargar();
    if (arch.guardarRegistro(obj))
    {
        cout << endl;
        cout << "¡Registro exitoso!" << endl;
    }
    else
    {
        cout << endl;
        cout << "Error al guardar el archivo." << endl;
    }
    system("pause");
}


void modificarFormato()
{
    int idBuscado;
    cout << "Ingrese ID del formato a modificar: ";
    cin >> idBuscado;

    ArchivoFormato arch;
    int pos = arch.buscarPorID(idBuscado);
    if (pos == -1)
    {
        cout << "No existe registro activo con el ID " << idBuscado << "." << endl;
        system("pause");
        return;
    }

    Formato obj = arch.leerRegistro(pos);
    obj.modificar();

    if (arch.modificarRegistro(obj, pos))
    {
        cout << "¡Registro modificado con exito." << endl;
    }
    else
    {
        cout << "Error al intentar guardar los cambios." << endl;
    }
    system("pause");
}


void cambiarEstadoFormato()
{
    int idBuscado;
    cout << "Ingrese el ID del formato a modificar estado: ";
    cin >> idBuscado;
    ArchivoFormato arch;
    int pos = arch.buscarPorID(idBuscado);
    if (pos == -1) {
        pos = arch.buscarPorIDInactivo(idBuscado);
    }
    if (pos == -1){
        cout << "Error, no se registro un formato con el ID " << idBuscado << "." << endl;
        system("pause");
        return;
    }
    Formato obj = arch.leerRegistro(pos);
    if (obj.getEstado() == false)
    {
        cout << "El formato previamente dado de baja ha vuelto a ser activado." << endl;
        obj.setEstado(true);
    }
    else
    {
        cout << "El formato ha sido dado de baja." << endl;
        obj.setEstado(false);
    }

    if (arch.modificarRegistro(obj, pos))
    {
        cout << "Estado de formato " << idBuscado << " modificado correctamente." << endl << endl;
    }
    else
    {
        cout << "Error al cambiar el estado." << endl << endl;
    }

    system("pause");
}

//-------------------------------------------
//SALAS

void cargarSala()
{
    ArchivoSalas arch;
    Sala obj;

    obj.cargar();
    if (arch.grabarRegistro(obj))
    {
        cout << "Sala cargada correctamente (capacidad: " << obj.getCapacidadButacas() << " butacas)." << endl;
    }
    else
    {
        cout << "Error al guardar la sala." << endl;
    }
    system("pause");
}

void modificarSala()
{
    ArchivoSalas arch;
    int id;

    cout << "ID de la sala a modificar: ";
    cin >> id;

    int pos = arch.buscarRegistro(id);
    if (pos == -1)
    {
        cout << "No existe una sala con ese ID." << endl;
        system("pause");
        return;
    }

    Sala obj = arch.leerRegistro(pos);
    cout << "1. FORMATO DE PROYECCION" << endl;
    cout << "0. CANCELAR" << endl;

    int opcion;
    cout << "Que desea modificar: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
    {
        ArchivoFormato archFormato;
        int cantFormatos = archFormato.contarRegistros();
        if (cantFormatos <= 0)
        {
            cout << "No hay formatos cargados en el sistema." << endl;
            system("pause");
            return;
        }

        cout << "--- Formatos disponibles ---" << endl;
        for (int i = 0; i < cantFormatos; i++)
        {
            Formato f = archFormato.leerRegistro(i);
            if (f.getEstado())
            {
                cout << "ID " << f.getID() << " - " << f.getNombre() << endl;
            }
        }

        int formato;
        cout << "INGRESE ID DEL NUEVO FORMATO: ";
        cin >> formato;

        int posFormato = archFormato.buscarPorID(formato);
        while (posFormato == -1 || !archFormato.leerRegistro(posFormato).getEstado())
        {
            cout << "Error, ingrese un ID de formato valido y activo: ";
            cin >> formato;
            posFormato = archFormato.buscarPorID(formato);
        }

        obj.setFormatoProyeccion(formato);
        break;
    }
    case 0:
    default:
        cout << "No se modifico nada." << endl;
        system("pause");
        return;
    }

    if (arch.modificarRegistro(obj, pos))
    {
        cout << "Sala modificada correctamente." << endl;
    }
    else
    {
        cout << "Error al modificar la sala." << endl;
    }
    system("pause");
}

void cambiarEstadoSala()
{
    ArchivoSalas arch;
    int id;

    cout << "ID de la sala a cambiar de estado: ";
    cin >> id;

    int pos = arch.buscarRegistro(id);
    if (pos == -1)
    {
        pos = arch.buscarRegistroInactivo(id);
    }
    if (pos == -1)
    {
        cout << "No existe una sala con ese ID." << endl;
        system("pause");
        return;
    }

    Sala obj = arch.leerRegistro(pos);
    bool nuevoEstado = !obj.getEstado();
    obj.setEstado(nuevoEstado);

    if (arch.modificarRegistro(obj, pos) == false)
    {
        cout << "Error al modificar el estado de la sala." << endl;
        system("pause");
        return;
    }

    if (nuevoEstado)
    {
        cout << "Sala reactivada correctamente." << endl;
    }
    else
    {
        cout << "Sala dada de baja correctamente." << endl;
    }
    system("pause");
}

//-------------------------------------------
//BUTACAS

void cambiarEstadoButaca()
{
    ArchivoSalas archSalas;
    int idSala;

    cout << "ID de la sala: ";
    cin >> idSala;
    while (idSala <= 0)
    {
        cout << "ID invalido. Ingrese un ID de sala mayor a 0: ";
        cin >> idSala;
    }

    int posSala = archSalas.buscarRegistro(idSala);
    if (posSala == -1)
    {
        posSala = archSalas.buscarRegistroInactivo(idSala);
    }

    if (posSala == -1)
    {
        cout << "No existe una sala registrada con ese ID." << endl;
        system("pause");
        return;
    }

    cout << "El archivo de butacas fue eliminado del sistema." << endl;
    cout << "La disponibilidad ahora se controla por capacidad de sala y entradas vendidas por funcion." << endl;
    system("pause");
}

//-------------------------------------------
//FUNCIONES

void cargarFuncion()
{
    ArchivoFunciones arch;
    Funcion obj;
    obj.cargar();
    if (arch.grabarRegistro(obj))
    {
        cout << endl;
        cout << "¡Registro exitoso!" << endl;
    }
    else
    {
        cout << endl;
        cout << " Error al guardar el archivo." << endl;
    }
    system("pause");
}

void modificarFuncion()
{
    int idBuscado;
    cout << "Ingrese el ID de la funcion a modificar: ";
    cin >> idBuscado;
    ArchivoFunciones arch;
    int pos = arch.buscarRegistro(idBuscado);
    if (pos == -1)
    {
        cout << "Error, no hay funcion registrada con el ID " << idBuscado << "." << endl;
        system("pause");
        return;
    }

    Funcion obj = arch.leerRegistro(pos);
    obj.modificar();

    if (arch.modificarRegistro(obj, pos))
    {
        cout << "Registro actualizado." << endl;
    }
    else
    {
        cout << "Error al actualizar el registro." << endl;
    }
    system("pause");
}



void cambiarEstadoFuncion()
{
    int idBuscado;
    cout << "Ingrese el ID de la funcion a modificar estado: ";
    cin >> idBuscado;
    ArchivoFunciones arch;
    int pos = arch.buscarRegistro(idBuscado);
    if (pos == -1) {
        pos = arch.buscarRegistroInactivo(idBuscado);
    }
    if (pos == -1){
        cout << "Error, no se registro una funcion con el ID " << idBuscado << "." << endl;
        system("pause");
        return;
    }
    Funcion obj = arch.leerRegistro(pos);
    if (obj.getEstado() == false)
    {
        cout << "La funcion previamente dada de baja ha vuelto a ser activada." << endl;
        obj.setEstado(true);
    }
    else
    {
        cout << "La funcion ha sido dada de baja." << endl;
        obj.setEstado(false);
    }

    if (arch.modificarRegistro(obj, pos))
    {
        cout << "Estado de funcion " << idBuscado << " modificado correctamente." << endl << endl;
    }
    else
    {
        cout << "Error al cambiar el estado de la funcion." << endl << endl;
    }

    system("pause");
}

//-------------------------------------------
//COMPRAS
void registrarCompra()
{
    ArchivoCompras archCompra;
    ArchivoDetalleEntradas archDetalle;

    Compra c;

    cout << "=======================================" << endl;
    cout << "        REGISTRAR NUEVA VENTA          " << endl;
    cout << "=======================================" << endl;

    c.cargar();

    int baseIdDetalle = archDetalle.contarRegistros() + 1;
    vector<DetalleEntrada> detalles;
    char agregarOtra = 's';

    while (agregarOtra == 's' || agregarOtra == 'S')
    {
        DetalleEntrada d;
        d.cargar(c.getIdCompra());

        if (d.getIdFuncion() <= 0)
        {
            if (detalles.empty())
            {
                cout << "No se pudo cargar ninguna entrada. La venta fue cancelada." << endl;
                system("pause");
                return;
            }
            else
            {
                cout << "No se pudo agregar otra entrada. Se conservaran las entradas cargadas previamente." << endl;
                break;
            }
        }

        bool repetidaEnCompraActual = false;
        for (int i = 0; i < detalles.size(); i++)
        {
            if (detalles[i].getIdFuncion() == d.getIdFuncion() &&
                strcmp(detalles[i].getNumeroButaca(), d.getNumeroButaca()) == 0)
            {
                repetidaEnCompraActual = true;
                break;
            }
        }

        if (repetidaEnCompraActual)
        {
            cout << "Error: ya seleccionaste esa butaca para esta funcion en la compra actual." << endl;
            continue;
        }

        d.setIdDetalleEntrada(baseIdDetalle + (int)detalles.size());
        detalles.push_back(d);

        cout << endl << "Entrada agregada a la compra. Desea agregar otra entrada/butaca? (s/n): ";
        cin >> agregarOtra;
    }

    if (detalles.empty())
    {
        cout << "Error: una compra debe tener al menos una entrada." << endl;
        system("pause");
        return;
    }

    if (archCompra.grabarRegistro(c) == false)
    {
        cout << "Error al guardar el archivo de compras." << endl;
        system("pause");
        return;
    }

    bool todosGuardados = true;
    for (int i = 0; i < detalles.size(); i++)
    {
        if (archDetalle.grabarRegistro(detalles[i]) == false)
        {
            todosGuardados = false;
            break;
        }
    }

    if (!todosGuardados)
    {
        int posC = archCompra.buscarRegistro(c.getIdCompra());
        if (posC != -1)
        {
            Compra compraAnulada = archCompra.leerRegistro(posC);
            compraAnulada.setEstado(false);
            archCompra.modificarRegistro(compraAnulada, posC);
        }
        cout << endl << "Error al guardar los detalles de la entrada. La compra fue cancelada para evitar registros incompletos." << endl;
        system("pause");
        return;
    }

    float totalCompra = 0.0;
    for (int i = 0; i < detalles.size(); i++)
    {
        totalCompra += detalles[i].getPrecioFinal();
    }

    cout << endl << "Registro exitoso!" << endl;
    cout << "Entradas vendidas en esta compra: " << detalles.size() << endl;
    cout << "Total de la compra: $" << (long long)totalCompra << endl;

    system("pause");
}

void cambiarEstadoCompra()
{
    int idBuscado;
    cout << "Ingrese el ID de la compra a modificar estado: ";
    cin >> idBuscado;
    ArchivoCompras arch;
    int pos = arch.buscarRegistro(idBuscado);
    if (pos == -1) {
        pos = arch.buscarRegistroInactivo(idBuscado);
    }
    if (pos == -1){
        cout << "Error, no se registro una compra con el ID " << idBuscado << "." << endl;
        system("pause");
        return;
    }
    Compra obj = arch.leerRegistro(pos);
    if (obj.getEstado() == false)
    {
        cout << "La compra previamente dada de baja ha vuelto a ser activada." << endl;
        obj.setEstado(true);
    }
    else
    {
        cout << "La compra ha sido dada de baja." << endl;
        obj.setEstado(false);
    }

    if (arch.modificarRegistro(obj, pos))
    {
        cout << "Estado de compra " << idBuscado << " modificado correctamente." << endl << endl;
    }
    else
    {
        cout << "Error al cambiar el estado de la compra." << endl << endl;
    }

    system("pause");
}
