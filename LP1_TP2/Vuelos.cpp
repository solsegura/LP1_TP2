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

cVuelo::cVuelo(estado estadovuelo, cAvion* avion, cFecha* fechasalida, cFecha* fechallegada, string destino, part_arribo poa) : NumeroVuelo(ContVuelo++) //inicializo const con el valor de static
{
	this->EstadoVuelo = estadovuelo;
	this->Avion = avion;
	this->FechaHora_Salida = fechasalida;
	this->FechaHora_Llegada = fechallegada;
	this->Destino = destino;
	this->PoA = poa;
	this->Pasajeros = new cListaPasajeros(this->Avion->getCantPasajerosMax());  //creamos la lista de pasajeros del vuelo en base a la capacidad maxima del avion
}

cVuelo::~cVuelo()
{
	delete this->Pasajeros;
	ContVuelo--;
}

int cVuelo::ContVuelo = 0;

cPasajero* cVuelo::DatosPasajero(string DNI)
{
	int indx = this->Pasajeros->BuscarDNI(DNI);
	cPasajero* aux = (*(this->Pasajeros))[indx];
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

void cVuelo::Pedir_Permiso(cAeropuerto* aeropuerto)
{
	if (this->PoA == partida)
		Avion->PedirPermiso(true, aeropuerto);
	else
		Avion->PedirPermiso(false, aeropuerto);
}

void cVuelo::SetearAvion()
{
	int peso = 0;
	peso+=this->Pasajeros->getCant()*75; //sumamos el peso de los pasajeros tomando 75kg como el peso promedio de una persona
	for (int i = 0; i < this->Pasajeros->getCant(); i++) {  //recorro la lista de pasajeros y por cada uno entro a su lista de equipaje y sumo el peso de cada valija
		cListaEquipaje* aux = (*(this->Pasajeros))[i]->getListavalijas();
		peso += aux->SumarPeso();
	}
	this->Avion->setPesoActual(peso);
	this->Avion->setCantDePasajeros(this->Pasajeros->getCant());

}

void cVuelo::SetEstado(estado Estado)
{
	this->EstadoVuelo = Estado;
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

void cVuelo::SetListaPasajeros(cListaPasajeros* lista)
{
	this->Pasajeros = lista;
}

int cVuelo::getNumeroDeVuelo()
{
	return this->NumeroVuelo; 
}

string cVuelo::to_String()
{
	stringstream ss;
	ss << endl <<"---------- NUMERO DE VUELO:  " <<to_string(this->NumeroVuelo) << " -----------" << endl;
	if (this->EstadoVuelo == on_time)
		ss << "Estado del vuelo: On time" << endl;
	if (this->EstadoVuelo == delayed)
		ss << "Estado del vuelo: Delayed" << endl;
	ss << "Avion: "<<this->Avion->getID() << endl;
	ss << "Fecha de salida: " << (*(this->FechaHora_Salida));  //uso la sobrecarga de fecha
	ss << "Fecha de llegada: " << (*(this->FechaHora_Llegada));
	ss << "Destino: " << this->Destino << endl << endl;
	ss << "  PASAJEROS DEL VUELO "<<to_string(this->NumeroVuelo)<< endl << endl;
	ss << (*(this->Pasajeros));  

	return ss.str();
}




ostream& operator<<(ostream& out, cVuelo& vuelo)
{
	out << vuelo.to_String();
	return out;
}
