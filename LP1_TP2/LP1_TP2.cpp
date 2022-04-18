#include "Aviones.h"
#include "Pasajeros.h"
#include "Aeropuertos.h"
#include "Vuelos.h"
#include "Valijas.h"
#include <iostream>



int main()
{
	cEquipaje* Valija1 = new cEquipaje("Bolso", 12);  //creamos algunos objetos de equipaje
	cEquipaje* Valija2 = new cEquipaje("Mochila", 7);
	cEquipaje* Valija3 = new cEquipaje("Valija", 17);
	cEquipaje* Valija4 = new cEquipaje("Bolso grande", 25);

	cPasajero* Pasajero1 = new cPasajero("23627615", "Sol", "23/4/2000", "201", 24, 2);  //creamos pasajeros
	cPasajero* Pasajero2 = new cPasajero("34556776", "Fiorella", "27/6/2002", "201", 25, 2);
	cPasajero* Pasajero3 = new cPasajero("21345673", "Rosario", "30/11/2003", "201", 26, 3);
	cPasajero* Pasajero4 = new cPasajero("12345678", "Valentina", "12/5/2000", "201", 27, 2);
	cPasajero* Pasajero5 = new cPasajero("12334554", "Martina", "24/4/2001", "201", 28, 1);

	Pasajero1->AgregarEquipaje(Valija1);   //los pasajeros agregan su equipaje
	Pasajero1->AgregarEquipaje(Valija1);
	Pasajero2->AgregarEquipaje(Valija4);
	Pasajero2->AgregarEquipaje(Valija2);
	Pasajero3->AgregarEquipaje(Valija1);
	Pasajero3->AgregarEquipaje(Valija2);
	Pasajero3->AgregarEquipaje(Valija3);
	Pasajero4->AgregarEquipaje(Valija2);
	Pasajero4->AgregarEquipaje(Valija2);
	Pasajero5->AgregarEquipaje(Valija4);

	cAvion* Avion1 = new cAvion("Flybondi01", 20);
	cAvion* Avion1 = new cAvion("Flybondi02", 2);





}
