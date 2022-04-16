#include "Valijas.h"

cEquipaje::cEquipaje(string desc, int peso)
{
	this->Descripcion = desc;
	this->Peso = peso;

}

cEquipaje::~cEquipaje()
{
}

cListaEquipaje::cListaEquipaje(int T)
{
	this->tam = T;
	this->cant_act = 0;
	this->Vector_Equipaje = new cEquipaje * [T];
	for (int i = 0; i < T; i++)
		this->Vector_Equipaje[i] = NULL;
}

cListaEquipaje::~cListaEquipaje()
{
	if (this->Vector_Equipaje != NULL) {
		for (int i = 0; i < this->cant_act; i++) {
			if (this->Vector_Equipaje[i] != NULL) {
				delete[]this->Vector_Equipaje;
				this->Vector_Equipaje = NULL;
			}
		}

	}
}

void cListaEquipaje::AgregarValija(cEquipaje* valija_nueva)
{
	if (this->cant_act < this->tam) {
		this->Vector_Equipaje[cant_act] = valija_nueva;
		cant_act++;
	}
}

cEquipaje* cListaEquipaje::EliminarValija(cEquipaje* valija)
{
	cEquipaje* aux=NULL;
	for (int i = 0; i < this->cant_act; i++) {
		if (this->Vector_Equipaje[i] == valija) {
			aux = this->Vector_Equipaje[i];
			this->Vector_Equipaje[i] = this->Vector_Equipaje[this->cant_act - 1]; //reeemplazo el que voy a borrar con el ultimo de la lista
			this->Vector_Equipaje[this->cant_act - 1] = NULL; //borro el ultimo de la lista porque ya lo deje en otro lado
			return aux;
		}
	}
}

int cListaEquipaje::SumarPeso()
{
	int peso = 0;
	for (int i = 0; i < this->cant_act; i++) {
		peso += this->Vector_Equipaje[i]->GetPeso();
	}
	return peso;
}

int cListaEquipaje::getCant()
{
	return this->cant_act;
}
