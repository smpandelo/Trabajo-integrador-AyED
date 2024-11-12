/*Se solicita:
Realizar un menú para administrar los turnos:
Altas:
Nuevo paciente
Nuevo turno: el alta debe darse como turno pendiente(P), 
pero se deberá validar que no exista otro turno 
ya dado al paciente para ese médico y que el médico no
tenga turnos tomados en ese horario.
Nuevo médico
Actualizaciones:
Dado el id de médico y de turno se debe poder actualizar el status
Listados:
Turnos pendientes para un mes determinado, para un idmedico dado
Cantidad de atenciones efectivas (status A) de todos los médicos del 
sistema para un mes determinado.
Listado de cancelaciones para un mes determinado con los siguientes datos:
Nombre del paciente, nombre del médico, especialidad, día de atención.
Se pueden utilizar todas las estructuras auxiliares que crean necesarias.
No pueden utilizar bibliotecas externas.
La entrega debe contener todos los archivos para realizar las pruebas y
una rutina de carga automática de la lista para poder utilizar el sistema 
y verificar su funcionamiento.*/

#include <iostream>
#include <cstring>

using namespace std;

struct pacientes{
    int id;
    char nom[51];
    char ape[51];
    int edad;
    int dni;
    int telefono;

};

struct nodo{
    turnos info;
    nodo*sgte;
};

struct dia{
    bool atiende;
    nodo*lista;
};

struct turnos{
    int idunico;
    int hora;
    int dia;
    int mes;
    char status[2];
    int idpacientes;
};

struct medico{
    int id;
    char nom[51];
    char ape[51];
    int matricula;
    int idespe;
    dia atencion[7];
    int rangohor[2];
    int tiempocon;

};


int main(){
    
    char espe[20][51];


    return 0;
}

void Menu()
{
    bool salir = false;
    int opcion;
    while(!salir)
    {
        cout << "Sistema de turnos de clinica" << endl;
    

        cout << "1. Altas " << endl;
        cout << "2. Actualizaciones " << endl;
        cout << "3. Listados" << endl;
        cout << "0. Salir "<<endl;

        cout<<"Selecione una opcion "<<endl;
        cin >> opcion;

        if(opcion == 1)
        {

        }
        else if(opcion == 2)
        {

        }
        else if(opcion == 3)
        {

        }
        else if(opcion == 0)
        {
            cout << "Usted esta saliendo del programa"<<endl;
            salir = true;
        }
        else
        {
            cout<< "Seleccione una opcion correcta"<<endl;
        }


    }

    
}

void mostrarAltas()
{

}

void nuevoTurno()
{

}

void nuevoMedico()
{

}

void nuevoPaciente()
{

}

void mostrarActualizaciones()
{

}

void mostrarListados()
{
    
}

