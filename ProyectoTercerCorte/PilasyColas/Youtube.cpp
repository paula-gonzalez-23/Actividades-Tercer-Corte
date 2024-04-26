#include <iostream>
#include <stack>
#include <string>
using namespace std;

class CancionesFav{

    private:

    stack<string> canciones;

    public: 

    void agregarCancion(){
        
        string cancion;

        cout << "Ingrese el nombre de la cancion que quiere agregar: " << endl;
        cin >> cancion; 

        canciones.push(cancion);
    }

    void verCancionesFav(){

        if (!canciones.empty()){
            cout << "Lista de canciones favoritas: " << endl;
            stack<string> temp = canciones;
            while (!temp.empty()){
                cout << temp.top() << endl;
                temp.pop();
            }
        } else {
            cout << "No hay cqanciones en la lista de reproduccion" << endl;
        }
    }
};

int main(){

    CancionesFav user;

    user.agregarCancion();

    user.verCancionesFav();

    return 0;
}