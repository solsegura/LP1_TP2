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



cListaVuelos::cListaVuelos(int T)
{
	this->tam = T;
	this->cant_act = 0;
	this->VectorVuelos = new cVuelo * [T]; //DELETE
	for (int i = 0; i < T; i++)
		this->VectorVuelos[i] = NULL;
}

cListaVuelos::~cListaVuelos()
{
	for (int i = 0; i < this->tam; i++)
		this->VectorVuelos[i] = NULL;
	delete[] this->VectorVuelos;
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

cVuelo* cListaVuelos::operator[](int indice)
{
	return this->VectorVuelos[indice];
}

string cListaVuelos::to_String()
{
	stringstream ss;
	ss << endl << "Cantidad de vuelos: " << this->cant_act << endl;
	for (int i = 0; i < this->cant_act; i++)
		ss << this->VectorVuelos[i]->to_String() << endl;
	return ss.str();
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


ostream& operator<<(ostream& out, cListaVuelos& vuelo)
{
	out << vuelo.to_String();
	return out;
}
