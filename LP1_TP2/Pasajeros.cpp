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

cPasajero::cPasajero(string dni, string nombre, cFecha* fecha, int nvuelo, int asiento, cListaEquipaje* lista_equipaje)
{
	this->DNI = dni;
	this->Nombre = nombre;
	this->Nvuelo = nvuelo;
	this->Asiento = asiento;
	this->ListaValijas = lista_equipaje;
	this->Fecha = fecha;
}


cPasajero::~cPasajero()
{

}

void cPasajero::AgregarEquipaje(cEquipaje* valija_nueva)
{
	this->ListaValijas->AgregarValija(valija_nueva);
}

void cPasajero::EliminarEquipaje(cEquipaje* valija)
{
	 this->ListaValijas->EliminarValija(valija);
	
}

int cPasajero::getNVuelo()
{
	return this->Nvuelo;
}

string cPasajero::getDNI()
{
	return this->DNI;
}

cFecha* cPasajero::getFecha()
{
	return this->Fecha;
}

cListaEquipaje* cPasajero::getListavalijas()
{
	return this->ListaValijas;
}



cPasajero cPasajero::operator+(cEquipaje& valija_nueva)
{
	this->AgregarEquipaje(&valija_nueva);
	return *this;
}

cPasajero cPasajero::operator-(cEquipaje& valija)
{
	this->EliminarEquipaje(&valija);
	return *this;
}

string cPasajero::to_String()
{
	stringstream ss;
	ss << "  Nombre: " << this->Nombre << endl;
	ss << "  DNI: " << this->DNI << endl;
	ss << "  Nacimiento: " << this->Fecha->getFecha();
	ss << "  Numero de vuelo: " << to_string(this->Nvuelo) << endl;
	ss << "  Asiento: " << to_string(this->Asiento) << endl;
	ss <<  (*(this->ListaValijas)) << endl;

	return ss.str();
}


ostream& operator<<(ostream& out, cPasajero& pasajero)
{
	out << pasajero.to_String();
	return out;
}
