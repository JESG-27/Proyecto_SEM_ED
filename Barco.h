#ifndef BARCO_H
#define BARCO_H
#include <iostream>
#include <iomanip>
#include <stack>
#include "Guerrero.h"

using namespace std;

class Barco
{
    string id;
    float combustible;
    float velocidad;
    float armadura;
    stack<Guerrero> Guerreros;

public:
    // Constructores
    Barco(){};
    Barco (const string &id, const float &combustible, const float &velocidad, const float &armadura):id(id), combustible(combustible), velocidad(velocidad), armadura(armadura){}

    // Setter y Getter
    void setId(const string &ID);
    string getId();
    void setCombustible(const float &COMBUSTIBLE);
    float getCombustible();
    void setVelocidad(const float &VELOCIDAD);
    float getVelocidad();
    void setArmadura(const float &ARMADURA);
    float getArmadura();

    // Guerreros
    void agregarGue(const Guerrero &g);
    void eliminarGue();
    Guerrero topGue();
    void mostrarGue();
    bool empty();

    friend ostream &operator<<(ostream &out, const Barco &b)
    {
        out << left;
        out << setw(15) << b.id;
        out << setw(15) << b.combustible;
        out << setw(15) << b.velocidad;
        out << setw(15) << b.armadura;
    }

};

#endif