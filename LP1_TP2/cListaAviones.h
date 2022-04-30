#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>


class cVuelo;
class cPasajero;
class cListaVuelos;
class cListaPasajeros;
class cAeropuerto;
class cFecha;
class cAvion;

using namespace std;


class cListaAviones {
	cAvion** VectorAviones;
	unsigned int tam, cant_act;

public:
	cListaAviones(int T);
	~cListaAviones();
	void AgregarAvion(cAvion* avion);
	cAvion* QuitarAvion(cAvion* avion);
	void EliminarAvion(cAvion* avion);
	int Buscar(cAvion* avion);
	int getCant();
	int getTam();
	cAvion* operator[](int indice);
	friend ostream& operator<<(ostream& out, cListaAviones& lista_aviones);
	string to_String();

};