#pragma once
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <sstream>

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
	cAeropuerto(string id, int capacidad, int cant_vuelos_max, cListaPasajeros* lista_pasajeros, cListaAviones* lista_aviones, cListaVuelos* lista_vuelos);
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
	/// <summary>
	/// agrega el pasajero que recibe por parametro a la lista de pasajeros
	/// </summary>
	/// <param name="pasajero_nuevo"></param>
	void AgregarPasajero(cPasajero* pasajero_nuevo);
	/// <summary>
	/// agrega el avion que recibe por parametro a la lista de aviones
	/// </summary>
	/// <param name="avion_nuevo"></param>
	void AgregarAvion(cAvion* avion_nuevo);  //la usamos para agregar aviones que creamos en el main, despues se eliminan al despegar
	/// <summary>
	/// Agrega el vuelo que recibe por parametro a la lista de vuelos
	/// </summary>
	/// <param name="vuelo_nuevo"></param>
	void AgregarVuelo(cVuelo* vuelo_nuevo);
	/// <summary>
	/// devuelve la lista de vuelos
	/// </summary>
	/// <returns></returns>
	cListaVuelos* GetListaVuelos();
	/// <summary>
	/// concatena los atributos de la clase en un string
	/// </summary>
	/// <returns></returns>
	string to_String();
	/// <summary>
	/// Devuelve el porcentaje de vuelos que despegaron/aterrizaron en horario
	/// </summary>
	/// <returns></returns>
	float PorcentajeEnHorario();
	friend ostream& operator<<(ostream& out, cAeropuerto& aeropuerto);
};