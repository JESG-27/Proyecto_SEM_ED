void capturarBarco(Civilizacion &c)
{
    Barco *b = new Barco();
    string id;
    b->setVelocidad(0.0);
    b->setArmadura(100.0);
    float combustible;

    cout << "ID: ";
    getline(cin, id);
    b->setId(id);

    cout << "Combustible: ";
    cin >> combustible; cin.ignore();
    b->setCombustible(combustible);

    c.agregarBarco(b);
}

void capturarGuerrero(Barco* b)
{
    string id, tipo;
    float salud, fuerza, escudo;
    Guerrero g;

    cout << "ID: ";
    getline(cin, id);
    g.setId(id);

    cout << "Salud: ";
    cin >> salud; cin.ignore();
    g.setSalud(salud);

    cout << "Fuerza: ";
    cin >> fuerza; cin.ignore();
    g.setFuerza(fuerza);

    cout << "Escudo: ";
    cin >> escudo; cin.ignore();
    g.setEscudo(escudo);

    cout << "Tipo:  " << "1) Artillero  " << "2) Arquero  " << "3) Paladin  " << "4) Lancero" << endl;
    
    size_t type;
    cout << "Opcion: ";
    cin >> type; cin.ignore();
    switch (type)
    {
    case 1:
        tipo = "Artillero";
        break;
    case 2:
        tipo = "Arquero";
        break;
    case 3: 
        tipo = "Paladin";
        break;
    case 4:
        tipo = "Lancero";
        break;
    default:
        break;
    }
    g.setTipo(tipo);

    b->agregarGue(g); 

}

void menuBarcos(VideoGame &VG)
{
    string op;

    while (true)
    {
        cout << "----- Barcos -----" << endl;
        cout << "1) Agregar Barco" << endl; 
        cout << "2) Mostrar Barcos" << endl; 
        cout << "3) Buscar Barco" << endl; 
        cout << "4) Eliminar Barco" << endl; 
        cout << "0) Salir" << endl;
        cout << ": ";
        getline(cin, op);

        if (op == "1")
        {
            Civilizacion search;
            string nombre;
            cout << "Nombre de civilizacion: ";
            getline (cin, nombre);
            search.setNombre(nombre);
            Civilizacion *ptr = VG.buscar(search);
            if (ptr == nullptr)
            {
                cout << "La busqueda no arrojo resultados" << endl;
            }
            else 
            {
                cout << "Civilizacion: " << ptr->getNombre() << endl;
                cout << "Agregar Barco" << endl;
                capturarBarco(*ptr);
            }
        } 

        else if (op == "2")
        {
            VG.mostrarBarcos();
        }

        else if (op == "3")
        {
            Barco *b1 = new Barco;
            string ID;

            cout << "Buscar Barco" << endl;
            cout << "ID: ";
            getline(cin, ID);
            cout << endl;
            b1->setId(ID);
            if (VG.buscarBarcos(b1) != nullptr)
            {
                string opc;

                while (true)
                {
                    cout << "  Guerreros  " << endl;
                    cout << "1) Agregar Guerrero" << endl;
                    cout << "2) Eliminar Guerrero" << endl;
                    cout << "3) Mostrar Ultimo Guerrero" << endl;
                    cout << "4) Mostrar todos los Guerreros" << endl;
                    cout << "0) Salir" << endl;
                    cout << ": ";
                    getline(cin, opc);

                    if (opc == "1")
                    {
                        capturarGuerrero(b1);
                    }

                    else if (opc == "2")
                    {
                        b1->eliminarGue();
                    }

                    else if (opc == "3")
                    {
                        cout << left;
                        cout << setw(15) << "ID";
                        cout << setw(15) << "Salud";
                        cout << setw(15) << "Fuerza";
                        cout << setw(15) << "Escudo";
                        cout << setw(15) << "Tipo";
                        cout << endl;
                        cout << b1->topGue();
                    }

                    else if (opc == "4")
                    {
                        cout << left;
                        cout << setw(15) << "ID";
                        cout << setw(15) << "Salud";
                        cout << setw(15) << "Fuerza";
                        cout << setw(15) << "Escudo";
                        cout << setw(15) << "Tipo";
                        cout << endl;
                        b1->mostrarGue();
                        cout << endl;
                    }

                    else if (opc == "0")
                    {
                        break;
                    }
                }

            }
            else 
            {
                cout << "No se encontro" << endl;
            }
        }

        else if (op == "4")
        {
           string opc;
           cout << " Eliminar " << endl;
           cout << "1) Eliminar por ID" << endl;
           cout << "2) Eliminar por combustible" << endl << ": ";
           getline(cin, opc);

           if (opc == "1")
           {
               string ID;
               cout << "ID: ";
               getline(cin, ID);
               cout << endl;
               VG.eliminarBarco(ID);
           }

           else if (opc == "2")
           {
               float Com;
               cout << "Eliminar por combustible menor a: ";
               cin >> Com; cin.ignore();
               VG.eliminarBarco(Com);
           }
           
        }
        
        else if (op == "0")
        {
            break;
        }
    }
}