#include <iostream>
#include <string>


using namespace std;

struct nodo{
    int cant;
    string d;
    string cocacola;
    string ingre;
    nodo *sig;
};

class ListaSimple{

    private:
        nodo *pInicio;
    
    public:
        ListaSimple();
        void insInicio(int, string, string, string);
        void mostrarListaIter(void);  
        void eliminarElemento(int);  
};

ListaSimple::ListaSimple(void)
{
    pInicio = NULL;
}


void ListaSimple::insInicio(int cant, string d,  string cocacola, string ingre)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->cant = cant;
    nuevo->d = d;
    nuevo->cocacola = cocacola;
    nuevo->ingre = ingre;
    nuevo->sig = pInicio;
    pInicio = nuevo;
}

void ListaSimple::mostrarListaIter(void)
{
    nodo *saltarin;

    cout << endl;
    saltarin = pInicio;
    while(saltarin != NULL){
        cout << saltarin->cant <<" Pupusas de " <<saltarin->d <<saltarin->cocacola << " Ingredientes: " <<saltarin->ingre << endl;
        saltarin = saltarin->sig;
    }
}

    

int menu(){
    int opcion = 0;
    cout << "\n1) Ingresar una orden" << endl;
    cout << "2) Mostrar ordenes" << endl;
    cout << "3) Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    return opcion;
}

int main(void)
{
    cout << endl;
    cout << "ADMINISTRACIÓN DE LISTA LINEAL SIMPLEMENTE ENLAZADA" << endl << endl;

    ListaSimple objListaSimple;

   bool continuar = true;
   int cant = 0;
   string d = "", cocacola ="", ingre ="";
   char coca, tipo;
    
    do{
        switch(menu()){
            case 1: //Hacer una transaccion
                cout << "Cuantas pupusas quiere?: ";
                cin >> cant; cin.ignore();
                cout << "Escriba los ingredientes que desea: ";
                getline (cin,ingre);

                 cout << "Arroz o Maiz, digite la inicial (a/m): ";
                cin >> tipo;
                
                if(tipo == 'a'){
                    d = "Arroz,";
                }
                if(tipo == 'm'){
                    d = "Maiz,";
                }

                cout << "Quiere Coca-Cola? (s/n): ";
                cin >> coca;
                if(coca == 's'){
                    cocacola = " con Coca-Cola ...";
                }
                if (coca == 'n'){
                    cocacola = " sin Coca-Cola ...";
                }


               objListaSimple.insInicio(cant, d, cocacola, ingre);
                cout << "Personas almacenada exitosamente!" << endl;
                break;
            case 2:
                objListaSimple.mostrarListaIter();
               
                break;
            case 3: 
                continuar = false;
                break;
            default: //El usuario se equivoco
                cout << "La opcion no es valida, favor intente denuevo." << endl;
                break;
        }
    }while(continuar);



    cout << endl;
    return 0;
}