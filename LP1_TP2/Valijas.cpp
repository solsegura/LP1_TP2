#include "Aviones.h"
#include "Pasajeros.h"
#include "Aeropuertos.h"
#include "Vuelos.h"
#include "Valijas.h"
#include "cFecha.h"

cEquipaje::cEquipaje(string desc, int peso)
{
	this->Descripcion = desc;
	this->Peso = peso;

}

cEquipaje::~cEquipaje()
{
}

int cEquipaje::GetPeso()
{
	return this->Peso;
}

string cEquipaje::to_String()
{
	stringstream ss;
	ss << endl << "  Descripcion: " << this->Descripcion << endl;
	ss << "  Peso: " << to_string(this->Peso)<< "kg." << endl;
	return ss.str(); //.str convierte a string el ss
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
	for (int i = 0; i < this->tam; i++)
		this->Vector_Equipaje = NULL;
	delete[] this->Vector_Equipaje;
}

void cListaEquipaje::AgregarValija(cEquipaje* valija_nueva)
{
	if (this->cant_act < this->tam) { //tam= max
		this->Vector_Equipaje[cant_act] = valija_nueva;
		this->cant_act++;
	}
	if (this->SumarPeso() > 25) {   //chequeamos que al agregar la valija no se pase del peso maximo
		this->EliminarValija(valija_nueva);
		cout << " No se pudo agregar a su lista de equipaje el siguiente elemento porque sobrepasa el total de 25kg." << valija_nueva->to_String() << endl << endl;
	}
}

void cListaEquipaje::EliminarValija(cEquipaje* valija)
{
	int indice = BuscarEquipaje(valija);
		if (indice!=-1) {
			this->Vector_Equipaje[indice] = this->Vector_Equipaje[this->cant_act - 1]; //reeemplazo el que voy a borrar con el ultimo de la lista
			this->Vector_Equipaje[this->cant_act - 1] = NULL; //borro el ultimo de la lista porque ya lo deje en otro lado
			this->cant_act--;
		}
}
		

string cListaEquipaje::to_String()
{
	stringstream ss;
	ss << "  Cantidad de valijas: " << to_string(this->cant_act) << endl;
	for (int i = 0; i < this->cant_act; i++) {
		int aux = i + 1;
		ss << endl << "Valija " << to_string(aux) << " : " << endl;
		ss << this->Vector_Equipaje[i]->to_String() << endl;
	}
	return ss.str();
}

int cListaEquipaje::SumarPeso()
{
	int peso = 0;
	for (int i = 0; i < this->cant_act; i++) {
		peso += this->Vector_Equipaje[i]->GetPeso();
	}
	return peso;
}

int cListaEquipaje::BuscarEquipaje(cEquipaje* valija)
{
	for (int i = 0; i < this->cant_act; i++)
		if (this->Vector_Equipaje[i] == valija)
			return i;
	return -1;  //si no la encuentro devuelvo -1
}

cEquipaje* cListaEquipaje::GetValija(int indice)
{
	return this->Vector_Equipaje[indice];
}

int cListaEquipaje::getCant()
{
	return this->cant_act;
}

ostream& operator<<(ostream& out, cEquipaje& equipaje)
{
	out << equipaje.to_String();
	return out;
}

ostream& operator<<(ostream& out, cListaEquipaje& lista_equipaje)
{
	out << lista_equipaje.to_String();
	return out;
}
