#include <iostream>
#include <queue>
using namespace std;

//Se crea una estructura que almacena los datos que necesitamos para la impresion
struct Impresion {

    //Se inicializan las variables necesarias 
    string documento;
    int paginas;

};

//Se crea una funcion que tiene como parametro la direccion de la cola que creamos como constante para que nunca cambie 
void mostrarPendientes(const queue<Impresion>& fila_impresiones){

    //Se crea un condicional que verifica que la cola este vacia, si es el caso no hay impresiones pendientes
    if (fila_impresiones.empty()){
        cout << "No hay impresiones pendientes" << endl;
        return;
    }

    //Para imprimir las impresiones pendientes
    cout << "Impresiones pendientes: " << endl;

    //Se inicializa la variable en 1 porque si es 0 significa que esta vacia y seria reiterar lo que hicimos con el condicional anterior
    int num_impresion = 1;

    //Creamos una cola temporal para no modificar la original
    queue<Impresion> fila_temp = fila_impresiones;
    //Se hace un condicional, que verifica que la cola temporal no este vacia 
    while (!fila_temp.empty()){
        //Se verifica cual es el elemento que ingreso primero y por lo tanto saldra de primeras
        const Impresion& impresion = fila_temp.front();
        cout << num_impresion << " Documento: " << impresion.documento << ", Paginas: " << impresion.paginas << endl;
        //Se elimina la cola temporal 
        fila_temp.pop();
        //Aumenta la variable cada vez que el usuario desea ingresar una nueva impresion
        num_impresion++;
    }
}

//Se crea una funcion que tiene como parametro la direccion de la cola que creamos 
void agregarImpresiones(queue<Impresion>& fila_impresiones){

    //Inicializamos las variables 
    string documento;
    int paginas;

    //Se le pide al usuario ingresar el nombre del documento
    cout << "Ingrese el nombre del documento: " << endl;
    //Almacenamos la entrada en una variable
    cin >> documento;

    //Se le pide al usuario ingresar el numero de paginas
    cout << "Ingrese el numero de paginas: " << endl;
    //Almacenamos la entrada en una variable
    cin >> paginas;

    Impresion nueva = {documento, paginas};
    fila_impresiones.push(nueva);

    cout << "Se agrego \"" << documento << "\" a la cola de impresiones" << endl;

}

void menu () {

    cout << "Bienvenido al sistema de impresiones" << endl;
    cout << "1.Agregar impresion a la cola" << endl;
    cout << "2.Mostrar impresiones pendientes" << endl;
    cout << "3.Salir" << endl;
    cout << "Ingrese la opcion que desea realizar: " << endl;
}

int main () {

    queue<Impresion> fila_impresiones;
    int opcion;

    do {

        menu();
        cin >> opcion;

        switch(opcion){
            case 1:
            agregarImpresiones(fila_impresiones);
            break;

            case 2:
            mostrarPendientes(fila_impresiones);
            break;

            case 3:
            break;

            default:
            cout << "Opcion no valida" << endl;
        }
        
    }while (opcion != 3);

    return 0;
}