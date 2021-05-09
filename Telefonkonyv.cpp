#define _CRT_SECURE_NO_WARNINGS

#include "Telefonkonyv.h"

Telefonkonyv const& Telefonkonyv::operator=(Telefonkonyv const& rhs) {

	Bejegyzes* mozgo = rhs.elso;
	akt = elso = rhs.elso;

	akt = akt->getKov();
	mozgo = mozgo->getKov();

	while (mozgo != nullptr) {
		akt = mozgo;

		akt = akt->getKov();
		mozgo = mozgo->getKov();
	}

	return *this;
}

///Keresesbol kellene megoldani
///Munkatars vagy Barat
void Telefonkonyv::torol(Bejegyzes& torlendo) {
	Bejegyzes* temp;
	if (*elso == torlendo) {
		temp = elso->getKov();
		delete elso;
		elso = temp;
		return;
	}
	else {
		akt = elso;
		Bejegyzes* lemarado = elso;
		while (!(*akt == torlendo) && akt->getKov() != nullptr) {
			lemarado = akt;
			akt = akt->getKov();
		}
		lemarado->setKov(akt->getKov());
		delete akt;
		return;
	}
	
	throw "Nincs ilyen bejegyzes a telefonkonyvben!";

}



void Telefonkonyv::hozzaad(Bejegyzes& hozzaadando){
	if (elso == nullptr) {
		elso = &hozzaadando;
		return;
	}

	akt = elso;
	while (akt != nullptr) {
		if (*akt == hozzaadando) {
			throw "Ez a bejegyzes mar benne van a telefonkonyvben!";
		}
		akt = akt->getKov();
	}


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

/*
//A verzio
void Telefonkonyv::beolvas(std::istream& is) {
	Bejegyzes* uj;
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
			uj = new Munkatars(veznev, kernev, temp);

			if (elso == nullptr)
				elso = uj;
			else {
				akt->setKov(uj);
			}
			akt = akt->getKov();
			is.putback(space);
		}
		else {
			is.putback(c);
			temp2.beolvas(is);

			uj = new Barat(veznev, kernev, temp, temp2);

			if (elso == nullptr)
				elso = uj;
			else {
				akt->setKov(uj);
			}

			akt = akt->getKov();

		}
		is >> space;

	}

}*/


//B verzio Mukodik!
void Telefonkonyv::beolvas(std::istream& is) {
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
			akt = new Munkatars(veznev, kernev, temp);

			if (elso == nullptr)
				elso = akt;
			else {
				Bejegyzes* mozgo = elso;
				while (mozgo->getKov() != nullptr)
					mozgo = mozgo->getKov();
				mozgo->setKov(akt);
			}
			akt = akt->getKov();
			is.putback(space);
		}
		else {
			is.putback(c);
			temp2.beolvas(is);

			akt = new Barat(veznev, kernev, temp, temp2);
			if (elso == nullptr) 
				elso = akt;
			else {
				Bejegyzes* mozgo = elso;
				while (mozgo->getKov() != nullptr)
					mozgo = mozgo->getKov();
				mozgo->setKov(akt);
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