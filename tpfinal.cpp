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