#include "Civilizacion.h"

Civilizacion::Civilizacion()
{}

Civilizacion::Civilizacion(const string &nombre, const float &ubicacion_x, const float &ubicacion_y, const float &puntuacion)
{
    this->nombre = nombre;
    this->ubicacion_x = ubicacion_x;
    this->ubicacion_y = ubicacion_y;
    this->puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string &civ)
{
    nombre=civ;
}

string Civilizacion::getNombre()
{
    return nombre;
}

void Civilizacion::setUbicacion_x(const float &civ)
{
    ubicacion_x = civ;
}

float Civilizacion::getUbicacion_x()
{
    return ubicacion_x;
}

void Civilizacion::setUbicacion_y(const float &civ)
{
    ubicacion_y = civ;
}

float Civilizacion::getUbicacion_y()
{
    return ubicacion_y;
}

void Civilizacion::setPuntuacion(const float &civ)
{
    puntuacion = civ;
}

float Civilizacion::getPuntuacion()
{
    return puntuacion;
}