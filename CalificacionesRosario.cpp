#include <iostream>
#include <map>
using namespace std;

void registrarNota(map<string, map<string, int>>&registro, string nombreEstudiante, string asignatura, int nota){
    registro[nombreEstudiante][asignatura] = nota;
}

int mostrarNota(const map<string, map<string, int>>& registro, string nombreEstudiante, string asignatura){
    auto itEstudiante = registro.find(nombreEstudiante);
    if (itEstudiante != registro.end()){
        auto itAsignatura = itEstudiante -> second.find(asignatura);
        if (itAsignatura != itEstudiante -> second.end()){
            return itAsignatura -> second;
        }
    }

    return -1; //La nota no se encontro
}

double calcularPromedioEstudiante(const map<string, map<string, int>>& registro, string nombreEstudiante){
    auto itEstudiante = registro.find(nombreEstudiante);
    if (itEstudiante != registro.end()){
        double sumaNotas = 0;
        int cantidadAsignaturas = itEstudiante -> second.size();
        for (const auto& par : itEstudiante -> second){
            sumaNotas += par.second;
        }

        return sumaNotas / cantidadAsignaturas;
    }

    return -1; //No se encontraron notas para el estudiante
}

double calcularPromedioAsignatura(const map<string, map<string, int>>& registro, string asignatura){
    double sumaNotas = 0;
    int cantidadEstudiantes = 0;
    for (const auto& estudiante : registro){
        auto itAsignatura = estudiante.second.find(asignatura);
        if (itAsignatura != estudiante.second.end()){
            sumaNotas += itAsignatura -> second;
            cantidadEstudiantes++;
        }
    }

    if (cantidadEstudiantes > 0){
        return sumaNotas / cantidadEstudiantes;
    }

    return -1;
}

int main(){

    map<string, map<string, int>> registro_notas;

    registrarNota(registro_notas, "Juan", "Matematicas", 85);
    registrarNota(registro_notas, "Valentina", "Ingles", 60);
    registrarNota(registro_notas, "Juan", "Ingles", 50);

    cout << "Nota de Juan en Ingles: " << mostrarNota(registro_notas, "Juan", "Ingles") << endl;

    cout << "Promedio de notas de Juan: " << calcularPromedioEstudiante(registro_notas, "Juan") << endl;

    cout << "Promedio de notas de Ingles: " << calcularPromedioAsignatura(registro_notas, "Ingles") << endl;
    
    return 0;
}