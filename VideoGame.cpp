#include "VideoGame.h"
#include <fstream>
#include <algorithm>

VideoGame::VideoGame()  // Constructor
{}

VideoGame::VideoGame(const string &nom, const vector<Civilizacion> Civilizaciones)
{
    this->Username = nom;
    this-> Civilizaciones = Civilizaciones;
}

void VideoGame::setNombre(const string &nom)
{
    Username=nom;
}

string VideoGame::getNombre()
{
    return Username;
}

void VideoGame::AgregarCiv(const Civilizacion &civ)  // Agregar Civilización
{
    Civilizaciones.push_back(civ);
}

void VideoGame::insertar(const Civilizacion &civ, size_t pos)  // Insertar
{
    Civilizaciones.insert(Civilizaciones.begin()+pos, civ);
}

void VideoGame::inicializar(const Civilizacion &civ, size_t n)   // Inicializar
{
    Civilizaciones = vector<Civilizacion>(n, civ);
}

Civilizacion VideoGame::PrimerCiv()   // Primera Civilización
{
    return Civilizaciones.front();
}

Civilizacion VideoGame::UltimaCiv()   // Ultima Civilización
{
    return Civilizaciones.back();
}

void VideoGame::OrdenarNom()    // Ordenar por Nombre
{
    sort(Civilizaciones.begin(), Civilizaciones.end());
}

void VideoGame::OrdenarUbX()  // Ordenar por ubicacion en X
{
    sort(Civilizaciones.begin(), Civilizaciones.end(), [](Civilizacion c1, Civilizacion c2){return c1.getUbicacion_x() < c2.getUbicacion_x();});
}

void VideoGame::OrdenarUbY()  // Ordenar por ubicacion en Y
{
    sort(Civilizaciones.begin(), Civilizaciones.end(), [](Civilizacion c1, Civilizacion c2){return c1.getUbicacion_y() < c2.getUbicacion_y();});
}

void VideoGame::OrdenarPun()  // Ordenar por puntuación
{
    sort(Civilizaciones.begin(), Civilizaciones.end(), [](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion() > c2.getPuntuacion();});
}

void VideoGame::eliminar(const string &nom)  // Eliminar por nombre
{
    for (auto it = Civilizaciones.begin(); it != Civilizaciones.end(); it++)
    {
        Civilizacion &c1 = *it;
        if (nom == c1.getNombre())
        {
            Civilizaciones.erase(it);
            break;
        }
    }
}

Civilizacion* VideoGame::buscar(const Civilizacion &civ)  // Buscar Civilizacion
{
    auto it = find(Civilizaciones.begin(), Civilizaciones.end(), civ);

    if (it == Civilizaciones.end())
    {
        return nullptr;
    }
    else 
    {
        return &(*it);
    }
}

size_t VideoGame::size()   // Total 
{
    return Civilizaciones.size();
}

void VideoGame::mostrar()
{
    cout << "_______________________________" << endl;
    cout << left;
    cout << setw(10) << "Nombre";
    cout << setw(10) << "Ubicacion en X";
    cout << setw(10) << "Ubicacion en Y";
    cout << setw(10) << "Puntuacion";
    cout << endl;
    for (size_t i=0; i<Civilizaciones.size(); i++)
    {
        Civilizacion &civ = Civilizaciones[i];
        cout << civ;
    }
    cout << "_______________________________" << endl;
}


