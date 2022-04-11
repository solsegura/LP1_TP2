#pragma once
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class cAvion;
class cAeropuerto;
class cPasajero;

enum estado { en_tiempo, retrasado, abordando, en_vuelo };
enum part_arribo { partida, arribo };

class cVuelo {
	string NumeroVuelo;
	estado EstadoVuelo;
	cAvion* Avion;
	string FechaHora_Salida;
	string FechaHora_Llegada;
	string Destino;
	part_arribo PoA;
	cListaPasajeros* Pasajeros;

public:
	cVuelo(cAvion* avion, string fechasalida, string fechallegada, string destino, part_arribo poa, cListaPasajeros pasajeros);
	~cVuelo();
	cPasajero* DatosPasajero(string DNI);
	void AgregarPasajero(cPasajero* pasajero);
	void CambiarPasajero(cPasajero* pasajero);
	void EliminarPasajero(cPasajero* pasajero);
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