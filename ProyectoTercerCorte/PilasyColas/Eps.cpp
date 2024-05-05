#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Turnos{

    private:

    queue<string> turno;

    public:

    void obtenerTurno(){

        string nombre;

        cout << "Ingrese su nombre: " << endl;
        cin >> nombre;
        turno.push(nombre);

        cout << nombre << ", su turno ha sido registrado" << endl;
    }

    void llamarTurno(){

        if (!turno.empty()){
            string paciente = turno.front();
            turno.pop();
            cout << "Atendiendo a: " << paciente << endl;
        } else {
            cout << "No hay pacientes en espera" << endl;
        }
    }

    void pacientesEspera(){

        if (!turno.empty()){
            cout << "Pacientes en espera: " << endl;
            queue<string> temp = turno;
            while (!temp.empty()){
                cout << temp.front() << endl;
                temp.pop();
            }
        } else {
            cout << "No hay pacientes en espera" << endl;
        }
    }
};

int main (){

    Turnos user;

    user.obtenerTurno();
    user.obtenerTurno();
    user.llamarTurno();
    user.llamarTurno();
    user.pacientesEspera();

    return 0;
}