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

enum estado { on_time, delayed };
enum part_arribo { partida, arribo };

class cVuelo {
	friend int cAeropuerto::CantVuelosDia(cFecha* dia);
	friend class cFecha;
	friend int cAeropuerto::FiltrarDia(cFecha* dia);
	static int ContVuelo;   //la idea seria hacerlo como el pampa hizo lo del dni
	const int NumeroVuelo;  //hacemos que el numero de vuelo sea constante ya que no va a variar
	estado EstadoVuelo;
	cAvion* Avion;
	cFecha* FechaHora_Salida; 
	cFecha* FechaHora_Llegada;
	string Destino; //aeroparque u otro
	//cAeropuerto* Salida;
	//cAeropuerto* Destino; //aeroparque u otro
	part_arribo PoA;
	cListaPasajeros* Pasajeros; //filtro

public:
	//cVuelo(estado estadovuelo, cAvion* avion, cFecha* fechasalida, cFecha* fechallegada, cAeropuerto* salida, cAeropuerto* destino, part_arribo poa);
	cVuelo(estado estadovuelo, cAvion* avion, cFecha* fechasalida, cFecha* fechallegada,string destino, part_arribo poa);
	~cVuelo();

	cPasajero* DatosPasajero(string DNI);
	void AgregarPasajero(cPasajero* pasajero);
	void CambiarPasajero(cPasajero* pasajero_nuevo, cPasajero* pasajero_viejo);
	void EliminarPasajero(cPasajero* pasajero);
	void Pedir_Permiso(cAeropuerto* aeropuerto);
	void SetearAvion();
	void SetEstado(estado Estado); //creo que no la usamos
	part_arribo getPoA();
	cFecha* getFecha_Llegada();
	cFecha* getFecha_Salida();
	void SetListaPasajeros(cListaPasajeros* lista);
	int getNumeroDeVuelo(); //antes era static
	
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
	//cVuelo* QuitarVuelo(cVuelo* vuelo);     creo que no lo necesitamos
	void EliminarVuelo(cVuelo* vuelo);
	int getCantAct();
	int Buscar(cVuelo* vuelo);
	cVuelo* operator[](int indice);
};