#ifndef CLSDETALLEENTRADA_H
#define CLSDETALLEENTRADA_H

class DetalleEntrada
{
private:
    int _idDetalleEntrada;
    int _idCompra;
    int _idFuncion;
    char _numeroButaca[7];
    int _idDescuento;
    float _precioBase;
    float _precioFinal;

public:
    DetalleEntrada();
    void setIdDetalleEntrada(int ID);
    void setIdCompra(int ID);
    void setIdFuncion(int ID);
    void setNumeroButaca(const char* num);
    void setIdDescuento(int ID);

    int getIdDetalleEntrada();
    int getIdCompra();
    int getIdFuncion();
    const char* getNumeroButaca();
    int getIdDescuento();
    float getPrecioBase();
    float getPrecioFinal();

    void cargar(int idCompra);
    void mostrar();
};

#endif // CLSDETALLEENTRADA_H
