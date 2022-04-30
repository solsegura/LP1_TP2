#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <sstream>

using namespace std;

class cVuelo;
class cAvion;
class cAeropuerto;
class cListaEquipaje;
class cEquipaje;
class cFecha;
class cPasajero;



class cListaPasajeros {
	friend class cAeropuerto;
	cPasajero** Vector_Pasajeros;
	unsigned int tam, cant_act;


public:
	cListaPasajeros(int T); //tam max
	~cListaPasajeros();
	void AgregarPasajero(cPasajero* pasajero);
	/// <summary>
	/// Copia la nueva informacion del pasajero en el indice que le pasamos por parametro
	/// </summary>
	void ModificarPasajero(cPasajero* pasajero1, cPasajero* pasajero2);
	void EliminarPasajero(cPasajero* pasajero);
	/// <summary>
	/// Retorna la posicion en la que esta el pasajero en la lista o -1 si no esta
	/// </summary>
	/// <param name="pasajero1"></param>
	/// <param name="pasajero2"></param>
	int Buscar(cPasajero* pasajero);
	/// <summary>
	/// Devuelve una lista de pasajeros filtrada por numero de vuelo
	/// </summary>
	/// <param name="pasajero"></param>
	cListaPasajeros* FiltrarLista(int vuelo);
	int BuscarDNI(string dni);
	unsigned int getCant();
	cPasajero* operator[](int indice);  //sobrecarga de [] para cListaPasajero, devuelve el pasajero que esta en la posicion indice

	//metodos para imprimir
	string to_String();
	friend ostream& operator<<(ostream& out, cListaPasajeros& lista_pasajeros);
};