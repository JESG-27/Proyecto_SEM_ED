#include "Barco.h"

void Barco::setId(const string &ID)
{
    id = ID;
}

string Barco::getId()
{
    return id;
}

void Barco::setCombustible(const float &COMBUSTIBLE)
{
    combustible = COMBUSTIBLE;
}

float Barco::getCombustible()
{
    return combustible;
}

void Barco::setVelocidad(const float &VELOCIDAD)
{
    velocidad = VELOCIDAD;
}

float Barco::getVelocidad()
{
    return velocidad;
}

void Barco::setArmadura(const float &ARMADURA)
{
    armadura = ARMADURA;
}

float Barco::getArmadura()
{
    return armadura;
}