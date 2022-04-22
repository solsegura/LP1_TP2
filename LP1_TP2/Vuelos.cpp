#include "Aviones.h"
#include "Pasajeros.h"
#include "Aeropuertos.h"
#include "Vuelos.h"
#include "Valijas.h"
#include "cFecha.h"

cVuelo::cVuelo(cAvion* avion, cFecha* fechasalida, cFecha* fechallegada, string destino, part_arribo poa): NumeroVuelo(ContVuelo++) //inicializo const con el valor de static
{
	this->Pasajeros = new cListaPasajeros(this->Avion->getCantPasajerosMax());  //creamos la lista de pasajeros del vuelo en base a la capacidad maxima del avion
	ContVuelo++;
}

cVuelo::~cVuelo()
{
	ContVuelo--;
}

int cVuelo::ContVuelo = 0;

cPasajero* cVuelo::DatosPasajero(string DNI)
{
	int indx = this->Pasajeros->BuscarDNI(DNI);
	cPasajero* aux = this->Pasajeros->getPasajero(indx);
	return aux;
}

void cVuelo::AgregarPasajero(cPasajero* pasajero)
{
	this->Pasajeros->AgregarPasajero(pasajero);
}

void cVuelo::CambiarPasajero(cPasajero* pasajero1, cPasajero* pasajero2) 
{
	this->Pasajeros->ModificarPasajero(pasajero2, pasajero1);
}

void cVuelo::EliminarPasajero(cPasajero* pasajero)
{
	this->Pasajeros->EliminarPasajero(pasajero);
}

void cVuelo::SetearAvion()
{
	int peso = 0;
	peso+=this->Pasajeros->getCant()*75; //sumamos el peso de los pasajeros tomando 75kg como el peso promedio de una persona
	for (int i = 0; i < this->Pasajeros->getCant(); i++) {  //recorro la lista de pasajeros y por cada uno entro a su lista de equipaje y sumo el peso de cada valija
		cPasajero* aux = this->Pasajeros->getPasajero(i);
		cListaEquipaje* aux2 = aux->getListavalijas();
		peso += aux2->SumarPeso();
	}
	this->Avion->setPesoActual(peso);
	this->Avion->setCantDePasajeros(this->Pasajeros->getCant());

}

part_arribo cVuelo::getPoA()
{
	return part_arribo();
}

int cListaVuelos::getCantAct()
{
	return 0;
}
