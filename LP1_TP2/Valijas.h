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
	int GetPeso();

};

class cListaEquipaje {
	cEquipaje** Vector_Equipaje;
	int tam, cant_act;

public:
	
	cListaEquipaje(int T); //max// Constructor de lista Equipaje, inicializa la cantidad actual de la lista en 0, y recibe T para el tamanio de la lista
	~cListaEquipaje();
	void AgregarValija(cEquipaje* valija_nueva);/// Agrega valija_nueva a la lista
	int getCant();
	int SumarPeso();
	cEquipaje* GetValija(int indice);
	cEquipaje* EliminarValija(cEquipaje* valija);
	
};