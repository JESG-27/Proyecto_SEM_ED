#include <iostream>
#include <algorithm>
#include <cstdlib>
#include "VideoGame.h"
#include "menuAldeano.h"
#include "menuBarco.h"

using namespace std;

void view_format()
{
    cout << left;
    cout << setw(20) << "Nombre";
    cout << setw(20) << "Ubicacion X";
    cout << setw(20) << "Ubicacion Y";
    cout << setw(20) << "Puntuacion";
    cout << endl;
}

int main()
{
    VideoGame VG;
    string opc;

    while (true)
    {
        cout << "__________ Video Juego __________" << endl;
        cout << "1) Nombre de Usuario" << endl;
        cout << "2) Agregar Civilizacion" << endl;
        cout << "3) Insertar Civilizacion" << endl;
        cout << "4) Inicializar Civilizaciones" << endl;
        cout << "5) Mostrar Primera Civilizacion" << endl;
        cout << "6) Mostrar Ultima Civilizacion" << endl;
        cout << "7) Ordenar Civilizaciones" << endl;
        cout << "8) Eliminar Civilizacion" << endl;
        cout << "9) Buscar Civilizacion" << endl;
        cout << "10) Modificar Civilizacion" << endl;
        cout << "11) Resumen" << endl;
        cout << "12) Respaldar" << endl;
        cout << "13) Rescuperar" << endl;
        cout << "14) Barcos" << endl;
        cout << "0) Salir" << endl;
        cout << ":  ";

        getline(cin, opc);

        if (opc == "1")                                       // Opcion 1 nombre de usuario
        {
            string nom;
            cout << "Nombre de usuario: ";
            getline(cin, nom); cin.ignore();
            VG.setNombre(nom);
            system ("PAUSE");
            system ("CLS");
        }

        else if (opc == "2")                                  // Opción 2 Agregar Civilización
        {
            Civilizacion civ;
            cin >> civ;
            VG.AgregarCiv(civ); cin.ignore();
            system ("PAUSE");
            system ("CLS");
        }

        else if (opc == "3")                                // Insertar Civilización en una posición
        {
            Civilizacion civ;
            size_t pos;
            cin >> civ;
            cout << "Posicion: ";
            cin >> pos; cin.ignore();

            if (pos<VG.size() && pos>=0)
            {
                VG.insertar(civ, pos);
            }
            else
            {
                cout << "Posicion no valida" << endl;
            }
            system ("CLS");
        }

        else if (opc == "4")                                    // Inicializar Civilizaciones
        {
            Civilizacion civ;
            size_t num;
            cin >> civ;
            cout << "Numero de Civilizaciones: ";
            cin >> num;
            VG.inicializar(civ, num);
            system ("PAUSE");
            system ("CLS");
        }

        else if (opc == "5")                                    // Primera Civilización
        {
            if (VG.size()>0)
            {
                view_format();
                cout << VG.PrimerCiv();
            }
            else
            {
                cout << "No hay civilizaciones existentes" << endl;
                cout << "Intente agregar civilizaciones" << endl; 
            }
            system("PAUSE");
            system ("CLS");
        }

        else if (opc == "6")                                    // Ultima Civilización
        {
            if (VG.size()>0)
            {
                view_format();
                cout << VG.UltimaCiv();
            }
            else
            {
                cout << "No hay civilizaciones existentes" << endl;
                cout << "Intente agregar civilizaciones" << endl; 
            }
            system ("PAUSE");
            system ("CLS");
        }

        else if (opc == "7")                                    // Ordenar Civilizaciones 
        {
            int opc1;
            cout << "1) Ordenar por Nombre" << endl << "2) Ordenar por posicion en X" << endl << "3) Ordenar por posicion en Y" << endl << "4) Ordenar por Puntuacion" << endl;
            cout << "Opcion: ";
            cin >> opc1; cin.ignore();
            switch (opc1)
            {
            case 1: VG.OrdenarNom();
                break;
            case 2: VG.OrdenarUbX();
                break;
            case 3: VG.OrdenarUbY();
                break;
            case 4: VG.OrdenarPun();
                break;
            default:
                break;
            }
            system ("PAUSE");
            system ("CLS");
        }

        else if (opc == "8")                                    // Eliminar Civilización
        {
            string nom;
            cout << "Nombre: ";
            getline(cin, nom); cin.ignore();
            VG.eliminar(nom);
            system ("PAUSE");
            system ("CLS");
        }

        else if (opc == "9")                                    // Buscar Civilización
        {
                Civilizacion search;
                string nombre;
                cout << "Nombre: ";
                getline (cin, nombre);
                search.setNombre(nombre);
                Civilizacion *ptr = VG.buscar(search);
                if (ptr == nullptr)
                {
                    cout << "La busqueda no arrojo resultados" << endl;
                }
                else 
                {
                    cout << "Resultados de la busqueda: " << endl;
                    view_format();
                    cout << *ptr << endl << endl;
                    menuAldeano(*ptr);
                }
            system ("PAUSE");
            system ("CLS");
        }

        else if (opc == "10")                                    // Modificar una civilización
        {
            string nomCiv, opc2;
            Civilizacion search;
            
            cout << "Civilizacion a modificar"<< endl;
            cout << "Ingrese el nombre: ";
            getline(cin, nomCiv);
            search.setNombre(nomCiv);
            Civilizacion *ptr = VG.buscar(search);
            if (ptr == nullptr)
            {
                cout << "No existe" << endl;
            }
            else
            {
                cout << *ptr << endl;
                cout << "1) Modificar Nombre" << endl;
                cout << "2) Modificar posicion en X" << endl;
                cout << "3) Modificar posicion en Y" << endl;
                cout << "4) Modificar Puntuacion" << endl;
                getline(cin, opc2);

                if (opc2 == "1")
                {
                    string nom;
                    cout << "Modificar Nombre" << endl;
                    cout << "Nuevo nombre: ";
                    getline(cin, nom);
                    ptr->setNombre(nom);
                }
                else if (opc2 == "2")
                {
                    float num;
                    cout << "Modificar Posicion en X" << endl;
                    cout << "Nueva posicion: ";
                    cin >> num;
                    ptr->setUbicacion_x(num);
                }
                else if (opc2 == "3")
                {
                    float num;
                    cout << "Modificar Posicion en Y" << endl;
                    cout << "Nueva posicion: ";
                    cin >> num;
                    ptr->setUbicacion_y(num);
                }
                else if (opc2 == "4")
                {
                    float num;
                    cout << "Modificar Puntuacion" << endl;
                    cout << "Nueva puntuacion: ";
                    cin >> num;
                    ptr->setPuntuacion(num);
                }
            }
            system ("PAUSE");
            system ("CLS");
        }

        else if (opc == "11")                                    // Resumen
        {
            cout << "Usuario: ";
            cout << VG.getNombre() << endl;
            VG.mostrar();
            system ("PAUSE");
            system ("CLS");
        }

        else if (opc == "12")                                   // Respaldar
        {
            VG.respaldar();
            cout << "Respaldo Finalizado" << endl;
            system ("PAUSE");
            system ("CLS");
        }

        else if (opc == "13")                                   // Recuperar
        {
            VG.recuperar();
            cout << "Datos Recuperados" << endl;
            system ("PAUSE");
            system ("CLS");
        }

        else if (opc == "14")                                 // Barcos
        {
            menuBarcos(VG);
            system("PAUSE");
            system("CLS");
        }

        else if (opc == "0")                                    // Salir
        {
            break;
        }
    }
    
    return 0;
}