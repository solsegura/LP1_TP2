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
class cListaPasajeros;
class cFecha;

class cAeropuerto {
	string ID;
	int Capacidad; //De aviones
	cListaAviones* Lista_aviones;
	cListaVuelos* Lista_vuelos;
	cListaPasajeros* Lista_pasajeros;  //esta lista contiene a todos los pasajeros, tanto los que vienen como los que se van
public:
	/// <summary>
	/// Constructor de la clase cAeropuerto
	/// </summary>
	/// <param name="id"></param>
	/// <param name="capacidad"></param>
	/// <param name="cant_vuelos_max"></param>
	/// <param name="lista_pasajeros"></param>
	cAeropuerto(string id, int capacidad, int cant_vuelos_max, cListaPasajeros* lista_pasajeros);
	///Destructor de cAeropuerto
	~cAeropuerto();

	/// <summary>
	/// Da permiso de despegar al avion que se pasa por parametro
	/// </summary>
	/// <param name="avion"></param>
	void DarPermisoDespegue(cAvion* avion); 
	/// <summary>
	/// Da permiso de aterrizar al avion si hay lugar en el aeropuerto
	/// </summary>
	/// <param name="avion"></param>
	void DarPermisoAterrizar(cAvion* avion);
	/// <summary>
	/// Metodo que cuenta la cantidad de pasajeros que viajaron en un dia
	/// </summary>
	/// <param name="dia"></param>
	/// <returns></returns>
	int FiltrarDia(cFecha* dia);
	/// <summary>
	///  Cuenta la cantidad de vuelos que despegaron o aterrizaron en un dia (se pasa el dia por parametro)
	/// </summary>
	/// <param name="dia"></param>
	/// <returns></returns>
	int CantVuelosDia(cFecha* dia);
	/// <summary>
	/// Devuelve la cantidad maxima de aviones que puede haber en el aeropuerto
	/// </summary>
	/// <returns></returns>
	int getCapacidad();

	void AgregarPasajero(cPasajero* pasajero_nuevo);
	void AgregarAvion(cAvion* avion_nuevo);  //la usamos para agregar aviones que creamos en el main, despues se eliminan al despegar
	void AgregarVuelo(cVuelo* vuelo_nuevo);
	cListaVuelos* GetListaVuelos();
};