#include <iostream>
#include <stack>
using namespace std;

//Se crea una estructura que almacena los datos que necesitamos sobre la llamada
struct Llamada {

    //Se inicializan las variables necesarias
    long int numero;
    string nombre;
    string fecha;
};

//Se crea una funcion que tiene como parametro la direccion de la pila que creamos 
void hacerLlamada (stack<Llamada>& listaLlamadas){

    //Se instancia la estructura con un objeto 
    Llamada newCall;

    //Se le pide al usuario ingresar el numero de telefono
    cout << "Ingrese el numero de telefono: " << endl;
    //Se almacena la entrada en la estructura ya definida
    cin >> newCall.numero;
    //Se limpia el buffer del teclado
    cin.ignore();

    //Se le pide al usuario ingresar el nombre de telefono
    cout << "Ingrese el nombre del contacto: " << endl;
    //Almacenamos una linea completa de entrada en la variable de la estructura
    getline(cin, newCall.nombre);

    //Simulamos la fecha actual inicializanco la variable con la fecha 
    newCall.fecha = "05/05/2024";

    //Almacenamos la instancia de la clase en la pila que creamos
    listaLlamadas.push(newCall);

    cout << "Llamada realizada y almacenada con exito!" << endl;

}

//Se crea una funcion que tiene como parametros la direccion de la pila que creamos
void mostrarLista(stack<Llamada>& listaLlamadas) {

    cout << "Lista de llamadas telefonicas recientes: " << endl;
    //Se crea un condicional que verifica si la pila es diferente de vacia
    while (!listaLlamadas.empty()){
        //Se instancia la estructura con un objeto y se verifica cual es el elemento en la cima de la pila
        Llamada llamada = listaLlamadas.top();
        cout << "Numero: " << llamada.numero << " - Nombre: " << llamada.nombre << " - Fecha: " << llamada.fecha << endl;
        //Se elimina la lista temporal
        listaLlamadas.pop();
    }
}

//Se crea el menu que contiene opciones para el usuario
void menu(){

    cout << "Bienvenido al registro de llamadas" << endl;
    cout << "1.Hacer llamada" << endl;
    cout << "2.Ver llamadas recientes" << endl;
    cout << "3.Salir" << endl;
    cout << "Ingrese la opcion que desea realizar: " << endl;
}

//Se crea el ejecutable
int main () {

    //Se crea la lista que contiene los elementos de la estructura
    stack<Llamada> listaLlamadas;
    int opcion;

    //Se crea un bucle infinito que se sale solo si el usuario ingresa la opcion de salir 
    do{
        menu();
        cin >> opcion;

        switch(opcion){
            case 1:
            hacerLlamada(listaLlamadas);
            break;

            case 2:
            mostrarLista(listaLlamadas);
            break;

            case 3:
            break;

            default:
            cout << "Opcion no valida" << endl;
            break;

        }


    }while (opcion != 3);
}