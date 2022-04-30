#include "Aviones.h"
#include "Pasajeros.h"
#include "Aeropuertos.h"
#include "Vuelos.h"
#include "Valijas.h"
#include "cFecha.h"
#include "cListaPasajero.h"
#include "cListaEquipaje.h"
#include "cListaAviones.h"



cAvion::cAvion(string id, int cantmax)
{
	this->ID = id;
	this->CantPasajerosMax = cantmax;
	this->CantPasajerosAct = 0;
	this->PesoAct=0;
	this->PesoMax = this->CantPasajerosMax * 75 + this->CantPasajerosMax * 25 + 4 * 75; //calculamos el pesomax del avion sumando el peso promedio de las personas y el maximo peso posible del equipaje
	this->Permiso = false;
	this->Estado = estadoAvion::en_tierra;
}

cAvion::~cAvion()
{
}

void cAvion::Despegar()
{
	if (this->Permiso == true) {
		try {
			if (this->ChequearCapacidadMaxima() && this->ChequearCargaMaxima()) {  //hacemos los chequeos necesarios
				this->Estado = volando;  //cambiamos el estado de "en tierra" a "volando" porque ahora el avion despego
				this->Permiso = false;   //dejamos permiso en false
				cout << "el avion " << this->ID << " despego " << endl;
			}
		}
		catch (exception* e) {
			cout << e->what() << endl;
			cout << "Tiene permiso de despegar pero el avion se encuentra sobrepasado de peso o de pasajeros" << endl;
		}
	}
	else
		cout << "No tiene permiso para despegar " << endl;
}

void cAvion::Aterrizar()
{
	if (this->Permiso == true) {
		this->Estado = en_tierra;
		this->Permiso = false;
		cout << "el avion " << this->ID << " aterrizo " << endl;
	}
	else
		cout<<"No tiene permiso de aterrizar"<<endl;
}

void cAvion::PedirPermiso(bool PoA, cAeropuerto* aeropuerto)  //aeropuerto SIEMPRE va a ser aeroparque
{
	if (PoA)
		aeropuerto->DarPermisoDespegue(this);
	else {
		try {
			aeropuerto->DarPermisoAterrizar(this);
		}
		catch (exception* e) {
			cout << e->what() << endl;
		}
	}
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
		throw new exception ("SE_SUPERO_LA_CARGA_MAX"); 
}

bool cAvion::ChequearCapacidadMaxima()
{
	if (this->CantPasajerosAct <= CantPasajerosMax)
		return true;
	else
		return false;
}

void cAvion::setPesoActual(int peso)
{
	this->PesoAct = peso;
}

void cAvion::setCantDePasajeros(int cant)
{
	this->CantPasajerosAct = cant;
}

int cAvion::getCantPasajerosMax()
{
	return this->CantPasajerosMax;
}

string cAvion::getID()
{
	return this->ID;
}

string cAvion::to_String()
{
	stringstream ss;
	ss << "ID: " << this->ID << endl;
	ss << "Cantidad maxima de pasajeros: " << to_string(this->CantPasajerosMax) << endl << "Cantidad actual: "  << to_string(this->CantPasajerosAct) << endl;
	ss << "Carga maxima: " << to_string(this->PesoMax) << endl << "Carga actual: " << to_string(this->PesoAct) << endl;
	if (this->Permiso)
		ss << "Permiso: Si." << endl;
	else
		ss << "Permiso: No." << endl;
	if (this->Estado == volando)
		ss << "Estado: Volando." << endl;
	else if (this->Estado == en_tierra)
		ss << "Estado: En tierra." << endl;
	return ss.str();
}


ostream& operator<<(ostream& out, cAvion& avion)
{
	out << avion.to_String();
	return out;
}
