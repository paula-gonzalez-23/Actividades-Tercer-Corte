#include <iostream>
#include <map>
using namespace std;

//Se crea la funcion para registrar la nota de un estudiante en una asignatura
void registrarNota(map<string, map<string, int>>&registro, string nombreEstudiante, string asignatura, int nota){
    //Asigna la nota correspondiente a la asignatura del estudiante registrado
    registro[nombreEstudiante][asignatura] = nota;
}

//Se crea la funcion para mostrar la nota de un estudiante en una asignatura
int mostrarNota(const map<string, map<string, int>>& registro, string nombreEstudiante, string asignatura){
    //Se busca el estudiante en el registro
    auto itEstudiante = registro.find(nombreEstudiante);
    if (itEstudiante != registro.end()){
        //Se busca la asignatura para ese estudiante
        auto itAsignatura = itEstudiante -> second.find(asignatura);
        if (itAsignatura != itEstudiante -> second.end()){
            //Devuelve la nota correspondiente
            return itAsignatura -> second;
        }
    }

    //Si la nota no se encuentra devuelve -1
    return -1; //La nota no se encontro
}

//Se crea la funcion para calcular el promedio de notas de un estudiante
double calcularPromedioEstudiante(const map<string, map<string, int>>& registro, string nombreEstudiante){
    //Se busca al estudiante en el registro
    auto itEstudiante = registro.find(nombreEstudiante);
    if (itEstudiante != registro.end()){ //Si se encuentra el estudiante en el registro
        double sumaNotas = 0;
        //Se calcula la suma de todas las notas del estudiante
        for (const auto& par : itEstudiante -> second){
            sumaNotas += par.second;
        }

        //Se calcula el promdio dividiendo la suma de notas entre la cantidad de asignaturas
        int cantidadAsignaturas = itEstudiante -> second.size();
        return sumaNotas / cantidadAsignaturas;
    }

    return -1; //No se encontraron notas para el estudiante
}

//Se crea la funcion para calcular el promedio de notas de una asignatura
double calcularPromedioAsignatura(const map<string, map<string, int>>& registro, string asignatura){
    double sumaNotas = 0;
    int cantidadEstudiantes = 0;
    //Se crea un for que itera sobre todos los estudiantes en el registro
    for (const auto& estudiante : registro){
        //Se busca la asignatura para el estudiante actual
        auto itAsignatura = estudiante.second.find(asignatura);
        if (itAsignatura != estudiante.second.end()){
            //Suma la nota de la asignatura al total
            sumaNotas += itAsignatura -> second;
            //Se incrementa la cantidad de estudiantes que tienen la asignatura
            cantidadEstudiantes++;
        }
    }

    //Si hay estudiantes con esa asignatura, calcula y devuelve el promedio
    if (cantidadEstudiantes > 0){
        return sumaNotas / cantidadEstudiantes;
    }

    //Si no se encuentran estudiantes con notas para la asignatura, devuelve -1
    return -1;
}

int main(){

    //Mapa para almacenar el registro de notas
    map<string, map<string, int>> registro_notas;

    //Registrar algunas notas como datos quemados
    registrarNota(registro_notas, "Juan", "Matematicas", 85);
    registrarNota(registro_notas, "Valentina", "Ingles", 60);
    registrarNota(registro_notas, "Juan", "Ingles", 50);

    //Mostrar la nota de Juan en Ingles
    cout << "Nota de Juan en Ingles: " << mostrarNota(registro_notas, "Juan", "Ingles") << endl;

    //Calcular el promedio de notas de Juan
    cout << "Promedio de notas de Juan: " << calcularPromedioEstudiante(registro_notas, "Juan") << endl;

    //Calcular el promedio de notas de la asignatura de Ingles
    cout << "Promedio de notas de Ingles: " << calcularPromedioAsignatura(registro_notas, "Ingles") << endl;
    
    return 0;
}