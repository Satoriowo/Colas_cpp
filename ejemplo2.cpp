#include <iostream>

using namespace std;

// estructura nodo
struct nodo  {
  int dato;
  nodo *sgte;
};

struct nodo *anterior, *inicio, *fin; // punteros que usaremos 

// Declaramos las funciones que vamos a utilizar;
void insertar();
void eliminar();
void buscar();
void modificar();
void mostrar();
void menu();

int main(){
  int opc;

  do{
    menu();
    cin >> opc;
    
    switch(opc){
      case 1: 
        cout << "\tInsertar dato" << endl;
        insertar();
        break;
      
      case 2: 
        cout << "\tBuscar dato" << endl;
        buscar();
        break;
      
      case 3: 
        cout << "\tModificar dato" << endl;
        modificar();
        break;

      case 4: 
        cout << "\tEliminar dato" << endl;
        eliminar();
        break;
      
      case 5: 
        cout << "\tMostrar dato" << endl;
        mostrar();
        break;
      
      case 6: 
        cout << "Hasta luego..."<< endl;
        break;

    }
  } while (opc != 6);
  return 0;
  
}

void menu(){
  cout << "--\tMenu\t--"<< endl;
  cout << "1. Insertar cola.\t\t4. Eliminar de la cola." << endl;
  cout << "2. Buscar dato.\t\t\t5.Mostrar cola."<< endl;
  cout << "3. Modificar dato.\t\t6. Salir" << endl;
  cout << "Ingrese la opcion elegida: ";
}

void insertar(){
  nodo *aux = new nodo();
  cout << "\nIngrese el numero a insertar: ";
  cin >> aux->dato; // almacenamos el numero dado en el nodo aux 
  
  if ( inicio == NULL){
    inicio = aux; // inicio es igual a nodo aux
    inicio->sgte=NULL; // sgte apunta a NULL
    fin = inicio; // fin es igual a inicio
  } else {
    fin->sgte = aux; // sgte apunta a nodo aux
    aux->sgte = NULL; // sgte de aux apunta a NULL
    fin = aux; // fin es igual a aux
  }

  cout << " Dato ingresado con exito..." << endl;

  system("cls");
  system("pause");
}

void buscar(){
  nodo *aux = new nodo();
  aux = inicio;
  bool nodoEncontrado = false;
  int nodoBuscado;

  cout << "\nIngrese dato a buscar: ";
  cin >> nodoBuscado;

  if ( inicio != NULL){
    while ( aux != NULL && nodoEncontrado != true){
      if (aux->dato == nodoBuscado){
        cout << "\nDato " << nodoBuscado << " encontrado.. " << endl;
        nodoEncontrado = true;
      }

      aux = aux->sgte;
    }
    if ( nodoEncontrado != true){
      cout << "\nDato no encontrado" << endl;
    }
  } else {
    cout << "\nLa cola esta vacia..." << endl;
  }

  system("cls");
  system("pause");
}

void modificar(){
  nodo *aux = new nodo();
  aux = inicio;
  bool nodoEncontrado = false;
  int nodoBuscado;

  cout << "\nIngrese dato que desea modificar: " << endl;
  cin >> nodoBuscado;

  if ( inicio != NULL){
    while ( aux != NULL && nodoEncontrado != true){
      if ( aux->dato == nodoBuscado){
        cout << "\nDato " << nodoBuscado << " encontrado" << endl;
        cout << "Ingrese el nuevo dato para este espacio: ";
        cin >> aux->dato;
        cout << "\nDato modificado..." << endl;
        nodoEncontrado = true;
      }
    }

    if (nodoEncontrado != true){
      cout << "\nDato no encontrado" << endl;
    }
  } else {
    cout << "La cola esta vacia..." << endl;
  }

  system("cls");
  system("pause");
}

void eliminar(){
  nodo *aux = NULL;
  aux = inicio; // aux igual a inicio
  nodo *anterior = new nodo();
  anterior = NULL;
  bool nodoEncontrado = false;
  int nodoBuscado;

  cout << "\nIngrese dato a eliminar: ";
  cin >> nodoBuscado;

  if ( inicio != NULL){
    while ( aux != NULL  && nodoEncontrado != true){
      if (aux->dato == nodoBuscado){
        
        cout << "\nDato " << nodoBuscado << " encontrado.." << endl;

        if ( aux == inicio){
          inicio = inicio->sgte;
        } else if( aux == fin){
          anterior->sgte = NULL;
          fin = anterior;
        } else {
          anterior->sgte = aux->sgte;
        }
      
        cout << "Dato eliminado..." << endl;
        nodoEncontrado = true;
      }
    
      anterior = aux;
      aux = aux->sgte;
    }

    if ( nodoEncontrado == false){
      cout << "\nDato no encontrado.... :c" << endl;
    }
  } else {
    cout << "\nLa cola esta vacia... " << endl;
  }

  system("cls");
  system("pause");
}

void mostrar(){
  nodo *aux = new nodo();
  aux = inicio;

  if ( inicio != NULL){
    while ( aux != NULL){
      cout << endl << " " << aux->dato;
      aux = aux->sgte;
    } 
    cout << endl;
  } else {
    cout << "\nLa cola esta vacia...." << endl;
  }

  system("cls");
  system("pause");
}

