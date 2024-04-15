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

void agregarDepartamento(map<string, Departamento>& Colombia, const string& nombre, const string& capital, const string& clima){
    Colombia[nombre] = {capital, clima};
}

pair<string, string> infoDepartamento(const map<string, Departamento>& Colombia, const string& departamento){
    auto it = Colombia.find(departamento);
    if (it != Colombia.end()){
        return make_pair(it -> second.capital, it -> second.clima);
    } else {
        return make_pair("", "");
    }
}

set<string> buscarxClima(const map<string, Departamento>& Colombia, const string& clima){
    set<string> ciudades;
    for (const auto& par : Colombia){
        if (par.second.clima == clima) {
            ciudades.insert(par.second.capital);
        }
    }

    return ciudades;
}

int main() {

    string departamento, clima;

    map<string, Departamento> Colombia;

    agregarDepartamento(Colombia, "Amazonas", "Leticia", "Tropical");
    agregarDepartamento(Colombia, "Antioquia", "Medellin", "Subtropical");
    agregarDepartamento(Colombia, "Atlantico", "Barranquilla", "Tropical");

    cout << "Ingrese el departamento del que requiere informacion: " << endl;
    cin >> departamento;

    auto informacion = infoDepartamento(Colombia,departamento);
    if (informacion.first != ""){
        cout << "La capital de " << departamento << " es " << informacion.first << " y su clima es: " << informacion.second << endl;
    } else {
        cout << "El departamento no existe en los registros" << endl;
    }

    cout << "Ingrese el clima por el que quiere buscar los departamentos: " << endl;
    cin >> clima;

    set<string> ciudades = buscarxClima(Colombia, clima);
    cout << "Ciudades con clima " << clima << ": ";
    for (const auto& ciudad : ciudades){
        cout << ciudad << ", ";
    } 
    cout << endl;

    return 0;

}