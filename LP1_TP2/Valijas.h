#pragma once
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

class cEquipaje {
	string Descripcion;
	int Peso;

public:
	/// <summary>
	/// Constructor de la clase Equipaje 
	/// </summary>
	/// <param name="desc"></param>
	/// <param name="peso"></param>
	cEquipaje(string desc, int peso);
	///Destructor de Equipaje
	~cEquipaje(); 
	int GetPeso();

};

class cListaEquipaje {
	cEquipaje** Vector_Equipaje;
	int tam, cant_act;

public:
	/// <summary>
	/// Constructor de lista Equipaje, inicializa la cantidad actual de la lista en 0, y recibe T para el tamanio de la lista
	/// </summary>
	/// <param name="T"></param>
	cListaEquipaje(int T);
	///Destructor de Lista Equipaje
	~cListaEquipaje();
	/// <summary>
	/// Agrega valija_nueva a la lista
	/// </summary>
	/// <param name="valija_nueva"></param>
	void AgregarValija(cEquipaje* valija_nueva);
	/// <summary>
	/// Elimina valija de la lista
	/// </summary>
	/// <param name="valija"></param>
	cEquipaje* EliminarValija(cEquipaje* valija);

	int SumarPeso();
	cEquipaje* GetValija(int indice);

	int getCant();
};