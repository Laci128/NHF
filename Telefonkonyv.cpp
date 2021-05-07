#define _CRT_SECURE_NO_WARNINGS

#include "Telefonkonyv.h"

Telefonkonyv const& Telefonkonyv::operator=(Telefonkonyv const& rhs) {

	Bejegyzes* mozgo = rhs.elso;
	this->akt = this->elso = rhs.elso;

	this->akt = this->akt->getKov();
	mozgo = mozgo->getKov();

	while (mozgo != nullptr) {
		this->akt = mozgo;

		this->akt = this->akt->getKov();
		mozgo = mozgo->getKov();
	}

	return *this;
}

/*void Telefonkonyv::torol(Bejegyzes const& torlendo) {
		if(*elso == torlendo)



		akt = elso;
		Bejegyzes* lemarado = elso;
		while (!(*akt == torlendo)) {
			akt = akt->getKov();
		}

	}*/




void Telefonkonyv::hozzaad(Bejegyzes& hozzaadando){
	if (elso == nullptr)
		elso = &hozzaadando;
	
	while (akt != nullptr)
	{
		akt = akt->getKov();
	}

	akt = &hozzaadando;

}


void Telefonkonyv::kiir(std::ostream& os) const
{
	Bejegyzes* mozgo = elso;
	while (mozgo != nullptr)
	{
		mozgo->kiir(os);
		os << '\n';
	}
}

//***
//***
//***
//HOW TO F*CK DO I DO THIS PIECE OF.....
//***
//***
//***
void Telefonkonyv::beolvas(std::istream& is)
{

	char c;
	Bejegyzes temp;
	akt = &temp;

	akt->beolvas(is);
	akt = akt->getKov();
	is >> c;
	elso = akt;
	while (c != EOF && c == '\n')
	{
		akt = &temp;
		akt->beolvas(is);
		akt = akt->getKov();
		is >> c;
	}
	akt->setKov(nullptr);
}




Bejegyzes* Telefonkonyv::keres(String const& keresendo)
{
	Bejegyzes* tmp = elso;
	while (tmp != nullptr)
	{
		if (tmp->keres(keresendo))
			return tmp;
	}
	return nullptr;
}


//megkeresi az összes találatot a telefonkönyben és egy újba fûzi
	//lehet használni rajta a kiíratást
Telefonkonyv Telefonkonyv::keres_mind(String const& keresendo)
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