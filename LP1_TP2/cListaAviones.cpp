#include "Aviones.h"
#include "Pasajeros.h"
#include "Aeropuertos.h"
#include "Vuelos.h"
#include "Valijas.h"
#include "cFecha.h"
#include "cListaPasajero.h"
#include "cListaEquipaje.h"
#include "cListaAviones.h"


cListaAviones::cListaAviones(int T)
{
	this->tam = T;
	this->cant_act = 0;
	this->VectorAviones = new cAvion * [T]; //DELETE
	for (int i = 0; i < T; i++)
		this->VectorAviones[i] = NULL;
}

cListaAviones::~cListaAviones()
{
	for (int i = 0; i < this->tam; i++)
		this->VectorAviones[i] = NULL;
	delete[] this->VectorAviones;
}


cAvion* cListaAviones::QuitarAvion(cAvion* avion)
{
	int idx = this->Buscar(avion);
	if (idx != -1)
		return this->VectorAviones[idx];

	return NULL;
}



int cListaAviones::getCant()
{
	return this->cant_act;
}

int cListaAviones::getTam()
{
	return this->tam;
}

cAvion* cListaAviones::operator[](int indice)
{
	return this->VectorAviones[indice];
}

string cListaAviones::to_String()
{
	stringstream ss;
	ss << "Cantidad de aviones: " << to_string(this->cant_act) << endl;
	for (int i = 0; i < this->cant_act; i++) {
		ss << "Avion nro. " << to_string(i) << " : " << endl;
		ss << this->VectorAviones[i]->to_String() << endl;
	}
	return ss.str();
}



void cListaAviones::EliminarAvion(cAvion* avion)
{
	for (int i = 0; i < this->cant_act; i++) {
		if (this->VectorAviones[i] == avion)
		{
			this->VectorAviones[i] = this->VectorAviones[this->cant_act - 1]; //reeemplazo el que voy a borrar con el ultimo de la lista
			this->VectorAviones[this->cant_act - 1] = NULL; //borro el ultimo de la lista porque ya lo deje en otro lado

		}
	}
}



void cListaAviones::AgregarAvion(cAvion* avion)
{

	if (this->cant_act < this->tam)
	{
		this->VectorAviones[cant_act] = avion;
		cant_act++;
	}
}
int cListaAviones::Buscar(cAvion* avion)
{
	for (int i = 0; i < this->cant_act; i++) {
		if (this->VectorAviones[i] == avion) {
			return i; // Retorno la posicion en caso de encontrar el avion
		}
	}
	return -1;//Retorno -1 en caso de no encontrarlo


}

ostream& operator<<(ostream& out, cListaAviones& lista_aviones)
{
	out << lista_aviones.to_String();
	return out;
}
