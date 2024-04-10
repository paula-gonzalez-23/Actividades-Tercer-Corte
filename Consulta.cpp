#include <iostream>
#include <set>
using namespace std;

int main () {

    //Conjunto = estructura de datos que almacen una coleccion de elementos unicos sin orden especifico
    //Cumple ciertas caracteristicas:
    //No se permiten elementos duplicaods, no se ordenan de ninguna manera especfica
    //El set proporciona un acceso rapido a los elementos mediantes la busqueda binaria


    //Se crea el conjunto que almacena datos tipo int 
    set<int> conjunto;

    //Se insertan elementos al conjunto 
    //Se insertan dos veces el 1 pero como no se pueden datos repetidos solo quedara una vez
    conjunto.insert(1);
    conjunto.insert(5);
    conjunto.insert(1);
    conjunto.insert(4);

    //Se crea un iterador que recorre el conjunto 
    for (auto it = conjunto.begin(); it != conjunto.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    //Se verifica si un elemento esta en el conjunto o no 
    if (conjunto.find(1) != conjunto.end()){
        cout << "El elemento 1 esta en el conjunto" << endl;\
    } else {
        cout << "El elemento 1 no esta en el conjunto" << endl;
    }

    //Se obtiene el tamanio del conjunto
    cout << "Tamanio del conjunto: " << conjunto.size() << endl;

    //Se elimina un elemento del conjunto 
    conjunto.erase(4);

    //Se verifica si un elemento esta en el conjunto o no 
    if (conjunto.find(4) != conjunto.end()){
        cout << "El elemento 4 esta en el conjunto" << endl;\
    } else {
        cout << "El elemento 4 no esta en el conjunto" << endl;
    }   

    //Se crea un iterador que recorre el conjunto
    for (auto it = conjunto.begin(); it != conjunto.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;


    return 0;
}