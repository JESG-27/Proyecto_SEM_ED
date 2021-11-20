#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "Civilizacion.h"
#include "Aldeano.h"
#include <vector>

class VideoGame
{
private:
    string Username;
    vector<Civilizacion> Civilizaciones;

public:
    // Constructores
    VideoGame();
    VideoGame(const string &nom, const vector<Civilizacion> Civilizaciones);

    // Métodos de acceso
    void setNombre(const string &nom);
    string getNombre();

    // Agregar
    void AgregarCiv(const Civilizacion &civ);
    void insertar(const Civilizacion &civ, size_t pos);
    void inicializar(const Civilizacion &civ, size_t n);

    // Mostrar
    Civilizacion PrimerCiv();
    Civilizacion UltimaCiv();
    void mostrar();

    // Ordenar
    void OrdenarNom();
    void OrdenarUbX();
    void OrdenarUbY();
    void OrdenarPun();

    // Eliminar
    void eliminar(const string &nom);

    // Buscar
    Civilizacion* buscar(const Civilizacion &civ);

    // Respaldar y Recuperar
    void respaldar();
    void recuperar();

    size_t size();
};


#endif