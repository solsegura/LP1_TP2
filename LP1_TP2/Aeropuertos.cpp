#include "Aviones.h"
#include "Pasajeros.h"
#include "Aeropuertos.h"
#include "Vuelos.h"

void cAeropuerto::DarPermisoDespegue(cAvion* avion)
{
		cAvion* aux = this->Lista_aviones->QuitarAvion(avion); //chequeamos que el avion este en el aeropuerto
		if (aux != NULL) {
			aux->RecibirPermiso(true);  //asignamos true en el permiso de ese avion
			this->Lista_aviones->EliminarAvion(aux); //lo sacamos de la lista porque va a despegar
		}
		else
			printf("\nEl avion no se encuentra en este aeropuerto");
}

void cAeropuerto::DarPermisoAterrizar(cAvion* avion)
{
	if (this->Lista_aviones->getCant() < this->Lista_aviones->getTam()) { //reviso que haya lugar en el hangar
		avion->RecibirPermiso(true);  //asignamos true en el permiso de ese avion
		this->Lista_aviones->AgregarAvion(avion);
	}
}