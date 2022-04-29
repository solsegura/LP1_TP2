#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <sstream>

//necesitamos declarados los metodos de cAeropuerto para hacerles friend pero si pongo el iclude se muere opcion:hacer toda la clase friend

using namespace std;

class cVuelo;
class cAvion;
class cAeropuerto;
class cListaEquipaje;
class cEquipaje;
class cFecha;


class cPasajero {
	friend class cAeropuerto;
	friend class cListaPasajeros;
	string DNI;
	string Nombre;
	cFecha* Fecha; //de nacimiento
	int Nvuelo;
	int Asiento;
	cListaEquipaje* ListaValijas;

public:
	cPasajero(string dni, string nombre, cFecha* fecha, int nvuelo, int asiento, cListaEquipaje* lista_equipaje);
	~cPasajero();
	void AgregarEquipaje(cEquipaje* valija_nueva);// Llama  al metodo agregar valija de la clase cListaEquipaje para agregar una valija a la losta del pasajero
	void EliminarEquipaje(cEquipaje* valija);
	int getNVuelo();
	string getDNI();
	cFecha* getFecha();
	cListaEquipaje* getListavalijas();
	cPasajero operator+(cEquipaje& valija_nueva);
	cPasajero operator-(cEquipaje& valija);
	string to_String();
	friend ostream& operator<<(ostream& out, const cPasajero& pasajero);
};

class cListaPasajeros {
	friend class cAeropuerto;
	cPasajero** Vector_Pasajeros;  
	unsigned int tam, cant_act;


public:
	cListaPasajeros(int T); //tam max
	~cListaPasajeros();
	void AgregarPasajero(cPasajero* pasajero);
	/// <summary>
	/// Copia la nueva informacion del pasajero en el indice que le pasamos por parametro
	/// </summary>
	void ModificarPasajero(cPasajero* pasajero1, cPasajero* pasajero2);
	void EliminarPasajero(cPasajero* pasajero);
	/// <summary>
	/// Retorna la posicion en la que esta el pasajero en la lista o -1 si no esta
	/// </summary>
	/// <param name="pasajero1"></param>
	/// <param name="pasajero2"></param>
	int Buscar(cPasajero* pasajero);
	/// <summary>
	/// Devuelve una lista de pasajeros filtrada por numero de vuelo
	/// </summary>
	/// <param name="pasajero"></param>
	cListaPasajeros* FiltrarLista(int vuelo);  
	int BuscarDNI(string dni);
	unsigned int getCant();
	cPasajero* operator[](int indice);  //sobrecarga de [] para cListaPasajero, devuelve el pasajero que esta en la posicion indice

	//metodos para imprimir
	string to_String();
	friend ostream& operator<<(ostream& out, const cListaPasajeros& lista_pasajeros);
};