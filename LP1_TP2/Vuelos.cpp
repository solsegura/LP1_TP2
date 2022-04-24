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
	return this->PoA;
}

cFecha* cVuelo::getFecha_Llegada()
{
	return this->FechaHora_Llegada;
}

cFecha* cVuelo::getFecha_Salida()
{
	return this->FechaHora_Salida;
}

int cVuelo::getNumeroDeVuelo()
{
	return this->NumeroVuelo; //const static, quilombo
}




cListaVuelos::cListaVuelos(int T)
{
	this->tam = T;
	this->cant_act = 0;
	this->VectorVuelos = new cVuelo* [T]; //DELETE
	for (int i = 0; i < T; i++)
		this->VectorVuelos[i] = NULL;
}




int cListaVuelos::getCantAct()
{
	return 0;
}

int cListaVuelos::Buscar(cVuelo* vuelo)
{
	for (int i = 0; i < this->cant_act; i++) {
		if (this->VectorVuelos[i] == vuelo) {
			return i; // Retorno la posicion en caso de encontrar el avion
		}
	}
	return -1;//Retorno -1 en caso de no encontrarlo
}

void cListaVuelos::AgregarVuelo(cVuelo* vuelo)
{
	if (this->cant_act < this->tam)
	{
		this->VectorVuelos[cant_act] = vuelo;
		cant_act++;
	}

}

/*void cListaVuelos::QuitarVuelo(cVuelo* vuelo) // ver si esta okey
{ 
    int idx = this->Buscar(vuelo);
	*this = VectorVuelos [idx]
}

*/
void cListaVuelos::EliminarVuelo(cVuelo* vuelo)
{
	for (int i = 0; i < this->cant_act; i++) {
		if (this->VectorVuelos[i] == vuelo)
		{
			this->VectorVuelos[i] = this->VectorVuelos[this->cant_act - 1]; 
			this->VectorVuelos[this->cant_act - 1] = NULL; 

		}
	}


}
