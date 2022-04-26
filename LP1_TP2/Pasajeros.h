#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class cVuelo;
class cAvion;
class cAeropuerto;
class cListaEquipaje;
class cEquipaje;
class cFecha;

/*Un Pasajero que tiene un DNI, su nombre, la fecha, número de vuelo, asiento, lista
de valijas que transporta (y el peso de cada una). Además, el método
AgregarEquipaje que chequee que el equipaje total no supere los 25 kg por persona.*/

class cPasajero {
	friend int cAeropuerto::FiltrarDia(cFecha* dia);
	friend class cListaPasajeros;
	string DNI;
	string Nombre;
	cFecha* Fecha; //de nacimiento
	int Nvuelo;
	int Asiento;
	cListaEquipaje* ListaValijas;

public:
	cPasajero(string dni, string nombre, cFecha* fecha, int nvuelo, int asiento, int cant_valijas);
	~cPasajero();
	void AgregarEquipaje(cEquipaje* valija_nueva);// Llama  al metodo agregar valija de la clase cListaEquipaje para agregar una valija a la losta del pasajero
	cEquipaje* EliminarEquipaje(cEquipaje* valija);
	int getNVuelo();
	string getDNI();
	cFecha* getFecha();
	cListaEquipaje* getListavalijas();
	cPasajero operator+(cEquipaje& valija_nueva);
	cPasajero operator-(cEquipaje& valija);

};

class cListaPasajeros {
	friend int cAeropuerto::CantVuelosDia(cFecha* dia);
	friend int cAeropuerto::FiltrarDia(cFecha* dia); //BRUNOOOOOOOOOOOOO
	cPasajero** Vector_Pasajeros;  
	unsigned int tam, cant_act;


public:
	cListaPasajeros(int T); //tam max
	~cListaPasajeros();
	void AgregarPasajero(cPasajero* pasajero);
	void ModificarPasajero(cPasajero* pasajero1, cPasajero* pasajero2);/// Copia la nueva informacion del pasajero en el indice que le pasamos por parametro
	void EliminarPasajero(cPasajero* pasajero);
	int Buscar(cPasajero* pasajero);// Retorna la posicion en la que esta el pasajero en la lista o -1 si no esta
	cListaPasajeros* FiltrarLista(int vuelo);  /// Devuelve una lista de pasajeros filtrada por numero de vuelo
	int BuscarDNI(string dni);
	unsigned int getCant();
	cPasajero* operator[](int indice);
};