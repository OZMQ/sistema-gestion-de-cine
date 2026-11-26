#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED
class FechaHora
{
private:
    int anio;
    int mes;
    int dia;
    int hora;
    int minutos;

public:
    FechaHora(int a = 0, int m = 0, int d = 0, int h = 0, int Min = 0);
    ~FechaHora();

    void fechaHoraActual();
    void Cargar();
    void Mostrar();

    void setAnio(int a);
    void setMes(int m);
    void setDia(int d);
    void setHora(int h);
    void setMinutos(int Min);

    int getAnio();
    int getMes();
    int getDia();
    int getHora();
    int getMinutos();

    bool operator==(FechaHora fh);
    bool operator>(FechaHora fh);
    bool operator<(FechaHora fh);
};
#endif // CLSFECHA_H_INCLUDED
