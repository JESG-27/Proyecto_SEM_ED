#include "Aldeano.h"

void Aldeano::setNombre(const string &nombre)
{
    this -> nombre = nombre;
}

string Aldeano::getNombre() const
{
    return nombre;
}

void Aldeano::setEdad(size_t edad)
{
    this -> edad = edad;
}

size_t Aldeano::getEdad() const
{
    return edad;
}

void Aldeano::setGenero(const string &genero)
{
    this -> genero = genero;
}

string Aldeano::getGenero() const
{
    return genero;
}

void Aldeano::setSalud(const float &salud)
{
    this -> salud = salud;
}

float Aldeano::getSalud() const
{
    return salud;
}
