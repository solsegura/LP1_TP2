#include "Aviones.h"
#include "Pasajeros.h"
#include "Aeropuertos.h"
#include "Vuelos.h"
#include "Valijas.h"
#include "cFecha.h"

cAeropuerto::cAeropuerto(string id, int capacidad, int cant_vuelos_max, cListaPasajeros* lista_pasajeros)
{
	this->ID = id;
	this->Capacidad = capacidad;
	this->Lista_pasajeros = lista_pasajeros;
	this->Lista_aviones = new cListaAviones(capacidad);  //preguntar donde irian los deletes
	this->Lista_vuelos = new cListaVuelos(cant_vuelos_max);
}

cAeropuerto::~cAeropuerto()
{
	delete this->Lista_aviones;
	delete this->Lista_vuelos;
}

void cAeropuerto::DarPermisoDespegue(cAvion* avion)
{
		cAvion* aux = this->Lista_aviones->QuitarAvion(avion); //chequeamos que el avion este en el aeropuerto
		if (aux != NULL) {
			aux->RecibirPermiso(true);  //asignamos true en el permiso de ese avion
			this->Lista_aviones->EliminarAvion(aux); //lo sacamos de la lista porque va a despegar
		}
		else
			cout << "El avion no se encuentra en este aeropuerto" << endl;
}

void cAeropuerto::DarPermisoAterrizar(cAvion* avion)
{
	if (this->Lista_aviones->getCant() < this->Capacidad) { //reviso que haya lugar en el hangar
		avion->RecibirPermiso(true);  //asignamos true en el permiso de ese avion
		this->Lista_aviones->AgregarAvion(avion);  //agregamos el avion a la lista ya que aterrizo
	}
	else throw new exception("HANGAR_LLENO");
}


int cAeropuerto::FiltrarDia(cFecha* dia)
{
	cListaPasajeros* filtroDia = new cListaPasajeros(this->Lista_pasajeros->getCant()); //lista filtrodia tam. cant act

	for (int i = 0; i < this->Lista_vuelos->cant_act; i++) //borrar gets!!!!!!!
	{
		if (this->Lista_vuelos->VectorVuelos[i]->PoA == arribo)
		{
			if (this->Lista_vuelos->VectorVuelos[i]->FechaHora_Llegada == dia)
				for (int j = 0; j < this->Lista_vuelos->VectorVuelos[i]->Pasajeros->getCant(); j++)
					filtroDia->AgregarPasajero((*(this->Lista_vuelos->VectorVuelos[i]->Pasajeros))[j]); //VER CLASE FRIENDDDDDD
		}
		else {
			if (this->Lista_vuelos->VectorVuelos[i]->FechaHora_Salida == dia)
				for (int j = 0; j < this->Lista_vuelos->VectorVuelos[i]->Pasajeros->getCant(); j++)
					filtroDia->AgregarPasajero((*(this->Lista_vuelos->VectorVuelos[i]->Pasajeros))[j]); //usamos sobrecarga de [] para acceder a cada pasajero del vuelo
		}
	}
	return filtroDia->getCant();
}

int cAeropuerto::CantVuelosDia(cFecha* dia)
{
	cListaVuelos* filtroDia = new cListaVuelos(this->Lista_vuelos->cant_act);
	for (int i = 0; i < this->Lista_vuelos->cant_act; i++) //borrar gets!!!!!!!
	{
		if (this->Lista_vuelos->VectorVuelos[i]->PoA == arribo)
			if (this->Lista_vuelos->VectorVuelos[i]->FechaHora_Llegada == dia)
				filtroDia->AgregarVuelo(this->Lista_vuelos->VectorVuelos[i]);
		
		else if (this->Lista_vuelos->VectorVuelos[i]->FechaHora_Salida == dia)
				filtroDia->AgregarVuelo(this->Lista_vuelos->VectorVuelos[i]);
		
	}
	return filtroDia->cant_act;
}

int cAeropuerto::getCapacidad()
{
	return this->Capacidad;
}

void cAeropuerto::AgregarPasajero(cPasajero* pasajero_nuevo)
{
	this->Lista_pasajeros->AgregarPasajero(pasajero_nuevo);
}

void cAeropuerto::AgregarAvion(cAvion* avion_nuevo)
{
	this->Lista_aviones->AgregarAvion(avion_nuevo);
}

void cAeropuerto::AgregarVuelo(cVuelo* vuelo_nuevo)
{
	this->Lista_vuelos->AgregarVuelo(vuelo_nuevo);
}

cListaVuelos* cAeropuerto::GetListaVuelos()
{
	return this->Lista_vuelos;
}

string cAeropuerto::to_String()
{
	stringstream ss;
	ss << "ID: " << this->ID << endl;
	ss << "Capacidad: " << to_string(this->Capacidad) << endl;
	ss << "______VUELOS_____ " << endl;
	ss << this->Lista_vuelos << endl;
	ss << "______AVIONES_____ " << endl;
	ss << this->Lista_aviones << endl;

	return ss.str();
}

float cAeropuerto::PorcentajeEnHorario()
{
	float cont = 0;
	for (int i = 0; i < this->Lista_vuelos->cant_act; i++) {
		if ((*(this->Lista_vuelos))[i]->EstadoVuelo == on_time)
			cont++;
	}

	cont = cont * 100 /(float) this->Lista_vuelos->cant_act;
	return cont;
}

ostream& operator<<(ostream& out, cAeropuerto& aeropuerto)
{
	out << aeropuerto.to_String();
	return out;
}
