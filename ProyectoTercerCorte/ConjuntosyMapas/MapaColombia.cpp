#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

//Creamos una estructura para representar la informacion que necesitamos de un departamento, capital y clima
struct Departamento {

    string capital;
    string clima;
};

//Creamos el mapa que contiene como valor el departamento y como clave la estructura que ya se definio que contiene capital y clima
map<string, Departamento> Colombia;

//Se crea la funcion que permite agregar un nuevo departamento al mapa
void agregarDepartamento(){

    //Se declaran las variables necesarias
    string ciudad, capital, clima;

    //Se le solicita al usuario los datos necesarios
    cout << "Ingrese el nombre de la ciudad: " << endl;
    cin >> ciudad;

    cout << "Ingrese la capital de la ciudad: " << endl;
    cin >> capital;

    cout << "Ingrese el clima de la ciudad que ya ingreso: " << endl;
    cin >> clima;

    //Se agrega el elemento al mapa
    Colombia[ciudad] = {capital,clima};

};

//Se crea una funcion para obtener la informacion de un departamento
//Esta devuelve un par de strings que representan capital y clima
pair<string, string> infoDepartamento(){

    //Se declara la variable necesaria
    string departamento;

    //Se solicita la informacion necesaria al usuario
    cout << "Ingrese el departamento del que requiere informacion: " << endl;
    cin >> departamento;

    //Se busca el departamento en el mapa
    auto it = Colombia.find(departamento);
    if (it != Colombia.end()){
        //Si se encuentra el departamento, se imprime la capital y el clima
        cout << "La capital de " << departamento << " es " << it->second.capital << " y su clima es: " << it->second.clima << endl;
        return make_pair(it -> second.capital, it -> second.clima);
    } else {
        //Si no se encuentra, se muestra un mensaje de error
        cout << "El departamento no existe en los registros" << endl;
        return make_pair("", "");
    }

};

//Se crea una funcion para buscar las ciudades por el clima
//Esta devuelve un conjunto que contiene todas las ciudades que tienen ese clima
set<string> buscarxClima(){

    //Se declara la variable 
    string clima;

    //Se solicita la informacion necesaria al usuario
    cout << "Ingrese el clima por el que quiere buscar los departamentos: " << endl;
    cin >> clima;

    //Se crea un conjunto para almacenar las ciudades con el clima especificado
    set<string> ciudades;
    for (const auto& par : Colombia){
        if (par.second.clima == clima) {
            ciudades.insert(par.second.capital);
        }
    }

    //Se imprime las ciudades con el clima especificado
    cout << "Ciudades con clima " << clima << ": ";
    for (const auto& ciudad : ciudades){
        cout << ciudad << ", ";
    } 
    cout << endl;

    return ciudades;

};

//Se crea el menu del programa
void menu(){

    cout << "Bienvenido al Mapa de Colombia" << endl;
    cout << "Elija la opcion que desea realizar" << endl;
    cout << "1.Agregar un departamento al mapa" << endl;
    cout << "2.Averiguar informacion de un departamento" << endl;
    cout << "3.Buscar ciudades por clima especifico" << endl;
    cout << "4.Salir" << endl;
}

//Se crea el main y se invocan las funciones creadas anteriormente
int main() {

    int opcion;

    do{
        menu();

        cout << "Ingrese su opcion: " << endl;
        cin >> opcion;

        switch(opcion){
            case 1:
            agregarDepartamento();
            break;
            
            case 2:
            infoDepartamento();
            break;

            case 3:
            buscarxClima();
            break;
            
            case 4:
            break;
             
            default:
            cout << "Opcion no valida" << endl;
            break;

        }

    }while(opcion != 4);
   
    
    return 0;

}