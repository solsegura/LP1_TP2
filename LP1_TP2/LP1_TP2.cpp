#include "Aviones.h"
#include "Pasajeros.h"
#include "Aeropuertos.h"
#include "Vuelos.h"
#include "Valijas.h"
#include <iostream>



int main()
{
	cAeropuerto* Aeroparque = new cAeropuerto("Aeroparque", 25, 30);

	cEquipaje* Valija1 = new cEquipaje("Bolso", 12);  //creamos algunos objetos de equipaje
	cEquipaje* Valija2 = new cEquipaje("Mochila", 7);
	cEquipaje* Valija3 = new cEquipaje("Valija", 17);
	cEquipaje* Valija4 = new cEquipaje("Bolso grande", 25);

	cPasajero* Pasajero1 = new cPasajero("23627615", "Sol", "23/4/2000", 1, 24, 2);  //creamos pasajeros
	cPasajero* Pasajero2 = new cPasajero("34556776", "Fiorella", "27/6/2002", 2, 25, 2);
	cPasajero* Pasajero3 = new cPasajero("21345673", "Rosario", "30/11/2003", 1, 26, 3);
	cPasajero* Pasajero4 = new cPasajero("12345678", "Valentina", "12/5/2000", 3, 27, 2);
	cPasajero* Pasajero5 = new cPasajero("12334554", "Martina", "24/4/2001", 1, 28, 1);

	cListaPasajeros* ListaPasajeros = new cListaPasajeros(Aeroparque->getCapacidad());
	ListaPasajeros->AgregarPasajero(Pasajero1);
	ListaPasajeros->AgregarPasajero(Pasajero2);
	ListaPasajeros->AgregarPasajero(Pasajero3);
	ListaPasajeros->AgregarPasajero(Pasajero4);
	ListaPasajeros->AgregarPasajero(Pasajero5);
	cPasajero* caca= (*ListaPasajeros)[2];

	*Pasajero1 + *Valija1;  //los pasajeros agregan su equipaje
	*Pasajero1 + *Valija1;
	Pasajero2->AgregarEquipaje(Valija4); //cambiar con sobrecarga
	Pasajero2->AgregarEquipaje(Valija2);
	Pasajero3->AgregarEquipaje(Valija1);
	Pasajero3->AgregarEquipaje(Valija2);
	Pasajero3->AgregarEquipaje(Valija3);
	Pasajero4->AgregarEquipaje(Valija2);
	Pasajero4->AgregarEquipaje(Valija2);
	Pasajero5->AgregarEquipaje(Valija4);
	*Pasajero1 - *Valija1;  //saco una valija

	cAvion* Avion1 = new cAvion("Flybondi01", 20);
	cAvion* Avion2 = new cAvion("Flybondi02", 2);

	cVuelo* Vuelo1 = new cVuelo(Avion1, "20/02/2022", "20/02/2022","Cordoba", partida);
	cVuelo* Vuelo2 = new cVuelo(Avion2, "20/02/2022", "21/02/2022","Uruguay" ,partida);
	cVuelo* Vuelo3 = new cVuelo(Avion1, "22/02/2022", "22/02/2022", "Jujuy",partida);

	Vuelo1->SetListaPasajeros(ListaPasajeros->FiltrarLista(Vuelo1->getNumeroDeVuelo()));
	Vuelo2->SetListaPasajeros(ListaPasajeros->FiltrarLista(Vuelo2->getNumeroDeVuelo()));
	Vuelo3->SetListaPasajeros(ListaPasajeros->FiltrarLista(Vuelo3->getNumeroDeVuelo()));

}
