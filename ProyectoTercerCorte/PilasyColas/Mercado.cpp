
#include <iostream>
#include <queue>
#include <string>
using namespace std;

//Se crea una funcion que tiene como parametro la direccion de la cola y el elemento a eliminar
void sacarElemento(queue<string> &lista, const string &producto){

    //Usamos un booleano que empieza en estado false
    bool encontrado = false;
    //Se crea una cola temporal para no modifcar la original 
    queue<string> temporal;
    //Usamos un condicional, que verifica que la lista no esta vacia
    while (!lista.empty()){
        //Se una otro condicional, que verifica que el primer producto de la lista sea el producto a eliminar y este en la lista
        if (lista.front() == producto && !encontrado){
            cout << "Sacando elemento: " << lista.front() << endl;
            //Se elimina el elemento
            lista.pop();
            //El estado del booleano pasa a true
            encontrado = true;
        } else {
            //Si no es el elemento actual, se pasa a la cola temporal y luego se elimina
            temporal.push(lista.front());
            lista.pop();
        }
    }

    //Si el elemento no fue encontrado, muestra un mensaje al usuario
    if (!encontrado) {

        cout << "El elemento especificado no se encuentra en la lista" << endl;

    }

    //Usamos un condicional que verfique si la cola temporal no esta vacia
    while (!temporal.empty()){
        //Agrega de vuelta los elementos de la lista temporal a la original, sin el elemento eliminado
        lista.push(temporal.front());
        //Se elemina la lista temporal
        temporal.pop();
    }

}

//Se crea una funcion que tiene como parametro la direccion de la cola
void verLista(queue<string> &lista){

    //Se crea la condicion de que verifica si la lista no esta vacia
    if (!lista.empty()){
        cout << "Lista de Mercado: " << endl;
        //Se vuelve a crear una lista temporal para no modificar la original
        queue<string> temp = lista;
        //Se usa un condicional que verifica que la cola temporal no esta vacia
        while(!temp.empty()){
            //Se imprime el elemento de al frente de la cola
            cout << temp.front() << endl;
            //Se elimina la cola temporal
            temp.pop();
        }
    } else {

        //Si la condicion no se cumple, da por entendido que la cola esta vacia
        cout << "La lista de mercado esta vacia" << endl;
    }
}

//Se crea una funcion donde el usuario podra manejar el sistema que tiene como parametro la direccion de la cola
void sistema(queue<string> &listaDeMercado){

    string producto;
    int opcion;

    //Se crea el bucle infinito que se sale solo si el usuario asi lo desea
    do {

        //Se crea el menu al usuario
        cout << "Bienvenido a su lista de mercado" << endl;
        cout << "1.Agregar producto a la lista" << endl;
        cout << "2.Sacar elemento de la lista" << endl;
        cout << "3.Ver la lista de mercado" << endl;
        cout << "4.Salir" << endl;
        cout << "Ingrese la opcion que desea realizar: " << endl;
        cin >> opcion;

        //Se crea el switch de las opciones
        switch(opcion){
            case 1:
            //El usuario ingresa el producto a agregar
            cout << "Ingresa el producto a agregar: " << endl;
            cin >> producto;

            //Se agrega el producto a la cola
            listaDeMercado.push(producto);

            cout << "Producto agregado con exito!" << endl;
            cout << "--------------------------------" << endl;
            break;

            case 2:
            //El usuario ingresa el producto que desea eliminar de la cola
            cout << "Ingresa el producto que vas a sacar de la lista: " << endl;
            cin >> producto;
            //Se llama el elemento a la funcion que saca el elemento de la cola
            sacarElemento(listaDeMercado, producto);
            cout << "---------------------------------" << endl;
            break;

            case 3:
            //Se llama a la funcion que le permite al usuario ver la lista de mercado
            verLista(listaDeMercado);
            cout << "---------------------------------" << endl;
            break;

            case 4:
            break;

            default:
            cout << "Opcion no valida" << endl;
        }
    } while (opcion != 4);
}

//Se crea el ejecutable
int main(){

    //Se crea la cola que almacena strings
    queue<string> listaDeMercado;
    //Se llama a la funcion que le permite manejar el sistema al usuario
    sistema(listaDeMercado);

    return 0;
}

