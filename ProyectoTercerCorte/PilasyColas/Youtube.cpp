#include <iostream>
#include <stack>
#include <string>
using namespace std;

//Se declara la clase Canciones Fav
class CancionesFav{

    private:

    //Se declara una pila para almacenar las canciones
    stack<string> canciones;

    public: 

    //Se crea el constructor de la clase
    CancionesFav(){


    }

    //Se crea una funcion para agregar un cancion a la pila
    void agregarCancion(){
        
        //Se declara la variable necesaria
        string cancion;

        //Se solicita al usuario los datos necesarios
        cout << "Ingrese el nombre de la cancion que quiere agregar: " << endl;
        cin >> cancion; 

        //Se agrega la cancion a la pila
        canciones.push(cancion);
    }

    //Se crea la funcion para mostrar las canciones favoritas
    void verCancionesFav(){

        //Se verifica si la pila no esta vacia
        if (!canciones.empty()){
            cout << "Lista de canciones favoritas: " << endl;
            //Se crea una copia temporal de la pila de canciones
            stack<string> temp = canciones;
            //Se verifica que la pila temporal no este vacia
            while (!temp.empty()){
                //Imprime el elemento en el top de la pila temporal
                cout << temp.top() << endl;
                //Elimina el elemento en el top de la pila temporal
                temp.pop();
            }
        } else {
            //Mensaje si la pila de canciones esta vacia
            cout << "No hay canciones en la lista de reproduccion" << endl;
        }
    }
};

int main(){

    //Se crea un objeto de la clase que ya se creo
    CancionesFav user;


    //Se invocan los metodos creados 
    user.agregarCancion();

    user.verCancionesFav();

    return 0;
}