#pragma once
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class cFecha;
class cAvion;
class cAeropuerto;
class cPasajero;

enum estado { on_time, delayed, boarding, flying};
enum part_arribo { partida, arribo };

class cVuelo {
	friend int cAeropuerto::CantVuelosDia(cFecha* dia);
	friend class cFecha;
	friend int cAeropuerto::FiltrarDia(cFecha* dia);
	static int ContVuelo;   //la idea seria hacerlo como el pampa hizo lo del dni
	const int NumeroVuelo;
	estado EstadoVuelo;
	cAvion* Avion;
	cFecha* FechaHora_Salida; 
	cFecha* FechaHora_Llegada;
	string Destino;
	part_arribo PoA;
	cListaPasajeros* Pasajeros; //filtro

public:
	cVuelo(cAvion* avion, cFecha* fechasalida, cFecha* fechallegada, string destino, part_arribo poa);
	~cVuelo();

	cPasajero* DatosPasajero(string DNI);
	void AgregarPasajero(cPasajero* pasajero);
	void CambiarPasajero(cPasajero* pasajero_nuevo, cPasajero* pasajero_viejo);
	void EliminarPasajero(cPasajero* pasajero);
	void SetearAvion();
	void SetEstado(estado Estado);
	part_arribo getPoA();
	cFecha* getFecha_Llegada();
	cFecha* getFecha_Salida();
	void SetListaPasajeros(cListaPasajeros* lista);
	static int getNumeroDeVuelo(); //NUMERO VUELO ES CONST, error en el cpp, deberia ser solo int.

};

class cListaVuelos {
	friend int cAeropuerto::CantVuelosDia(cFecha* dia);
	friend int cAeropuerto::FiltrarDia(cFecha* dia);
	cVuelo** VectorVuelos;
	unsigned int tam, cant_act;

public:
	cListaVuelos(int T);
	~cListaVuelos();
	void AgregarVuelo(cVuelo* vuelo);
	void QuitarVuelo(cVuelo* vuelo);
	void EliminarVuelo(cVuelo* vuelo);
	int getCantAct();
	int Buscar(cVuelo* vuelo);
};