#include <iostream>
#include <queue>
using namespace std;

//Se define una estructura que almacena los datos requeridos para registrar a un cliente
struct Cliente {

    long int identificacion;
    string nombre;

};

//Se crea una funcion que permite registrar a un cliente en la estructura previamente creada
Cliente registrarCliente() {

    //Se instancia la estructura con un objeto 
    Cliente nuevoCliente;

    //Se le solicita al usuario el id
    cout << "Ingrese su ID: " << endl;
    //Se guarda el valor ingresado en la estructura Cliente
    cin >> nuevoCliente.identificacion;

    //Se le solicita al usuario el nombre 
    cout << "Ingrese su nombre: " << endl;
    //Se guarda el valor ingresado en la estructura Cliente
    cin >> nuevoCliente.nombre;

    cout << "El usuario se ha registrado con exito!" << endl;

    cout << "--------------------------------------" << endl;
    cout << endl;

    return nuevoCliente;
};

//Se crea una funcion que le permite al usuario ingresar a la fila virtual
void ingresarFila( queue<Cliente>& filaClientes){

    long int identificacion;

    //Se solicita el id del cliente
    cout << "Ingrese su ID: " << endl;
    cin >> identificacion;

    bool registrado = false;
    int posicion = 1;
    string nombreCliente = "";

    //Se crea una cola temporal para no modificar la original
    queue<Cliente> tempFila = filaClientes;
    //Se verifica que la cola temporal no este vacia
    while (!tempFila.empty()){
        //Se verifica que el id registrado sea igual que el id que se pide para ingresar a la fila
        if (tempFila.front().identificacion == identificacion){
            //Se cambia el estado del booleano para que se salga
            registrado = true;
            //Se busca el nombre registrado del cliente para poderlo imprimir 
            nombreCliente = tempFila.front().nombre;
            break;
        }
        //Se elimina la cola temporal
        tempFila.pop();
        //Cada que un usuario nuevo ingrese a la fila virtual la posicion en la cola aumenta
        posicion++;
    }   

    cout << endl;

    //Se crea un condicional, donde se utiliza el booleano true para mostrar el mensaje al cliente
    if (registrado){

        cout << "Sr(a) " << nombreCliente << " usted esta en la posicion " << posicion << " de la fila" << endl;
        cout << "El tiempo estimado de espera es de aproximadamente " << posicion << " minuto(s)" << endl;

    } else {

        //Si el booleano sigue siendo false muestra el siguiente mensaje 
        cout << "Usted no esta registrado. Por favor, registrese para poder ingresar a la fila" << endl;
    }

    cout << "---------------------------------------------" << endl;
    cout << endl;
}

void menu(){

    //Se crea una funcion menu, que contiene 3 opciones que el cliente puede realizar     
    cout << "Bienvenido a e-ticket" << endl;
    cout << "1.Registrame" << endl;
    cout << "2.Ingresar a la fila virtual" << endl;
    cout << "3.Salir" << endl;
    cout << "Ingrese la opcion que desea realizar: " << endl;
}

//Se crea el ejecutable
int main () {

    //Se crea la cola que tiene los elementos de la estructura cliente
    queue<Cliente> filaClientes;
    int opcion;

    //Se crea un bucle do-while, que contiene un switch con los casos posibles que pueda elegir el usuario 
    do {

        menu();
        cin >> opcion;
        cout << "---------------------" << endl;
        cout << endl;
    
        switch(opcion){

            case 1:

            filaClientes.push(registrarCliente());
            break;

            case 2:

            ingresarFila(filaClientes);
            break;

            case 3:
            break;

            default:
            cout << "Opcion no valida" << endl;
            break;

        }
        
    } while (opcion != 3);

    return 0;
}