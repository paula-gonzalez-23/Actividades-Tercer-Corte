#include <iostream>
#include <map>
using namespace std;

int main (){

    //Mapa = es un tipo de contenedor que se utiliza para almacenar pares clave-valor
    //Clave = es un identificador  unico que se utiliza para acceder al valor asociado
    //Valor = es el dato que se almacena en el mapa
    //Son contenedores ordenados, los elementos se almacenan en orden ascendente por la clave\
    //No se permite las claves duplicadas, si se intenta insertar una clave que ya existe, se sobreescribira el valor asociado

    int valorPredeterminado = 35;

    //Se crea el mapa, almacena una clave de tipo string y un valor tipo entero
    map<string,int> edades;
    map<string,int> edades2 = {{"Andres", 50}, {"Valentina", 60}};

    //Se agregan por dos metodos tres claves y tres valores
    edades["Juan"] = 20;
    edades["Paula"] = 18;
    edades.insert(make_pair("Pedro", 15));

    for (auto it = edades.begin(); it != edades.end(); ++it){
        cout << it -> first << " : " << it -> second << endl;
    }

    //Se obtiene el valor de la edad de Pedro
    int edadPedro = edades["Pedro"];
    
    //Se imprime la edad de Pedro
    cout << "La edad de Pedro es: " << edadPedro << endl;

    //Se modifica le edad de juan que ahora es 10
    edades["Juan"] = 10;

    //Se borra a Pedro del mapa
    edades.erase("Pedro");

    //Se crea un iterador para buscar con la clave en el mapa para saber si existe o no
    auto it = edades.find("Juan");
    if (it != edades.end()){
        cout << "Juan si esta en el mapa" << endl;
    } else {
        cout << "Juan no esta en el mapa" << endl;
    }   

    //Se obtiene el tamanio del mapa
    int totalPersonas = edades.size();

    //Se imprime el mapa
    for (auto it = edades.begin(); it != edades.end(); ++it){
        cout << it -> first << " : " << it -> second << endl;
    }

    //Buscar una si una clave esta presente en el mapa y si no agregarla como valor predeterminado
    if (edades.find("Paula") == edades.end()){
        edades["Paula"] = valorPredeterminado;
    }

    //Se combina el mapa 1 edades, en el mapa 2 edades 2
    edades2.insert(edades.begin(), edades.end());

    //Se imprime el mapa 2 combinado 
    for (const auto& par : edades2){
        cout << par.first << ": " << par.second << endl;
    }
    
    return 0;
}