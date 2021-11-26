#ifndef GUERRERO_H
#define GUERRERO_H
#include <iostream>
#include <iomanip>

using namespace std;

class Guerrero
{
private:
    string id;
    int salud;
    float fuerza;
    float escudo;
    string tipo;

public:
    Guerrero(){};
    Guerrero(const string &id, const int &salud, const float &fuerza, const float &escudo, const string &tipo):id(id), salud(salud), fuerza(fuerza), escudo(escudo), tipo(tipo){}
    
    void setId(const string &ID);
    string getId();
    void setSalud(const float &SALUD);
    float getSalud();
    void setFuerza(const float &FUERZA);
    float getFuerza();
    void setEscudo(const float &ESCUDO);
    float getEscudo();
    void setTipo(const string &TIPO);
    string getTipo();

    friend ostream &operator<<(ostream &out, const Guerrero &g)
    {
        out << left;
        out << setw(15) << g.id;
        out << setw(15) << g.salud;
        out << setw(15) << g.fuerza;
        out << setw(15) << g.escudo;
        out << setw(15) << g.tipo;
    }

};

#endif