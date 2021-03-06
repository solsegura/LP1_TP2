#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>


class cVuelo;
class cPasajero;
class cListaVuelos;
class cListaPasajeros;
class cListaAviones;
class cAeropuerto;
class cFecha;

using namespace std;

/*Un Avi?n que tiene un ID ?nico, cantidad de pasajeros que permite, cantidad actual,
peso m?ximo que puede transportar en total. El avi?n puede despegar, aterrizar,
pedir permiso y recibir permiso tanto para aterrizar como para despegar*/
enum estadoAvion { volando, en_tierra};

class cAvion {
	string ID;
	int CantPasajerosMax;
	int CantPasajerosAct;
	int PesoMax;
	int PesoAct;
	bool Permiso;
	estadoAvion Estado;


public:
	cAvion(string id, int cantmax);
	~cAvion();
	void Despegar();
	void Aterrizar();
	void PedirPermiso(bool PoA, cAeropuerto* aeropuerto);  
	void RecibirPermiso(bool permiso); //setter de Permiso
	bool ChequearCargaMaxima();  
	bool ChequearCapacidadMaxima();
	void setPesoActual(int peso);
	void setCantDePasajeros(int cant);
	int getCantPasajerosMax();
	string getID();
	string to_String();
	friend ostream& operator<<(ostream& out, cAvion& avion);
};
