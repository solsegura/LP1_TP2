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
class cEquipaje;


class cListaEquipaje {
	cEquipaje** Vector_Equipaje;
	int tam, cant_act;

public:

	cListaEquipaje(int T); //max// Constructor de lista Equipaje, inicializa la cantidad actual de la lista en 0, y recibe T para el tamanio de la lista
	~cListaEquipaje();
	void AgregarValija(cEquipaje* valija_nueva);/// Agrega valija_nueva a la lista
	int getCant();
	int SumarPeso();
	int BuscarEquipaje(cEquipaje* valija);
	cEquipaje* GetValija(int indice);  //podria ser sobrecarga de [ ]  //igual creo que ni lo usamos
	void EliminarValija(cEquipaje* valija);
	friend ostream& operator<<(ostream& out, cListaEquipaje& lista_equipaje);
	string to_String();

};