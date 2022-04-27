#include "Aviones.h"
#include "Pasajeros.h"
#include "Aeropuertos.h"
#include "Vuelos.h"
#include "Valijas.h"
#include "cFecha.h"
#include <iostream>
#define MAX_PERSONAS 50

using namespace std;

string lista_destino[5] = { "Jujuy","Cordoba", "Ushuaia", "Mendoza","Aeroparque" };

int main()
{
	cListaPasajeros* ListaPasajeros = new cListaPasajeros(MAX_PERSONAS);
	cAeropuerto* Aeroparque = new cAeropuerto("Aeroparque", 25, 30, ListaPasajeros);
	cAeropuerto* Jujuy = new cAeropuerto("Jujuy", 25, 30, ListaPasajeros);
	cAeropuerto* Cordoba = new cAeropuerto("Cordoba", 25, 30, ListaPasajeros);

	cFecha* Dia1 = new cFecha(1, 4, 2022);
	cFecha* Dia2 = new cFecha(2, 4, 2022);
	cFecha* Dia3 = new cFecha(3, 4, 2022);
	cFecha* Dia4 = new cFecha(4, 4, 2022);
	cFecha* Dia5 = new cFecha(5, 4, 2022);

	cFecha* Nacimiento1 = new cFecha(1, 5, 1971);
	cFecha* Nacimiento2 = new cFecha(12, 3, 1998);
	cFecha* Nacimiento3 = new cFecha(9, 4, 1960);
	cFecha* Nacimiento4 = new cFecha(3, 4, 2001);
	cFecha* Nacimiento5 = new cFecha(22, 11, 2000);



	cEquipaje* Valija1 = new cEquipaje("Bolso", 12);  //creamos algunos objetos de equipaje
	cEquipaje* Valija2 = new cEquipaje("Mochila", 7);
	cEquipaje* Valija3 = new cEquipaje("Valija", 17);
	cEquipaje* Valija4 = new cEquipaje("Bolso grande", 25);

	cPasajero* Pasajero1 = new cPasajero("23627615", "Sol", Nacimiento1, 1, 24, 2);  //creamos pasajeros
	cPasajero* Pasajero2 = new cPasajero("34556776", "Fiorella", Nacimiento2, 2, 25, 2);
	cPasajero* Pasajero3 = new cPasajero("21345673", "Rosario", Nacimiento3, 1, 26, 3);
	cPasajero* Pasajero4 = new cPasajero("12345678", "Valentina", Nacimiento4, 3, 27, 2);
	cPasajero* Pasajero5 = new cPasajero("12334554", "Martina", Nacimiento5, 1, 28, 1);


	
	Aeroparque->AgregarPasajero(Pasajero1);
	Aeroparque->AgregarPasajero(Pasajero2);
	Aeroparque->AgregarPasajero(Pasajero3);
	Aeroparque->AgregarPasajero(Pasajero4);
	Aeroparque->AgregarPasajero(Pasajero5);

	
	
	*Pasajero1 + *Valija1;  //los pasajeros agregan su equipaje
	*Pasajero1 + *Valija1;
	*Pasajero2 + *Valija4; //cambiar con sobrecarga
	*Pasajero2 + *Valija2;
	*Pasajero3 + *Valija1;
	*Pasajero3 + *Valija2;
	*Pasajero3 + *Valija3;
	*Pasajero4 + *Valija2;
	*Pasajero4 + *Valija2;
	*Pasajero5 + *Valija4;
	*Pasajero1 - *Valija1;  //saco una valija para probar

	cAvion* Avion1 = new cAvion("Flybondi01", 20);
	cAvion* Avion2 = new cAvion("Flybondi02", 2);

	Aeroparque->AgregarAvion(Avion1);
	Aeroparque->AgregarAvion(Avion2);

	cVuelo* Vuelo1 = new cVuelo(on_time, Avion1, Dia1, Dia1, lista_destino[0], partida); //problema con el enum de estado
	cVuelo* Vuelo2 = new cVuelo(delayed, Avion2, Dia1, Dia2, lista_destino[1], partida);
	cVuelo* Vuelo3 = new cVuelo(on_time, Avion1, Dia2, Dia3, lista_destino[4], arribo);

	Aeroparque->AgregarVuelo(Vuelo1);
	Aeroparque->AgregarVuelo(Vuelo2);
	Aeroparque->AgregarVuelo(Vuelo3);


	Vuelo1->SetListaPasajeros(ListaPasajeros->FiltrarLista(Vuelo1->getNumeroDeVuelo())); //ponemos en cada vuelo a los pasajeros que corresponden
	Vuelo2->SetListaPasajeros(ListaPasajeros->FiltrarLista(Vuelo2->getNumeroDeVuelo()));
	Vuelo3->SetListaPasajeros(ListaPasajeros->FiltrarLista(Vuelo3->getNumeroDeVuelo()));

	Vuelo1->SetearAvion(); //seteamos el avion con los datos de los pasajeros y su equipaje
	Vuelo2->SetearAvion();
	Vuelo3->SetearAvion();

	for(int i=0;i<Aeroparque->GetListaVuelos()->getCantAct();i++)
		(*(Aeroparque->GetListaVuelos()))[i]->Pedir_Permiso(Aeroparque); //todos los vuelos piden su permiso correspondiente y si lo obtienen van aterrizando/ despegando
	
	system("pause");
	system("cls");

	cout << "--------AEROPUERTO--------" << endl << endl;
	cout << Aeroparque;
	system("pause");
	system("cls");

	
}
