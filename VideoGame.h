#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "Civilizacion.h"
#include <vector>

class VideoGame
{
    string Username;
    vector<Civilizacion> Civilizaciones;
public:
    VideoGame();
    VideoGame(const string &nom, const vector<Civilizacion> Civilizaciones);
    void setNombre(const string &nom);
    string getNombre();
    void AgregarCiv(const Civilizacion &civ);
    void insertar(const Civilizacion &civ, size_t pos);
    void inicializar(const Civilizacion &civ, size_t n);
    Civilizacion PrimerCiv();
    Civilizacion UltimaCiv();
    void OrdenarNom();
    void OrdenarUbX();
    void OrdenarUbY();
    void OrdenarPun();
    void eliminar(const string &nom);
    Civilizacion* buscar(const Civilizacion &civ);
    size_t size();
    void mostrar();
};


#endif