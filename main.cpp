#include <iostream>
#include "VideoGame.h"

using namespace std;

int main()
{
    VideoGame VG;
    char opc;

    while (true)
    {
        cout << "__________ Video Juego __________" << endl;
        cout << "A) Nombre de Usuario" << endl;
        cout << "B) Agregar Civilizacion" << endl;
        cout << "C) Insertar Civilizacion" << endl;
        cout << "D) Inicializar Civilizaciones" << endl;
        cout << "E) Mostrar Primera Civilizacion" << endl;
        cout << "F) Mostrar Ultima Civilizacion" << endl;
        cout << "G) Ordenar Civilizaciones" << endl;
        cout << "H) Eliminar Civilizacion" << endl;
        cout << "I) Buscar Civilizacion" << endl;
        cout << "J) Modificar Civilizacion" << endl;
        cout << "K) Resumen" << endl;
        cout << "I) Salir" << endl;

        cin >> opc; 
        fflush(stdin);
        opc = toupper(opc);

        if (opc == 'A')                                       // Opcion 1 nombre de usuario
        {
            string nom;
            getline(cin, nom);
            VG.setNombre(nom);
        }

        else if (opc == 'B')                                  // Opción 2 Agregar Civilización
        {
            Civilizacion civ;
            cin >> civ;
            VG.AgregarCiv(civ); cin.ignore();
        }

        else if (opc == 'C')                                // Insertar Civilización en una posición
        {
            Civilizacion civ;
            size_t pos;
            cin >> civ;
            cout << "Posicion: ";
            cin >> pos;

            if (pos<VG.size() && pos>=0)
            {
                VG.insertar(civ, pos);
            }
            else
            {
                cout << "Posicion no valida" << endl;
            }
        }

        else if (opc == 'D')                                    // Inicializar Civilizaciones
        {
            Civilizacion civ;
            size_t num;
            cin >> civ;
            cout << "Numero de Civilizaciones: ";
            cin >> num;
            VG.inicializar(civ, num);
        }

        else if (opc == 'E')                                    // Primera Civilización
        {
            if (VG.size()>0)
            {
                VG.PrimerCiv();
            }
            else
            {
                cout << "No hay civilizaciones existentes" << endl;
                cout << "Intente agregar civilizaciones" << endl; 
            }
        }

        else if (opc == 'F')                                    // Ultima Civilización
        {
            if (VG.size()>0)
            {
                VG.UltimaCiv();
            }
            else
            {
                cout << "No hay civilizaciones existentes" << endl;
                cout << "Intente agregar civilizaciones" << endl; 
            }
        }

        else if (opc == 'G')                                    // Ordenar Civilizaciones 
        {
            int opc1;
            cout << "1) Ordenar por Nombre" << endl << "2) Ordenar por posicion en X" << endl << "3) Ordenar por posicion en Y" << endl << " 4) Ordenar por Puntuacion" << endl;
            cin >> opc1;
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
        }

        else if (opc == 'H')                                    // Eliminar Civilización
        {
            string nom;
            cout << "Nombre: ";
            getline(cin, nom); cin.ignore();
            VG.eliminar(nom);
        }

        else if (opc == 'I')                                    // Buscar Civilización
        {
                Civilizacion search;
                cin >> search;
                VG.buscar(search);
        }

        else if (opc == 'J')                                    // Modificar una civilización
        {
            
        }

        else if (opc == 'K')                                    // Resumen
        {
            VG.mostrar();
        }

        else if (opc == 'L')                                    // Salir
        {
            break;
        }

    }
    
    return 0;
}