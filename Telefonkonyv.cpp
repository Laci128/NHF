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
	if (elso == nullptr) {
		elso = &hozzaadando;
		return;
	}

	/*akt = elso;
	while (akt != nullptr) {
		if (*akt == hozzaadando)
			throw "Ez a bejegyzes mar benne van a telefonkonyvben!";
	}*/


	akt = elso;
	while (akt->getKov() != nullptr) //<elmegyunk az utolso elemig
	{
		akt = akt->getKov();
	}

	akt->setKov(&hozzaadando);

}


void Telefonkonyv::kiir(std::ostream& os) const
{
	Bejegyzes* mozgo = elso;
	while (mozgo != nullptr)
	{
		mozgo->kiir(os);
		os << '\n';
		mozgo = mozgo->getKov();
	}
}



void Telefonkonyv::beolvas(std::istream& is){
	String veznev;
	String kernev;
	String temp;
	String temp2;
	char space;
	char c;
	char fajl_vege_e;

	while (is >> c && is >> fajl_vege_e) {
		is.putback(fajl_vege_e);
		is.putback(c);
		veznev.beolvas(is);
		kernev.beolvas(is);
		temp.beolvas(is);
		is >> space;
		is >> c;
		if (c == '\n') {
			Munkatars ujMunkatars(veznev, kernev, temp);
			ujMunkatars.setKov(nullptr);
			akt = &ujMunkatars;
			if (elso == nullptr)
				elso = akt;
			akt = akt->getKov();
			is.putback(space);
		}
		else {
			is.putback(c);
			temp2.beolvas(is);
			Barat ujBarat(veznev, kernev, temp, temp2);
			ujBarat.setKov(nullptr);
			akt = &ujBarat;
			if (elso == nullptr) {
				elso = akt;

			}
			akt = akt->getKov();
	
		}
		is >> space;

	} 

}



template<class Funktor>
Bejegyzes* Telefonkonyv::keres(String const& keresendo, Funktor fun)
{
	Bejegyzes* tmp = elso;
	while (tmp != nullptr)
	{
		if (tmp->keres(keresendo))
			return tmp;
	}
	return nullptr;
}


//megkeresi az osszes talalatot a telefonkonyvben es egy ujba fuzi
	//lehet hasznalni rajta a kiiratast
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