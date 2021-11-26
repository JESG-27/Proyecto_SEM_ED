#include "Civilizacion.h"
#include <fstream>

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
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getEdad() > a2.getEdad();});
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


// Respaldar

void Civilizacion::respaldar()
{
    ofstream archivo(getNombre() + ".txt", ios::out);

    if (archivo.is_open())
    {
        for (auto it = aldeanos.begin(); it != aldeanos.end(); it++)
        {
            Aldeano &aldeano = *it;
            archivo << aldeano.getNombre() << endl;
            archivo << aldeano.getEdad() << endl;
            archivo << aldeano.getGenero() << endl;
            archivo << aldeano.getSalud() << endl;
        }
    }
    archivo.close();
}

// Recuperar
void Civilizacion::recuperar()
{
    ifstream archivo(getNombre() + ".txt", ios::in);

    if (archivo.is_open())
    {
        string temp;
        size_t edad;
        float salud;

        while (true)
        {
            Aldeano a;
            getline (archivo, temp);
            if (archivo.eof())
            {
                break;
            }
            a.setNombre(temp);

            getline (archivo, temp);
            edad = stoi(temp);
            a.setEdad(edad);

            getline (archivo, temp);
            a.setGenero(temp);

            getline(archivo, temp);
            salud = stof(temp);
            a.setSalud(salud);

            agregarInicio(a);
        }
    }
    archivo.close();
}

// Agregar Barco
void Civilizacion::agregarBarco(Barco *b)
{
    puerto.push_back(b);
}

// Mostrar Barco
void Civilizacion::mostrarBarcos()
{
    cout << left;
    cout << setw(15) << "ID";
    cout << setw(15) << "Combustible";
    cout << setw(15) << "Velocidad";
    cout << setw(15) << "Armadura";
    cout << endl;
    for (auto it = puerto.begin(); it != puerto.end(); it++)
    {
        cout << **it << endl;
    }
}