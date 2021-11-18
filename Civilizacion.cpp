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

void Civilizacion::agregarFinal(const Aldeano &a)
{
    aldeanos.push_back(a);
}

void Civilizacion::agregarInicio(const Aldeano &a)
{
    aldeanos.push_front(a);
}

// Mostrar
void Civilizacion::print()
{
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++)
    {
        cout << *it << endl;
    }
}

// Eliminar
void Civilizacion::eliminarNombre(const string &nombre)
{
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++)
    {
        Aldeano &a = *it;
        if (a.getNombre() == nombre)
        {
            aldeanos.erase(it);
            break;
        }
    }
}

void Civilizacion::elimnarSalud(const float &num)
{
    aldeanos.remove_if([num](const Aldeano &a){return a.getSalud() < num;});
}

void Civilizacion::eliminarEdad()
{
    aldeanos.remove_if([](const Aldeano &a){return a.getEdad() >= 60;});
}

// Ordenar
void Civilizacion::ordenarNombre()
{
    aldeanos.sort();
}

void Civilizacion::ordenarEdad()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getEdad() < a2.getEdad();});
}

void Civilizacion::ordenarSalud()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getSalud() > a2.getSalud();});
}

// Buscar
Aldeano* Civilizacion::buscarAldeano(const Aldeano &a1)
{
   for (auto it = aldeanos.begin(); it != aldeanos.end(); it++)
    {
        Aldeano a2 = *it;
        if (a2.getNombre() == a1.getNombre())
        {
            return &(*it);
        }
        else if (it == aldeanos.end())
        {
            return nullptr;
        }
    }
}
