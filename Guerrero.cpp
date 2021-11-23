#include "Guerrero.h"

void Guerrero::setId(const string &ID)
{
    id = ID;
}

string Guerrero::getId()
{
    return id;
}

void Guerrero::setSalud(const float &SALUD)
{
    salud = SALUD;
}

float Guerrero::getSalud()
{
    return salud;
}

void Guerrero::setFuerza(const float &FUERZA)
{
    fuerza = FUERZA;
}

float Guerrero::getFuerza()
{
    return fuerza;
}

void Guerrero::setEscudo(const float &ESCUDO)
{
    escudo = ESCUDO;
}

float Guerrero::getEscudo()
{
    return escudo;
}

void Guerrero::setTipo(const string &TIPO)
{
    tipo = TIPO;
}

string Guerrero::getTipo()
{
    return tipo;
}