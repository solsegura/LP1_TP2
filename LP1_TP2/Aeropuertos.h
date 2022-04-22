#pragma once
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class cVuelo;
class cAvion;
class cPasajero;
class cListaAviones;
class cListaVuelos;

class cAeropuerto {
	string ID;
	int Capacidad; //aviones
	cListaAviones* Lista_aviones;
	cListaVuelos* Lista_vuelos;
	cListaPasajeros* Lista_pasajeros;
public:
	cAeropuerto(string id, int capacidad, int cant_vuelos_max, cListaPasajeros* lista_pasajeros);
	~cAeropuerto();

	/// <summary>
	/// Los aviones se agregan a la lista cuando aterrizan y se quitan
	/// cuando despegan.El Aeropuerto puede DarPermiso que otorgue o niegue el
	/// permiso de aterrizar según la disponibilidad del hangar.
	/// </summary>
	/// <param name="avion"></param>
	void DarPermisoDespegue(cAvion* avion);  //podria hacerlo en un solo metodo DarPermiso chequeando el estado del avion
	void DarPermisoAterrizar(cAvion* avion);
	cListaPasajeros* FiltrarDia(cFecha* dia);
	int getCapacidad();

};