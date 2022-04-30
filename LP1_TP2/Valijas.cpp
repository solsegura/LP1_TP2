#include "Aviones.h"
#include "Pasajeros.h"
#include "Aeropuertos.h"
#include "Vuelos.h"
#include "Valijas.h"
#include "cFecha.h"
#include "cListaPasajero.h"
#include "cListaEquipaje.h"
#include "cListaAviones.h"
#include "cListaVuelos.h"


cEquipaje::cEquipaje(string desc, int peso)
{
	this->Descripcion = desc;
	this->Peso = peso;

}

cEquipaje::~cEquipaje()
{
}

int cEquipaje::GetPeso()
{
	return this->Peso;
}

string cEquipaje::to_String()
{
	stringstream ss;
	ss << endl << "  Descripcion: " << this->Descripcion << endl;
	ss << "  Peso: " << to_string(this->Peso)<< "kg." << endl;
	return ss.str(); //.str convierte a string el ss
}


ostream& operator<<(ostream& out, cEquipaje& equipaje)
{
	out << equipaje.to_String();
	return out;
}
