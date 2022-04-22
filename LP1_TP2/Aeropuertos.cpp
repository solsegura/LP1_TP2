#include "Aviones.h"
#include "Pasajeros.h"
#include "Aeropuertos.h"
#include "Vuelos.h"

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
}

void cAeropuerto::DarPermisoDespegue(cAvion* avion)
{
		cAvion* aux = this->Lista_aviones->QuitarAvion(avion); //chequeamos que el avion este en el aeropuerto
		if (aux != NULL) {
			aux->RecibirPermiso(true);  //asignamos true en el permiso de ese avion
			this->Lista_aviones->EliminarAvion(aux); //lo sacamos de la lista porque va a despegar
		}
		else
			printf("\nEl avion no se encuentra en este aeropuerto");
}

void cAeropuerto::DarPermisoAterrizar(cAvion* avion)
{
	if (this->Lista_aviones->getCant() < this->Capacidad) { //reviso que haya lugar en el hangar
		avion->RecibirPermiso(true);  //asignamos true en el permiso de ese avion
		this->Lista_aviones->AgregarAvion(avion);
	}
}
cListaPasajeros* cAeropuerto::FiltrarDia(cFecha* dia)
{
	cListaPasajeros* filtroDia = new cListaPasajeros(this->Lista_pasajeros->getCant()); //lista filtrodia tam. cant act

	for (int i = 0; i < this->Lista_vuelos->cant_act; i++) //borrar gets!!!!!!!
	{
		if (this->Lista_vuelos->VectorVuelos[i]->PoA == arribo)
		{
			if (this->Lista_vuelos->VectorVuelos[i]->FechaHora_Llegada == dia)
				for (int j = 0; j < this->Lista_vuelos->VectorVuelos[i]->Pasajeros->getCant(); j++)
					filtroDia->AgregarPasajero(this->Lista_vuelos->VectorVuelos[i]->Pasajeros->Vector_Pasajeros[j]); //VER CLASE FRIENDDDDDD
		}
		else {
			if (this->Lista_vuelos->VectorVuelos[i]->FechaHora_Salida == dia)
				for (int j = 0; j < this->Lista_vuelos->VectorVuelos[i]->Pasajeros->getCant(); j++)
					filtroDia->AgregarPasajero(this->Lista_vuelos->VectorVuelos[i]->Pasajeros->Vector_Pasajeros[j]);
		}
	}
	return filtroDia;
}
