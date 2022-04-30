#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;
class cVuelo;
class cAvion;
class cPasajero;
class cListaAviones;
class cListaVuelos;
class cListaPasajeros;
class cFecha;

class cEquipaje {
	string Descripcion;
	int Peso;

public:
	cEquipaje(string desc, int peso);
	~cEquipaje(); 
	int GetPeso();
	friend ostream& operator<<(ostream& out, cEquipaje& equipaje);
	string to_String();
};
