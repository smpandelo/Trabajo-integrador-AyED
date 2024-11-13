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

template <typename T> struct Nodo {
    T info;
    Nodo<T> *sgte;
};

template <typename T, typename U> Nodo<T> *buscar(Nodo<T> *lista, U buscado, int (*criterio)(T, U)) {
    Nodo<T> *aux = lista;

    while (aux != NULL && criterio(aux->info, buscado) != 0) {
        aux = aux->sgte;
    }

    return aux;
}

template <typename I> Nodo<I> *insertarOrdenado(Nodo<I> *&lista, I dato, int (*criterio)(I, I)) {
	Nodo<I> *p = new Nodo<I>();
	p->info = dato;
	p->sgte = NULL;

	if (lista == NULL || criterio(dato, lista->info) <= 0) {
		p->sgte = lista;
		lista = p;
	} else {
		Nodo<I> *q = lista;

		while (q->sgte != NULL && criterio(q->sgte->info, dato) <= 0) {
			q = q->sgte;
		}

		p->sgte = q->sgte;
		q->sgte = p;
	}

	return p;
}

struct Paciente {
    int id;
    char nom[51];
    char ape[51];
    int edad;
    int dni;
    int telefono;

};

struct Turno {
    int idUnico;
    int hora;
    int dia;
    int mes;
    char status;
    int idPaciente;
};

struct Registro {
    int idMedico;
    Nodo<Turno> *turnos[12][31];
};

struct Medico {
    int id;
    char nom[51];
    char ape[51];
    int matricula;
    int idEspe;
    bool atencion[7];
    int rangoHor[2];
    int tiempoCon;
};


void menu(Nodo<Registro>*&, FILE*&, FILE*&, char[][51]);
void mostrarAltas(Nodo<Registro>*&, FILE*&, FILE*&);
void mostrarActualizaciones();
void mostrarListados();
void nuevoTurno();
void nuevoMedico();
void nuevoPaciente(FILE*&);

int main() {
    char especialidades[20][51] ={"Cardiología", "Neurología", "Pediatría", "Ginecología", "Psiquiatría", "Dermatología", "Oftalmología", "Ortopedia", "Oncología", "Geriatría", "Endocrinología", "Nefrología", "Gastroenterología", "Neumología", "Reumatología", "Hematología", "Infectología", "Cirugía General", "Urología", "Medicina de Emergencias"};
    Nodo<Registro> *registro = NULL;
    FILE *pacientes = fopen("pacientes.bin", "rb+");
    FILE *medicos = fopen("medicos.bin", "rb+");

    menu(registro, pacientes, medicos, especialidades);

    return 0;
}

int criterioMedico(Registro lista, int dato) {
    return lista.idMedico - dato;
}

int criterioPaciente(Turno lista, int dato) {
    return lista.idPaciente - dato;
}

int criterioHora(Turno lista, int dato) {
    return lista.hora - dato;
}

int criterioTurno(Turno lista, Turno dato) {
    return lista.hora - dato.hora;
}

int criterioID(Turno lista, int dato) {
    return lista.idUnico - dato;
}

void menu(Nodo<Registro> *&registro, FILE *&pacientes, FILE *&medicos, char especialidades[][51]) {
    bool salir = false;
    int opcion;

    while (!salir) {
        cout << "\033[2J\033[1;1H"; // idea de facu semmartin
        cout << "Menu" << endl;
        cout << "1. Altas"  << endl;
        cout << "2. Actualizaciones" << endl;
        cout << "3. Listados" << endl;
        cout << "0. Salir" << endl;

        cout << "Selecione una opcion: " << endl;
        cin >> opcion;

        if (opcion == 1) {
            mostrarAltas(registro, pacientes, medicos);
        }
        else if (opcion == 2) {

        }
        else if(opcion == 3)
        {
            mostrarlistado()
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

void mostrarAltas(Nodo<Registro> *&registro, FILE *&pacientes, FILE *&medicos) {
    bool salir = false;
    int opcion;

    while (!salir) {
        cout << "\033[2J\033[1;1H"; // idea de facu semmartin
        cout << "Menu de altas" << endl;
        cout << "1. Nuevo paciente" << endl;
        cout << "2. Nuevo turno" << endl;
        cout << "3. Nuevo medico" << endl;
        cout << "0. Salir" << endl;

        cout << "Selecione una opcion: " << endl;
        cin >> opcion;

        if (opcion == 1) {
            nuevoPaciente(pacientes);
        }
        else if (opcion == 2) {

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

void nuevoPaciente(FILE *&pacientes) {
    Paciente paciente, aux;

    cout << "ID: ";
    cin >> paciente.id;
    cout << "Nombre: ";
    cin >> paciente.nom;
    cout << "Apellido: ";
    cin >> paciente.ape;
    cout << "Edad: ";
    cin >> paciente.edad;
    cout << "DNI: ";
    cin >> paciente.dni;
    cout << "Telefono: ";
    cin >> paciente.telefono;

    cout << "Actualizando archivo de pacientes y volviendo al menu de altas." << endl;

    fseek(pacientes, 0, SEEK_END);
    fwrite(&paciente, sizeof(paciente), 1, pacientes);
}

void nuevoTurno(Nodo<Registro> *&reg) {
    int idMedico, i = 0;
    Turno turn;
    Nodo<Registro> *medico = NULL;
    Nodo<Turno> *aux = NULL;

    cout << "ID del medico: ";
    cin >> idMedico;

    medico = buscar(reg, idMedico, criterioMedico);

    if (medico == NULL) {
        cout << "No se encontro el medico" << endl;

        return;
    }

    cout << "ID del paciente: ";
    cin >> turn.idPaciente;


    cout << "Mes: ";
    cin >> turn.mes;

    while (i < 31 && aux == NULL) {
        aux = buscar(medico->info.turnos[turn.mes - 1][i], turn.idPaciente, criterioPaciente);
        i++;
    }

    if (aux != NULL) {
        cout << "El paciente ya tiene un turno asignado" << endl;

        return;
    }

    cout << "Dia: ";
    cin >> turn.dia;
    cout << "Hora: ";
    cin >> turn.hora;

    aux = buscar(medico->info.turnos[turn.mes - 1][turn.dia - 1], turn.hora, criterioHora);

    if (aux != NULL) {
        cout << "Ese horario ya esta ocupado" << endl;

        return;
    }

    cout << "ID unico: ";
    cin >> turn.idUnico;

    turn.status = 'P';

    cout << "Agregando turno a la lista y volviendo al menu de altas" << endl;

    insertarOrdenado(medico->info.turnos[turn.mes - 1][turn.dia - 1], turn, criterioTurno);
}

void nuevoMedico(FILE *&medicos) {
    int i;
    char semana[7][10] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
    Medico medico, aux;

    cout << "ID: ";
    cin >> medico.id;
    cout << "Nombre: ";
    cin >> medico.nom;
    cout << "Apellido: ";
    cin >> medico.ape;
    cout << "ID de la especialidad: ";
    cin >> medico.idEspe;
    cout << "Matricula: ";
    cin >> medico.matricula;
    cout << "Que dias atiende?" << endl;
    for (i = 0; i < 7; i++) {
        cout << semana[i] << ": ";
        cin >> medico.atencion[i];
    }
    cout << "Ingrese hora de inicio de atencion: ";
    cin >> medico.rangoHor[0];
    cout << "Ingrese hora de fin de atencion: ";
    cin >> medico.rangoHor[1];
    cout << "Tiempo de consulta: ";
    cin >> medico.tiempoCon;

    cout << "Actualizando archivo de medicos y volviendo al menu de altas." << endl;

    fseek(medicos, 0, SEEK_END);
    fwrite(&medico, sizeof(medico), 1, medicos);
}

void mostrarActualizaciones(Nodo<Registro> *&reg) {
    int i, j, idMedico, idTurno;
    char nuevoStatus;
    Nodo<Registro> *medico = NULL;
    Nodo<Turno> *turno = NULL;

    cout << "ID del medico: ";
    cin >> idMedico;

    medico = buscar(reg, idMedico, criterioMedico);

    if (medico == NULL) {
        cout << "No se encontro el registro del medico" << endl;

        return;
    }

    cout << "ID del turno: ";
    cin >> idTurno;

    for (i = 0; i < 12 && turno != NULL; i++) {
        for (j = 0; j < 31 && turno != NULL; j++) {
            turno = buscar(medico->info.turnos[i][j], idTurno, criterioID);
        }
    }

    if (turno == NULL) {
        cout << "No se encontro el turno" << endl;

        return;
    }

    cout << "Ingrese el nuevo status: ";
    cin >> nuevoStatus;
    cout << "Actualizando status del turno y volviendo al menu principal" << endl;

    turno->info.status = nuevoStatus;
}

void mostrarListados(Nodo<Registro> *&reg) {
        
    bool salir = false;
    int opcion;

    while (!salir) {
        cout << "\033[2J\033[1;1H"; // idea de facu semmartin
        cout << "Menu de listados" << endl;
        cout << "1. Turnos pendientes" << endl;
        cout << "2. Cantidad de atenciones efectivas" << endl;
        cout << "3. Cancelaciones" << endl;
        cout << "0. Salir" << endl;

        cout << "Selecione una opcion: " << endl;
        cin >> opcion;

        if (opcion == 1) {
            turnosPendientes(mes, idmedico);
        }
        else if (opcion == 2) {

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

void turnospendientes(Nodo<Registro> *&reg){
    int mes, idmedico;
    cout << "Ingrese un mes" << endl;
    cin >> mes;
    cout << "ingrese el id del medico" << endl;
    
}
