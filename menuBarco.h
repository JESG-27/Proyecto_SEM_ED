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
            Barco b1;
            string ID;

            cout << "Buscar Barco" << endl;
            cout << "ID: ";
            getline(cin, ID);
            b1.setId(ID);
            VG.buscarBarcos(&b1);
        }

        else if (op == "4")
        {

        }
        
        else if (op == "0")
        {
            break;
        }
    }
}