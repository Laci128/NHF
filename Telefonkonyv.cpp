#define _CRT_SECURE_NO_WARNINGS

#include "Telefonkonyv.h"



/*void Telefonkonyv::torol(Bejegyzes& torlendo) {
		if(*elso == torlendo)



		akt = elso;
		Bejegyzes* lemarado = elso;
		while (!(*akt == torlendo)) {
			akt = akt->getKov();
		}

	}*/

Telefonkonyv::Telefonkonyv(Telefonkonyv const& rhs)
{

}



void Telefonkonyv::hozzaad(Bejegyzes const& hozzaadando){
	while (akt != NULL)
	{
		akt = akt->getKov();
	}
	*akt = hozzaadando;
}

void Telefonkonyv::kiir(std::ostream& os) const
{
	Bejegyzes* mozgo = elso;
	while (mozgo != NULL)
	{
		mozgo->kiir(os);
		os << '\n';
	}
}


void Telefonkonyv::beolvas(std::istream& is)
{
	//Bejegyzes temp;
	//akt = &temp;
	char c;
	akt->beolvas(is);
	akt = akt->getKov();
	is >> c;
	elso = akt;
	while (c != EOF && c == '\n')
	{
		akt->beolvas(is);
		akt = akt->getKov();
		is >> c;
	}
	akt->setKov(NULL);
}




Bejegyzes* Telefonkonyv::keres(const String keresendo)
{
	Bejegyzes* tmp = elso;
	while (tmp != nullptr)
	{
		if (tmp->keres(keresendo))
			return tmp;
	}
}


//megkeresi az �sszes tal�latot a telefonk�nyben �s egy �jba f�zi
	//lehet haszn�lni rajta a ki�rat�st
Telefonkonyv Telefonkonyv::keres_mind(const String keresendo)
{
	Bejegyzes* tmp = elso;
	Telefonkonyv result;
	while (tmp != nullptr)
	{
		if (tmp->keres(keresendo))
			result.hozzaad(*tmp);
	}
	return result;
}