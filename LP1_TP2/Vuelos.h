#pragma once
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class cAvion;
class cAeropuerto;
class cPasajero;

enum estado { on_time, delayed, boarding, flying};
enum part_arribo { partida, arribo };

class cVuelo {
	static int ContVuelo;   //la idea seria hacerlo como el pampa hizo lo del dni
	const int NumeroVuelo;
	estado EstadoVuelo;
	cAvion* Avion;
	string FechaHora_Salida;  // hacer cfecha
	string FechaHora_Llegada;
	string Destino;
	part_arribo PoA;
	cListaPasajeros* Pasajeros; //filtro

public:
	cVuelo(cAvion* avion, string fechasalida, string fechallegada, string destino, part_arribo poa);
	~cVuelo();

	cPasajero* DatosPasajero(string DNI);
	void AgregarPasajero(cPasajero* pasajero);
	void CambiarPasajero(cPasajero* pasajero_nuevo, cPasajero* pasajero_viejo);
	void EliminarPasajero(cPasajero* pasajero);
	void SetearAvion();
	void SetEstado(estado Estado);
	void SetListaPasajeros(cListaPasajeros* lista);
	static int getNumeroDeVuelo();
};

class cListaVuelos {
	cVuelo** VectorVuelos;
	unsigned int tam, cant_act;

public:
	cListaVuelos(int T);
	~cListaVuelos();
	void AgregarVuelo(cVuelo* vuelo);
	void QuitarVuelo(cVuelo* vuelo);
	void EliminarVuelo(cVuelo* vuelo);
	int Buscar(cVuelo* vuelo);
};