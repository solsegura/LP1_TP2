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
	void AgregarEquipaje(cEquipaje* valija_nueva);
};

class cListaPasajeros {
	cPasajero** Vector_Pasajeros;
	unsigned int tam, cant_act;

public:
	cListaPasajeros(int T);
	~cListaPasajeros();
	void AgregarPasajero(cPasajero* pasajero);
	void QuitarPasajero(cPasajero* pasajero);
	void EliminarPasajero(cPasajero* pasajero);
	int Buscar(cPasajero* pasajero);
	cListaPasajeros FiltrarLista(string vuelo);  //filtrar la lista entera de pasajeros por numero de vuelo
};