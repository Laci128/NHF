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



void Telefonkonyv::beolvas(std::istream& is){
	Bejegyzes uj;
	String temp;
	String temp2;
	char space;
	char c;
	char fajl_vege_e;

	while (is >> c && is >> fajl_vege_e) {
		is.putback(fajl_vege_e);
		is.putback(c);
		uj.beolvas(is);
		temp.beolvas(is);
		is >> space;
		is >> c;
		if (c == '\n') {
			Munkatars ujMunkatars(uj.getVeznev(), uj.getKernev(), temp);
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
			Barat ujBarat(uj.getVeznev(), uj.getKernev(), temp, temp2);
			ujBarat.setKov(nullptr);
			akt = &ujBarat;
			if (elso == nullptr) {
				elso = akt;
				elso->kiir(std::cout);
				std::cout << std::endl;
			}
			akt = akt->getKov();
			
			elso->kiir(std::cout);
			std::cout << std::endl;
			std::cout << "Itt meg jo Barat" << std::endl;
		}
		is >> space;

		
		elso->kiir(std::cout);
		std::cout << std::endl; 
		std::cout << "Itt meg jo" <<std::endl;

	} 

	elso->kiir(std::cout);

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