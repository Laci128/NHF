#define _CRT_SECURE_NO_WARNINGS

#include "Telefonkonyv.h"
#include "memtrace.h"


Telefonkonyv& Telefonkonyv::operator=(Telefonkonyv const& rhs) {
	if (rhs.elso == nullptr) {
		this->torol_mind();
		return *this;
	}

	if (rhs.elso->barat_e())
		elso = new Barat;
	else
		elso = new Munkatars;
	
	*elso = *rhs.elso;

	Bejegyzes* temp;
	akt = elso;
	Bejegyzes* rhs_mozgo = rhs.elso->getKov();

	while (rhs_mozgo != nullptr) {
		if (rhs_mozgo->barat_e()) 
			temp = new Barat;
		else
			temp = new Munkatars;
		
		*temp = *rhs_mozgo;
		akt->setKov(temp);
		akt = akt->getKov();
		rhs_mozgo = rhs_mozgo->getKov();
	}

	return *this;
}

bool Telefonkonyv::operator==(Telefonkonyv const& rhs) {
	akt = elso;
	Bejegyzes* mozgo_rhs = rhs.elso;

	while (mozgo_rhs != nullptr && akt !=nullptr){
		if (!(*akt == *mozgo_rhs))
			return false;
		akt = akt->getKov();
		mozgo_rhs = mozgo_rhs->getKov();
	}
	if (mozgo_rhs == nullptr && akt == nullptr)
		return true;
	else
		return false;
}



//torol_mind
void Telefonkonyv::torol_mind() {
	if (elso == nullptr)
		return;
	else {
		akt = elso;
		while (akt != nullptr) {
			Bejegyzes* temp = akt->getKov();
			delete akt;
			akt = temp;
		}
		elso = akt = nullptr;
	}
	
}


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
		if (*akt == torlendo) {
			lemarado->setKov(akt->getKov());
			delete akt;
			akt = lemarado;
			return;
		}
	}
	
	throw "Nincs ilyen bejegyzes a telefonkonyvben!";

}


void Telefonkonyv::hozzaad(Bejegyzes& hozzaadando) {
	
	
	if (elso == nullptr) {    //< Ha ures a Telefonkonyv
		if (hozzaadando.barat_e()) {
			elso = new Barat;
		}
		else {
			elso = new Munkatars;
		}
		*elso = hozzaadando;
		return;
	}

	akt = elso;
	while (akt != nullptr) {	//< Megnezzuk hogy benne van-e mar
		if (*akt == hozzaadando) {
			throw "Ez a bejegyzes mar benne van a telefonkonyvben!";
		}
		akt = akt->getKov();
	}

	akt = elso;
	while (akt->getKov() != nullptr) //< Elmegyunk az utolso elemig
	{
		akt = akt->getKov();
	}

	Bejegyzes* temp;
	if (hozzaadando.barat_e())
		temp = new Barat;
	else
		temp = new Munkatars;

	*temp = hozzaadando;
	akt->setKov(temp);
	akt = elso;
}


void Telefonkonyv::kiir(std::ostream& os) const {
	if (elso == nullptr) {
		throw "A Telefonkonyv ures, nincs mit kiirni!";
	}
	Bejegyzes* mozgo = elso;
	while (mozgo != nullptr)
	{
		mozgo->kiir(os);
		os << '\n';
		mozgo = mozgo->getKov();
	}
}


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


Bejegyzes* Telefonkonyv::keres(String const& keresendo) {
	Bejegyzes* tmp = elso;
	while (tmp != nullptr)
	{
		if (tmp->benne_van_e(keresendo))
			return tmp;
		tmp = tmp->getKov();
	}

	return nullptr;
}

