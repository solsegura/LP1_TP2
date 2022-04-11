#pragma once
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

class cEquipaje {
	string Descripcion;
	int Peso;

public:
	cEquipaje(string desc, int peso);
	~cEquipaje();

};

class cListaEquipaje {
	cEquipaje** Vector_Equipaje;
	int tam, cant_act;

public:
	cListaEquipaje(int T);
	~cListaEquipaje();
	void AgregarValija(cEquipaje* valija_nueva);
	void EliminarValija(cEquipaje* valija);
};