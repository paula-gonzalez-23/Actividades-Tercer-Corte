#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main () {

    //Conjunto = estructura de datos que almacen una coleccion de elementos unicos sin orden especifico
    //Cumple ciertas caracteristicas:
    //No se permiten elementos duplicaods, no se ordenan de ninguna manera especfica
    //El set proporciona un acceso rapido a los elementos mediantes la busqueda binaria


    //Se crea el conjunto que almacena datos tipo int 
    set<int> conjunto;
    set<int> conjunto2 = {5, 6, 7, 8};

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

    //Se crea el conjunto que almacena la union entre los conjuntos
    set<int> unionConjuntos;
    
    //Se usa la funcion merge, para unir los conjuntos
    //Se recorre el conjunto y el conjunto2 
    //Se inserta la union en el nuevo conjunto creado
    merge(conjunto.begin(), conjunto.end(), conjunto2.begin(), conjunto2.end(),
        inserter(unionConjuntos, unionConjuntos.begin()));

    //Se crea el iterador para imprimir los elementos del conjunto
    for (auto it : unionConjuntos){
        cout << it << " ";
    }
    cout << endl;

    //Se crea el conjunto que almacena la interseccion entre los conjuntos
    set<int> interseccionConjuntos;

    //Se usa la funcion set_intersection, para intersectar los conjuntos
    //Se recorre el conjunto y el conjunto2
    //Se inserta la interseccion en el nuevo conjunto creado
    set_intersection(conjunto.begin(), conjunto.end(), conjunto2.begin(), conjunto2.end(),
        inserter(interseccionConjuntos, interseccionConjuntos.begin()));

    //Se crea el iterador para imprimir los elementos del conjunto
    for (auto it : interseccionConjuntos){
        cout << it << " ";
    }
    cout << endl;

    //Se crea el conjunto que almacena la diferencia entre los conjuntos
    set<int> diferenciaConjuntos;

    //Se usa la funcion set_difference, para hallar la diferencia de los conjuntos
    //Se recorre el conjunto y el conjunto2
    //Se inserta la interseccion en el nuevo conjunto creado
    set_difference(conjunto.begin(), conjunto.end(), conjunto2.begin(), conjunto2.end(),
        inserter(diferenciaConjuntos, diferenciaConjuntos.begin()));

    //Se crea el iterador para imprimir los elementos del conjunto 
    for (auto it : diferenciaConjuntos){
        cout << it << " ";
    }
    cout << endl;
    
    return 0;
}