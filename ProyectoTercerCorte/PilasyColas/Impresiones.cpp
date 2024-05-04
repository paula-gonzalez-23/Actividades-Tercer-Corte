//Crear un sistema que permita llevar un orden de las impresiones en una oficina
//Mostrar lo que ya imprimio y lo que le falta por imprimir 
#include <iostream>
#include <queue>
using namespace std;

struct Impresion {

    string documento;
    int paginas;

};

void mostrarPendientes(const queue<Impresion>& fila_impresiones){

    if (fila_impresiones.empty()){
        cout << "No hay impresiones pendientes" << endl;
        return;
    }

    cout << "Impresiones pendientes: " << endl;
    int num_impresion = 1;

    queue<Impresion> fila_temp = fila_impresiones;
    while (!fila_temp.empty()){
        const Impresion& impresion = fila_temp.front();
        cout << num_impresion << "Documento: " << impresion.documento << ", Paginas: " << impresion.paginas << endl; 
        fila_temp.pop();
        num_impresion++;
    }
}

void agregarImpresiones(queue<Impresion>& fila_impresiones){

    string documento;
    int paginas;

    cout << "Ingrese el nombre del documento: " << endl;
    cin >> documento;

    cout << "Ingrese el numero de paginas: " << endl;
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