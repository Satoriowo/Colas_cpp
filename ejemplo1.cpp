// programa simple, para iniciar

#include <iostream>

using namespace std;

// Estructura del Nodo
struct nodo{

  int dato;

  nodo *sgte;

};


void insertar( nodo *&inicio, nodo*&fin, int num){

  nodo *nuevo = new nodo(); // creamos espacio de memoria

  nuevo->dato = num; // hacemos que en el nodo nuevo dato igual a num

  nuevo->sgte = NULL; // sgte del nodo nuevo apunte a NULL

  if( inicio == NULL){
    inicio = nuevo; // se inserta el primer elemento si la cola esta vacía
  } else { // si tiene un elemento
    fin->sgte = nuevo; // fin apunta a sgte que es igual al nodo nuevo (se encola/inserta)
  }
  fin = nuevo; // si o si puntero fin siempre debe apuntar al último elemento


void eliminar( nodo*&inicio, nodo *&fin){

  if (inicio == NULL){
      cout<<"Cola vacia"<<endl;
  }

  nodo *aux; // creamos un nodo aux
  int num; 
  aux = inicio;  // aux apunta al inicio de la cola
  num = aux->dato; // num es igual al dato al que apunta aux
  inicio = inicio->sgte; // el inicio de la cola apunta a sgte que este apunta al siguiente elemento

  delete (aux);

  cout << "Numero " << num << " eliminado de la cola";
}

void mostrar(nodo *&inicio, nodo *&fin){

  nodo *aux; // creamos un nodo aux
  aux = inicio; // hacemos que aux igual a inicio

  if ( inicio == NULL){
      cout << "Cola vacia" << endl;
  }


  while (aux != NULL){
    cout << aux->dato << " "; // imprimimos el dato del nodo
    aux = aux->sgte; // aux apunta al siguiente nodo
  }

}

 

void eliminarTodo(nodo *&inicio, nodo *&fin){
  nodo *aux;

  while( inicio != NULL){ // mientras la cola no este vacía
    aux = inicio; // aux apunta a inicio
    inicio = aux->sgte; // inicio apunta a donde apunta aux (que apunta a sgte)
    delete (aux); // liberamos la memoria
  }

  inicio = NULL; // inicio y fin apuntan a NULL
  fin = NULL;
}

 

void menu(){

  cout << "\n\n\t -MENU-" << endl;
  cout << "1. Insertar un numero " << endl;
  cout << "2. Eliminar el primer numero" << endl;
  cout << "3. Mostrar cola" << endl;
  cout << "4. Eliminar todos los numeros" << endl;
  cout << "5. Salir" << endl;
  cout<<"Ingrese su opcion: ";

}

int main(){
  nodo *inicio = NULL;
  nodo *fin = NULL;
  int dato;
  int opc;

  do {

    menu();
    cin>>opc;

    switch(opc){

      case 1:
        cout << "Numero que se insertara: ";
        cin >> dato;
        insertar(inicio, fin, dato);
        cout << "\nNumero " << dato << " insertado " << endl;
        break;

      case 2:
        eliminar(inicio, fin);
        break;

      case 3: 
        mostrar(inicio, fin);
        break;

      case 4: 
        eliminarTodo(inicio,  fin);
        break;

      case 5: break;

    }

  }while(opc != 5);

  return 0;
}

