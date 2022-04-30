#include "Aviones.h"
#include "Pasajeros.h"
#include "Aeropuertos.h"
#include "Vuelos.h"
#include "Valijas.h"
#include "cFecha.h"
#include "cListaPasajero.h"


cListaPasajeros::cListaPasajeros(int T)
{
	this->tam = T;
	this->cant_act = 0;
	this->Vector_Pasajeros = new cPasajero * [T];
	for (int i = 0; i < T; i++)
		this->Vector_Pasajeros[i] = NULL;

}

cListaPasajeros::~cListaPasajeros()
{
	for (int i = 0; i < this->tam; i++)
		this->Vector_Pasajeros = NULL;
	delete[] this->Vector_Pasajeros;
}


void cListaPasajeros::ModificarPasajero(cPasajero* pasajero1, cPasajero* pasajero2) //cambiar de asiento
{
	int aux = pasajero1->Asiento;
	pasajero1->Asiento = pasajero2->Asiento;
	pasajero2->Asiento = aux;
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

int cListaPasajeros::BuscarDNI(string dni) {
	for (int i = 0; i < this->cant_act; i++) {
		if (this->Vector_Pasajeros[i]->getDNI() == dni) {
			return i;				//si encuentro al pasajero en la lista, retorno la posicion
		}
	}
	return -1;//si no encuentro, retorna -1
}

unsigned int cListaPasajeros::getCant()
{
	return this->cant_act;
}

cPasajero* cListaPasajeros::operator[](int indice)
{
	return this->Vector_Pasajeros[indice];
}

string cListaPasajeros::to_String()
{
	stringstream ss;
	ss << "Cantidad de pasajeros: " << to_string(this->cant_act) << endl << endl;
	for (int i = 0; i < this->cant_act; i++) {
		int aux = i + 1;
		ss << "___________" << endl << "Pasajero nro " << to_string(aux) << ": " << endl;
		ss << this->Vector_Pasajeros[i]->to_String() << endl;
	}
	return ss.str();
}

cListaPasajeros* cListaPasajeros::FiltrarLista(int vuelo)
{
	cListaPasajeros* filtro = new cListaPasajeros(this->cant_act); //filtro es la lista nueva 
	for (int i = 0; i < this->cant_act; i++)
		if (this->Vector_Pasajeros[i]->getNVuelo() == vuelo)
			filtro->AgregarPasajero(Vector_Pasajeros[i]); //agregar a filtro cada pasajero que tenga el vuelo = vuelo
	return filtro;
}


void cListaPasajeros::AgregarPasajero(cPasajero* pasajero)
{
	if (this->cant_act < this->tam)  //me fijo que haya espacion en la lista
	{
		if (this->Buscar(pasajero) == -1) {  //me fijo que el pasajero no este en la lista
		
			this->Vector_Pasajeros[cant_act] = pasajero;
			cant_act++;
		}
	}
}

//void cListaPasajeros::AgregarPasajero(cPasajero* pasajero)
//{
//	for (unsigned int i = 0; i < this->tam; i++) {
//		if (this->Vector_Pasajeros[i] == NULL) {
//			this->Vector_Pasajeros[i] = pasajero;
//			cant_act++;
//			return;
//		}
//	}
//
//}

void cListaPasajeros::EliminarPasajero(cPasajero* pasajero)
{
	int aux = this->Buscar(pasajero);
	if (aux != -1) // si encuentro al pasajero
	{
		this->Vector_Pasajeros[aux] = this->Vector_Pasajeros[this->cant_act - 1];
		this->Vector_Pasajeros[this->cant_act - 1] = NULL;

	}


}


ostream& operator<<(ostream& out, cListaPasajeros& lista_pasajeros)
{
	out << lista_pasajeros.to_String();
	return out;
}
