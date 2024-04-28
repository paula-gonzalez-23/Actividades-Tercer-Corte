#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

//Creamos una estructura para representar la informacion que necesitamos de un departamento
struct Departamento {

    string capital;
    string clima;
};

map<string, Departamento>& Colombia;

void agregarDepartamento(){

    string ciudad, capital, clima;

    cout << "Ingrese el nombre de la ciudad: " << endl;
    cin >> ciudad;

    cout << "Ingrese la capital de la ciudad: " << endl;
    cin >> capital;

    cout << "Ingrese el clima de la ciudad que ya ingreso: " << endl;
    cin >> clima;

    Colombia[ciudad] = {capital,clima};

};

pair<string, string> infoDepartamento(){

    string departamento;

    cout << "Ingrese el departamento del que requiere informacion: " << endl;
    cin >> departamento;

    auto it = Colombia.find(departamento);
    if (it != Colombia.end()){
        cout << "La capital de " << departamento << " es " << it->second.capital << " y su clima es: " << it->second.clima << endl;
        return make_pair(it -> second.capital, it -> second.clima);
    } else {
        cout << "El departamento no existe en los registros" << endl;
        return make_pair("", "");
    }

};

set<string> buscarxClima(){

    string clima;

    cout << "Ingrese el clima por el que quiere buscar los departamentos: " << endl;
    cin >> clima;

    set<string> ciudades;
    for (const auto& par : Colombia){
        if (par.second.clima == clima) {
            ciudades.insert(par.second.capital);
        }
    }

    cout << "Ciudades con clima " << clima << ": ";
    for (const auto& ciudad : ciudades){
        cout << ciudad << ", ";
    } 
    cout << endl;

    return ciudades;

};

d
int main() {

    agregarDepartamento();
    agregarDepartamento();

    infoDepartamento();

    buscarxClima();
    
    return 0;

}