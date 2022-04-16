#pragma once
#include <string>
#include <stdio.h>
#include <iostream>

class cVuelo;
class cAeropuerto;
class cPasajero;

/*Un Avión que tiene un ID único, cantidad de pasajeros que permite, cantidad actual,
peso máximo que puede transportar en total. El avión puede despegar, aterrizar,
pedir permiso y recibir permiso tanto para aterrizar como para despegar*/
enum estado{ volando, en_tierra};

class cAvion {
	int ID;
	int CantPasajerosMax;
	int CantPasajerosAct;
	int PesoMax;
	int PesoAct;
	bool Permiso;
	estado Estado;


public:
	cAvion(int id, int cantmax);
	~cAvion();
	void Despegar();
	void Aterrizar();
	void PedirPermiso();  //no entiendo que tiene que hacer esta cosa (tal vez con clase friend al aeropuerto?)
	void RecibirPermiso(bool permiso); //setter de Permiso
	bool ChequearCargaMaxima();  
	bool ChequearCapacidadMaxima();
	void setPesoActual(int peso);
	void setCantDePasajeros(int cant);
};

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
};