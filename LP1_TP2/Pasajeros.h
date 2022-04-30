#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <sstream>

//necesitamos declarados los metodos de cAeropuerto para hacerles friend pero si pongo el iclude se muere opcion:hacer toda la clase friend

using namespace std;

class cVuelo;
class cAvion;
class cAeropuerto;
class cListaEquipaje;
class cEquipaje;
class cFecha;


class cPasajero {
	friend class cAeropuerto;
	friend class cListaPasajeros;
	string DNI;
	string Nombre;
	cFecha* Fecha; //de nacimiento
	int Nvuelo;
	int Asiento;
	cListaEquipaje* ListaValijas;

public:
	cPasajero(string dni, string nombre, cFecha* fecha, int nvuelo, int asiento, cListaEquipaje* lista_equipaje);
	~cPasajero();
	void AgregarEquipaje(cEquipaje* valija_nueva);// Llama  al metodo agregar valija de la clase cListaEquipaje para agregar una valija a la losta del pasajero
	void EliminarEquipaje(cEquipaje* valija);
	int getNVuelo();
	string getDNI();
	cFecha* getFecha();
	cListaEquipaje* getListavalijas();
	cPasajero operator+(cEquipaje& valija_nueva);
	cPasajero operator-(cEquipaje& valija);
	string to_String();
	friend ostream& operator<<(ostream& out, cPasajero& pasajero);

};

