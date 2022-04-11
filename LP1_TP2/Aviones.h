#pragma once
#include <string>
#include <stdio.h>
#include <iostream>

class cVuelo;
class cAeropuerto;
class cPasajero;

/*Un Avi�n que tiene un ID �nico, cantidad de pasajeros que permite, cantidad actual,
peso m�ximo que puede transportar en total. El avi�n puede despegar, aterrizar,
pedir permiso y recibir permiso tanto para aterrizar como para despegar*/

class cAvion {
	const int ID;
	const int CantPasajerosMax;
	int CantPasajerosAct;
	const int PesoMax;

public:
	cAvion(int id, int cantmax, int maxpersonas);
	~cAvion();
	void Despegar();
	void Aterrizar();
	void PedirPermiso();
};

class cListaAviones {
	cVuelo** VectorAviones;
	unsigned int tam, cant_act;

public:
	cListaAviones(int T);
	~cListaAviones();
	void AgregarAvion(cAvion* avion);
	void QuitarAvion(cAvion* avion);
	void EliminarAvion(cAvion* avion);
	int Buscar(cAvion* avion);
};