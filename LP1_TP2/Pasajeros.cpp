#include "Aviones.h"
#include "Pasajeros.h"
#include "Aeropuertos.h"
#include "Vuelos.h"
#include "Valijas.h"

cPasajero::cPasajero(string dni, string nombre, string fecha, string nvuelo, int asiento, cListaEquipaje* listavalijas)
{
	this->DNI = dni;
	this->Nombre = nombre;
	this->Fecha = fecha;
	this->Nvuelo = nvuelo;
	this->Asiento = asiento;
	this->ListaValijas = listavalijas;
}

cPasajero::~cPasajero()
{
}

void cPasajero::AgregarEquipaje(cEquipaje* valija_nueva)
{
	this->ListaValijas->AgregarValija(valija_nueva);
}

cEquipaje* cPasajero::EliminarEquipaje(cEquipaje* valija)
{
	cEquipaje* aux = this->ListaValijas->EliminarValija(valija);
	return aux;
}

string cPasajero::getNVuelo()
{
	return this->Nvuelo;
}

int cListaPasajeros::Buscar(cPasajero* pasajero)
{
	int indice = 0;
	for (int i = 0; i < this->cant_act; i++) {
		if (this->Vector_Pasajeros[i] == pasajero) {
			return i;				//si encuentro al pasajero en la lista, retorno la posicion
		}
	}
	return -1;//si no encuentro, retorna -1
}

cListaPasajeros* cListaPasajeros::FiltrarLista(string vuelo)
{
	cListaPasajeros* filtro = new cListaPasajeros(this->cant_act);
	for (int i = 0; i < this->cant_act; i++)
		if (this->Vector_Pasajeros[i]->getNVuelo() == vuelo)
			filtro->AgregarPasajero(Vector_Pasajeros[i]);
	return filtro;
}
