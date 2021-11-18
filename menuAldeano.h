Aldeano capturar()
{
    Aldeano a;
    string nombre;
    size_t edad;
    string genero;
    size_t salud;

    cout << "Nombre: ";
    getline(cin, nombre);
    a.setNombre(nombre);

    cout << "Edad: ";
    cin >> edad; cin.ignore();
    a.setEdad(edad);

    cout << "Genero: ";
    getline(cin, genero);
    a.setGenero(genero);

    cout << "Salud: ";
    cin >> salud; cin.ignore();
    a.setSalud(salud);

    return a;
}

void menuAldeano(Civilizacion &civ)
{
   string op;

   while (true)
    {
        cout << "<<< Aldeanos >>>" << endl;
        cout << "1) Agregar Aldeano" << endl;
        cout << "2) Eliminar Aldeano" << endl;
        cout << "3) Clasificar Aldeanos" << endl;
        cout << "4) Buscar Aldeano" << endl;
        cout << "5) Modificar Aldeano" << endl;
        cout << "6) Mostar Aldeanos" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op);
        cout << endl;

        if (op == "1")                                                                                      // Agregar Aldeanos
        {
            string opc;
            
            cout << "1) Agregar Inicio" << endl; 
            cout << "2) Agregar Final" << endl;
            getline (cin, opc);
            cout << endl;

            if (opc == "1")
            {
                civ.agregarInicio(capturar());
                float punt = civ.getPuntuacion();
                civ.setPuntuacion(punt+100);
            }
            else if (opc == "2")
            {
                civ.agregarFinal(capturar());
                float punt = civ.getPuntuacion();
                civ.setPuntuacion(punt+100);
            }
        }

        else if (op == "2")                                                                                  // Eliminar Aldeanos
        {
            string opc1;

            cout << "1) Eliminar por nombre" << endl;
            cout << "2) Eliminar por Salud < x" << endl;
            cout << "3) Eliminar por Edad >= 60" << endl;
            getline(cin, opc1);
            cout << endl;

            if (opc1 == "1")
            {
                string nombre;
                cout << "Nombre: ";
                getline(cin, nombre);
                civ.eliminarNombre(nombre);
            }
            else if (opc1 == "2")
            {
                float num;
                cout << "Salud: ";
                cin >> num; cin.ignore();
                civ.elimnarSalud(num);
            }
            else if (opc1 == "3")
            {
                civ.eliminarEdad();
            }
        }

        else if (op == "3")                                                                                     // Ordenar
        {
            string opc2;

            cout << "1) Ordenar por Nombre" << endl;
            cout << "2) Ordenar por Edad" << endl;
            cout << "3) Ordenar por Salud" << endl;
            getline (cin, opc2);
            cout << endl;

            if (opc2 == "1")
            {
                civ.ordenarNombre();
            }
            else if (opc2 == "2")
            {
                civ.ordenarEdad();
            }
            else if (opc2 == "3")
            {
                civ.ordenarSalud();
            }
        }

        else if (op == "4")                                                                                      // Buscar
        {
            string nom;
            cout << "Buscar Aldeano" << endl << "Nombre: ";
            getline(cin, nom);
            Aldeano a;
            a.setNombre(nom);
            Aldeano *ptr = civ.buscarAldeano(a);
            if (ptr == nullptr)
                {
                    cout << "La busqueda no arrojo resultados" << endl;
                }
                else 
                {
                    cout << "Resultados de la busqueda: " << endl;
                    cout << left;
                    cout << setw(15) << "Nombre";
                    cout << setw(15) << "Edad";
                    cout << setw(15) << "Genero";
                    cout << setw(15) << "Salud" << endl;
                    cout << *ptr << endl << endl;
                }
        }
        else if (op == "5")                                                                                         // Modificar
        {
            string nom;
            cout << "Modificar Aldeano" << endl << "Nombre: ";
            getline(cin, nom);
            Aldeano a;
            a.setNombre(nom);
            Aldeano *ptr = civ.buscarAldeano(a);
            if (ptr == nullptr)
                {
                    cout << "La busqueda no arrojo resultados" << endl;
                }
                else 
                {
                    cout << "Resultados de la busqueda: " << endl;
                    cout << left;
                    cout << setw(15) << "Nombre";
                    cout << setw(15) << "Edad";
                    cout << setw(15) << "Genero";
                    cout << setw(15) << "Salud";
                    cout << endl;
                    cout << *ptr << endl << endl;

                    cout << "Modificar Aldeano" << endl;
                    cout << "1) Nombre" << endl;
                    cout << "2) Edad" << endl;
                    cout << "3) Genero" << endl;
                    cout << "4) Salud" << endl;
                    getline(cin, op);
                    cout << endl;

                    if (op == "1")
                    {
                        string nombre;
                        cout << "Nuevo Nombre: ";
                        getline(cin, nombre);
                        ptr->setNombre(nombre);
                    }
                    else if  (op == "2")
                    {
                        size_t edad;
                        cout << "Nueva Edad: ";
                        cin >> edad; cin.ignore();
                        ptr->setEdad(edad);
                    }
                    else if (op == "3")
                    {
                        string genero;
                        cout << "Nuevo Genero: ";
                        getline(cin, genero);
                        ptr->setGenero(genero);
                    }
                    else if (op == "4")
                    {
                        float salud;
                        cout << "Nueva Salud: ";
                        cin >> salud; cin.ignore();
                        ptr->setSalud(salud);
                    }
                }
        }

        else if (op == "6")                                                                                  // Mostrar  Aldeanos
        {
            cout << left;
            cout << setw(15) << "Nombre";
            cout << setw(15) << "Edad";
            cout << setw(15) << "Genero";
            cout << setw(15) << "Salud";
            cout << endl;
            civ.print();
        }

        else if (op == "0")
        {
            break;
        }

    }
}