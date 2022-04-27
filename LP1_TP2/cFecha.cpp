#include "cFecha.h"

using namespace std;

cFecha::cFecha(int anio, int mes, int dia)
{
	this->Anio = anio;
	this->Mes = mes;
	this->Dia = dia;
}

cFecha::~cFecha()
{
}

string cFecha::getFecha()
{
	stringstream ss;
	ss << to_string(this->Dia) << " / " << to_string(this->Mes) << " / " << to_string(this->Anio) << endl;
	return ss.str();
}


ostream& operator<<(ostream& out,cFecha& fecha)
{
	out << fecha.getFecha();
	return out;
}