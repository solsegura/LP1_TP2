#pragma once
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;


class cFecha
{
	int Anio, Mes, Dia;
	
public:
	cFecha(int anio, int mes, int dia);
	~cFecha();

	
	friend ostream& operator<<(ostream& out, const cFecha& fecha);
	string getFecha();
};

