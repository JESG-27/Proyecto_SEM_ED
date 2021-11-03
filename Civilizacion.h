#ifndef CIVILIZACON_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>
using namespace std;

class Civilizacion
{
    string nombre;
    float ubicacion_x;
    float ubicacion_y;
    float puntuacion;
public:
    Civilizacion();
    Civilizacion(const string &nombre, const float &ubicacion_x, const float &ubicacion_y, const float &puntuacion);
    void setNombre(const string &civ);
    string getNombre();
    void setUbicacion_x(const float &civ);
    float getUbicacion_x();
    void setUbicacion_y(const float &civ);
    float getUbicacion_y();
    void setPuntuacion(const float &civ);
    float getPuntuacion();

    friend ostream& operator<<(ostream &out, const Civilizacion &civ)
    {
        out << left;
        out << setw(10) << civ.nombre;
        out << setw(10) << civ.ubicacion_x;
        out << setw(10) << civ.ubicacion_y;
        out << setw(10) << civ.puntuacion;
        out << endl;
    }

    friend istream& operator>>(istream &in, Civilizacion &civ)
    {
        cout << "Nombre: ";
        getline(cin, civ.nombre);

        cout << "Ubicacion X: ";
        cin >> civ.ubicacion_x;

        cout << "Ubicacion Y: ";
        cin >>civ.ubicacion_y;

        cout << "Ubicacion Y: ";
        cin >> civ.ubicacion_y;

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
        return nombre == civ.nombre;
    }

    bool operator<(const Civilizacion &civ) const
    {
        return nombre == civ.nombre;
    }

};

#endif