#pragma once
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

class cAvion;
class cPasajero;
class cListaAviones;
class cListaPasajeros;
class cAeropuerto;
class cFecha;
class cVuelo;


class cListaVuelos {
	friend class cAeropuerto;
	/*friend int cAeropuerto::CantVuelosDia(cFecha* dia);
	friend int cAeropuerto::FiltrarDia(cFecha* dia);
	friend float cAeropuerto::PorcentajeEnHorario();*/
	cVuelo** VectorVuelos;
	unsigned int tam, cant_act;

public:
	cListaVuelos(int T);
	~cListaVuelos();
	void AgregarVuelo(cVuelo* vuelo);
	//cVuelo* QuitarVuelo(cVuelo* vuelo);     creo que no lo necesitamos
	void EliminarVuelo(cVuelo* vuelo);
	int getCantAct();
	int Buscar(cVuelo* vuelo);
	cVuelo* operator[](int indice);
	string to_String();
	friend ostream& operator<<(ostream& out, cListaVuelos& vuelo);
};

