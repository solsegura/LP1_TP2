#include "Aviones.h"
#include "Pasajeros.h"
#include "Aeropuertos.h"
#include "Vuelos.h"
#include "Valijas.h"
#include "cFecha.h"

cPasajero::cPasajero(string dni, string nombre, string fecha, int nvuelo, int asiento, int cant_valijas)
{
	this->DNI = dni;
	this->Nombre = nombre;
	this->Fecha = fecha;
	this->Nvuelo = nvuelo;
	this->Asiento = asiento;
	this->ListaValijas = new cListaEquipaje(cant_valijas);
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

int cPasajero::getNVuelo()
{
	return this->Nvuelo;
}

string cPasajero::getDNI()
{
	return this->DNI;
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

void cListaPasajeros::ModificarPasajero(cPasajero* pasajero1, cPasajero* pasajero2) //cambiar de asiento
{
	int aux = pasajero1->Asiento;
	pasajero1->Asiento = pasajero2->Asiento;
	pasajero2->Asiento = aux;
}

void cListaPasajeros::EliminarPasajero(cPasajero* pasajero)
{
}

int cListaPasajeros::Buscar(cPasajero* pasajero)
{
	for (int i = 0; i < this->cant_act; i++) {
		if (this->Vector_Pasajeros[i] == pasajero) {
			return i;				//si encuentro al pasajero en la lista, retorno la posicion
		}
	}
	return -1;//si no encuentro, retorna -1
}

int cListaPasajeros:: BuscarDNI(string dni) {
	for (int i = 0; i < this->cant_act; i++) {
		if (this->Vector_Pasajeros[i]->getDNI() == dni) {
			return i;				//si encuentro al pasajero en la lista, retorno la posicion
		}
	}
	return -1;//si no encuentro, retorna -1
}

cPasajero* cListaPasajeros::operator[](int indice)
{
	return this->Vector_Pasajeros[indice];
}

cListaPasajeros* cListaPasajeros::FiltrarLista(int vuelo)
{
	cListaPasajeros* filtro = new cListaPasajeros(this->cant_act); //filtro es la lista nueva 
	for (int i = 0; i < this->cant_act; i++)
		if (this->Vector_Pasajeros[i]->getNVuelo() == vuelo)
			filtro->AgregarPasajero(Vector_Pasajeros[i]); //agregar a filtro cada pasajero que tenga el vuelo = vuelo
	return filtro;
}

/*cListaPasajeros* cListaPasajeros::FiltrarDia(string dia)
{
	cListaPasajeros* filtroDia = new cListaPasajeros(this->cant_act); //lista filtrodia tam. cant act
	for (int i = 0; i < this->cant_act; i++)
	{
		if (Vector_Pasajeros[i]->getFecha() == dia)
			filtroDia->AgregarPasajero(Vector_Pasajeros[i]);
	}
	return filtroDia;
}*/
