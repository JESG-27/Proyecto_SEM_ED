#ifndef CIVILIZACON_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>
#include <list>
#include "Aldeano.h"
using namespace std;

class Civilizacion
{
    string nombre;
    float ubicacion_x;
    float ubicacion_y;
    float puntuacion;
    list<Aldeano> aldeanos;
    
public:

    // Constructores
    Civilizacion();
    Civilizacion(const string &nombre, const float &ubicacion_x, const float &ubicacion_y, const float &puntuacion);

    // Métodos de acceso
    void setNombre(const string &civ);
    string getNombre();
    void setUbicacion_x(const float &civ);
    float getUbicacion_x();
    void setUbicacion_y(const float &civ);
    float getUbicacion_y();
    void setPuntuacion(const float &civ);
    float getPuntuacion();

    // Funciones para Aldeanos
    //Agregar
    void agregarFinal(const Aldeano &a);
    void agregarInicio(const Aldeano &a);

    // Mostrar
    void print();

    // Eliminar
    void eliminarNombre(const string &nombre);
    void elimnarSalud(const float &num);
    void eliminarEdad();

    // Ordenar
    void ordenarNombre();
    void ordenarEdad();
    void ordenarSalud();

    // Buscar
    Aldeano* buscarAldeano(const Aldeano &a1);

    friend ostream& operator<<(ostream &out, const Civilizacion &civ)
    {
        out << left;
        out << setw(20) << civ.nombre;
        out << setw(20) << civ.ubicacion_x;
        out << setw(20) << civ.ubicacion_y;
        out << setw(20) << civ.puntuacion;
        out << endl;
    }

    friend istream& operator>>(istream &in, Civilizacion &civ)
    {
        cout << "Nombre de Civilizacion: ";
        getline(cin, civ.nombre);

        cout << "Ubicacion X: ";
        cin >> civ.ubicacion_x;

        cout << "Ubicacion Y: ";
        cin >>civ.ubicacion_y;

        cout << "Puntuacion: ";
        cin >> civ.puntuacion;

        return in;
    }

    bool operator==(const Civilizacion &civ)
    {
        return nombre == civ.nombre;
    }

    bool operator==(const Civilizacion &civ) const
    {
        return nombre == civ.nombre;
    }

    bool operator<(const Civilizacion &civ)
    {
        return nombre < civ.nombre;
    }

    bool operator<(const Civilizacion &civ) const
    {
        return nombre < civ.nombre;
    }

};

#endif