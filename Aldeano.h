#ifndef ALDEANO_H
#define ALDEANO_H
#include <iostream>
#include <iomanip>
using namespace std;

class Aldeano
{
public:
    Aldeano(){}
    Aldeano(const string &nombre, size_t edad, const string &genero, const float &salud): nombre(nombre), edad(edad), genero(genero), salud(salud){}
    
    void setNombre(const string &nombre);
    string getNombre() const;
    void setEdad(size_t edad);
    size_t getEdad() const;
    void setGenero(const string &genero);
    string getGenero() const;
    void setSalud(const float &salud);
    float getSalud() const;

    friend ostream &operator<<(ostream &out, const Aldeano &a)
    {
        out << left;
        out << setw(15) << a.nombre;
        out << setw(15) << a.edad;
        out << setw(15) << a.genero;
        out << setw(15) << a.salud;
    }

    bool operator<(const Aldeano &a) const
    {
        return nombre < a.getNombre();
    }

private:
    string nombre;
    size_t edad;
    string genero;
    float salud;
};

#endif