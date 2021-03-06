#include "Aviones.h"
#include "Pasajeros.h"
#include "Aeropuertos.h"
#include "Vuelos.h"
#include "Valijas.h"
#include "cFecha.h"
#include "cListaEquipaje.h"
#include "cListaPasajero.h"
#include "cListaAviones.h"
#include "cListaVuelos.h"

#define MAX_PERSONAS 50
#define MAX_AVIONES 10
#define MAX_VUELOS 10
#define MAX_VALIJAS 5


using namespace std;

string lista_destino[5] = { "Jujuy","Cordoba", "Ushuaia", "Mendoza","Aeroparque" };

int main()
{
	cListaPasajeros* ListaPasajeros = new cListaPasajeros(MAX_PERSONAS);
	cListaAviones* ListaAviones = new cListaAviones(MAX_AVIONES);
	cListaVuelos* ListaVuelos = new cListaVuelos(MAX_VUELOS);

	cAeropuerto* Aeroparque = new cAeropuerto("Aeroparque", 25, 30, ListaPasajeros, ListaAviones,ListaVuelos);
	

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


	cListaEquipaje* ListaE1 = new cListaEquipaje(MAX_VALIJAS);
	cListaEquipaje* ListaE2 = new cListaEquipaje(MAX_VALIJAS);
	cListaEquipaje* ListaE3 = new cListaEquipaje(MAX_VALIJAS);
	cListaEquipaje* ListaE4 = new cListaEquipaje(MAX_VALIJAS);
	cListaEquipaje* ListaE5 = new cListaEquipaje(MAX_VALIJAS);


	cEquipaje* Valija1 = new cEquipaje("Bolso", 12);  //creamos algunos objetos de equipaje
	cEquipaje* Valija2 = new cEquipaje("Mochila", 7);
	cEquipaje* Valija3 = new cEquipaje("Valija", 17);
	cEquipaje* Valija4 = new cEquipaje("Bolso grande", 25);

	cPasajero* Pasajero1 = new cPasajero("23627615", "Sol", Nacimiento1, 1, 24, ListaE1);  //creamos pasajeros
	cPasajero* Pasajero2 = new cPasajero("34556776", "Fiorella", Nacimiento2, 2, 25, ListaE2);
	cPasajero* Pasajero3 = new cPasajero("21345673", "Rosario", Nacimiento3, 1, 26, ListaE3);
	cPasajero* Pasajero4 = new cPasajero("12345678", "Valentina", Nacimiento4, 3, 27, ListaE4);
	cPasajero* Pasajero5 = new cPasajero("12334554", "Martina", Nacimiento5, 1, 28, ListaE5);


	//try catch, throw si ya esta en la lista
	Aeroparque->AgregarPasajero(Pasajero1);
	Aeroparque->AgregarPasajero(Pasajero2);
	Aeroparque->AgregarPasajero(Pasajero3);
	Aeroparque->AgregarPasajero(Pasajero4);
	Aeroparque->AgregarPasajero(Pasajero5);

	
	
	*Pasajero1 + *Valija1;  //los pasajeros agregan su equipaje
	*Pasajero1 + *Valija1;  
	*Pasajero2 + *Valija4; 
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

	cVuelo* Vuelo1 = new cVuelo(on_time, Avion1, Dia1, Dia1, lista_destino[0], partida); 
	cVuelo* Vuelo2 = new cVuelo(delayed, Avion2, Dia1, Dia2, lista_destino[1], partida);
	cVuelo* Vuelo3 = new cVuelo(on_time, Avion1, Dia2, Dia3, lista_destino[4], arribo);

	Aeroparque->AgregarVuelo(Vuelo1);  //agregamos los vuelos a la lista de vuelos del aeropuerto
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
	cout << (*Aeroparque);
	system("pause");
	system("cls");

	cout << "---------ESTADISTICAS DE AEROPARQUE------------" << endl;
	cout << "Porcentaje de vuelos en horario:" << to_string(Aeroparque->PorcentajeEnHorario()) << endl;

	cout << "Cantidad de pasajeros que volaron el dia: " << *Dia1 << to_string(Aeroparque->CantVuelosDia(Dia1)) << endl;
	cout << "Cantidad de pasajeros que volaron el dia: " << *Dia2 << to_string(Aeroparque->CantVuelosDia(Dia2)) << endl;
	cout << "Cantidad de pasajeros que volaron el dia: " << *Dia3 << to_string(Aeroparque->CantVuelosDia(Dia3)) << endl;
	cout << "Cantidad de pasajeros que volaron el dia: " << *Dia4 << to_string(Aeroparque->CantVuelosDia(Dia4)) << endl;
	cout << "Cantidad de pasajeros que volaron el dia: " << *Dia5 << to_string(Aeroparque->CantVuelosDia(Dia5)) << endl;

	cout << "Cantidad de vuelos que aterrizaron y despegaron en el dia: " << *Dia1 << to_string(Aeroparque->FiltrarDia(Dia1)) << endl;
	cout << "Cantidad de vuelos que aterrizaron y despegaron en el dia: " << *Dia2 << to_string(Aeroparque->FiltrarDia(Dia2)) << endl;
	cout << "Cantidad de vuelos que aterrizaron y despegaron en el dia: " << *Dia3 << to_string(Aeroparque->FiltrarDia(Dia3)) << endl;
	cout << "Cantidad de vuelos que aterrizaron y despegaron en el dia: " << *Dia4 << to_string(Aeroparque->FiltrarDia(Dia4)) << endl;
	cout << "Cantidad de vuelos que aterrizaron y despegaron en el dia: " << *Dia5 << to_string(Aeroparque->FiltrarDia(Dia5)) << endl;

	//DELETES
	delete ListaPasajeros;
	delete ListaVuelos;
	delete ListaAviones;
	delete Aeroparque;
	delete Dia1;
	delete Dia2;
	delete Dia3;
	delete Dia4;
	delete Dia5;
	delete Nacimiento1;
	delete Nacimiento2;
	delete Nacimiento3;
	delete Nacimiento4;
	delete Nacimiento5;
	delete Valija1;
	delete Valija2;
	delete Valija3;
	delete Valija4;
	delete ListaE1;
	delete ListaE2;
	delete ListaE3;
	delete ListaE4;
	delete ListaE5;
	delete Pasajero1;
	delete Pasajero2;
	delete Pasajero3;
	delete Pasajero4;
	delete Pasajero5;
	delete Avion1;
	delete Avion2;
	delete Vuelo1;
	delete Vuelo2;
	delete Vuelo3;






}
