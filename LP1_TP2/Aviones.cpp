#include "Aviones.h"
#include "Pasajeros.h"
#include "Aeropuertos.h"
#include "Vuelos.h"
/* peso máximo, para calcular el peso del avión se
considera la suma del peso humano y el peso total del equipaje, siendo el
peso humano el peso de los pasajeros. Un pasajero tiene un peso promedio
de 75kg (se considera lo mismo para todos los pasajeros) y el peso total del
equipaje incluye todos los equipajes de todos los pasajeros. En este cálculo
hay que considerar el peso de los 4 integrantes de la tripulación (no llevan
equipaje).
*/

cAvion::cAvion(int id, int cantmax)
{
	this->ID = id;
	this->CantPasajerosMax = cantmax;
	this->CantPasajerosAct = 0;
	this->PesoAct=0;
	this->PesoMax = this->CantPasajerosMax * 75 + this->CantPasajerosMax * 25 + 4 * 75; //calculamos el pesomax del avion sumando el peso promedio de las personas y el maximo peso posible del equipaje
	this->Permiso = false;
	this->Estado = en_tierra;
}

cAvion::~cAvion()
{
}

void cAvion::Despegar()
{
	if (this->Permiso == true){
		if (this->ChequearCapacidadMaxima() && this->ChequearCargaMaxima()) {  //hacemos los chequeos necesarios
			this->Estado = volando;  //cambiamos el estado de "en tierra" a "volando" porque ahora el avion despego
			this->Permiso = false;   //dejamos permiso en false
		}
		else
			printf("\nTiene permiso de despegar pero el avion se encuentra sobrepasado de peso o de pasajeros");
	}
	else
		printf("\nNo tiene permiso para despegar ");
}

void cAvion::Aterrizar()
{
	if (this->Permiso == true) {
		this->Estado = en_tierra;
		this->Permiso = false;
	}
	else
		printf("\nNo tiene permiso de aterrizar");
}

void cAvion::RecibirPermiso(bool permiso)
{
	if (this->Estado == en_tierra) {  //si el avion se encuentra en tierra le damos permiso de despegar y lo hacemos despegar
		this->Permiso = permiso;
		this->Despegar();
	}
	if (this->Estado == volando) { //de la misma forma, si esta volando lo hacemos aterrizar
		this->Permiso = permiso;
		this->Aterrizar();
	}
}

bool cAvion::ChequearCargaMaxima()
{
	if (this->PesoAct <= this->PesoMax)
		return true;
	else
		return false;
}

bool cAvion::ChequearCapacidadMaxima()
{
	if (this->CantPasajerosAct <= CantPasajerosMax)
		return true;
	else
		return false;
}

cAvion* cListaAviones::QuitarAvion(cAvion* avion)
{
	int idx = this->Buscar(avion);
	if(idx!=-1)
		return this->VectorAviones[idx];

	return NULL;
}
