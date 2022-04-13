#pragma once
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class cVuelo;
class cAvion;
class cAeropuerto;
class cListaEquipaje;
class cEquipaje;

/*Un Pasajero que tiene un DNI, su nombre, la fecha, número de vuelo, asiento, lista
de valijas que transporta (y el peso de cada una). Además, el método
AgregarEquipaje que chequee que el equipaje total no supere los 25 kg por persona.*/

class cPasajero {
	string DNI;
	string Nombre;
	string Fecha;
	string Nvuelo;
	int Asiento;
	cListaEquipaje* ListaValijas;

public:
	cPasajero(string dni, string nombre, string fecha, string nvuelo, int asiento, cListaEquipaje* listavalijas);
	~cPasajero();
	/// <summary>
	/// Llama  al metodo agregar valija de la clase cListaEquipaje para agregar una valija a la losta del pasajero
	/// </summary>
	/// <param name="valija_nueva"></param>
	void AgregarEquipaje(cEquipaje* valija_nueva);
	cEquipaje* EliminarEquipaje(cEquipaje* valija);
	string getNVuelo();
};

class cListaPasajeros {
	cPasajero** Vector_Pasajeros;  //cada vez que ingreso un pasajero deberia agregarlo en la mega lista de pasajeros ponele creo
	unsigned int tam, cant_act;

public:
	cListaPasajeros(int T);
	~cListaPasajeros();
	void AgregarPasajero(cPasajero* pasajero);
	void QuitarPasajero(cPasajero* pasajero);
	void EliminarPasajero(cPasajero* pasajero);
	/// <summary>
	/// Retorna la posicion en la que esta el pasajero en la lista o -1 si no esta
	/// </summary>
	/// <param name="pasajero"></param>
	/// <returns></returns>
	int Buscar(cPasajero* pasajero);
	/// <summary>
	/// Devuelve una lista de pasajeros filtrada por numero de vuelo
	/// </summary>
	/// <param name="vuelo"></param>
	/// <returns></returns>
	cListaPasajeros* FiltrarLista(string vuelo);  
};