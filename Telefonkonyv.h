#ifndef TELEFONKONYV_H
#define TELEFONKONYV_H

#include <iostream>
#include <algorithm>

#include "Szerializal.h"
#include "String.h"
#include "Bejegyzes.h"

class Telefonkonyv : public Szerializal
{
private:
	Bejegyzes* elso;           ///a Telefonkonyv 
	Bejegyzes* akt;

public:
	///Konstruktor
	Telefonkonyv()
		: elso(NULL), akt(NULL)
	{
		akt = elso;
	}

	///Masolo konstruktor
	Telefonkonyv(Telefonkonyv const& rhs);

	///Ertekado operator
	Telefonkonyv const& operator=(Telefonkonyv const& rhs);

	///Destruktor
	~Telefonkonyv() {
		
	};

	///Kitorli a torlendo Bejegyzest a Telefonkonyvbol
	///**Felbehagytam**
	void torol(Bejegyzes& torlendo) {
		if(*elso == torlendo)
		
		
		
		akt = elso;
		Bejegyzes* lemarado = elso;
		while (!(*akt == torlendo)) {
			akt = akt->getKov();
		}

	}

	///Hozzaadja a hozzaadando Bejegyzest a Telefonkonyvbe  
	void hozzaad(Bejegyzes const& hozzaadando) {
		while (akt != NULL){
			akt = akt->getKov();
		}
		*akt = hozzaadando;
	}
	
	///Kikeres egy Bejegyzest a Telefonkonyvbol egy megadott adat alapjan
	
	template <class Funktor>
	Bejegyzes* kereses(String const& adat, Funktor fun) {
		akt = elso;
		while (akt != NULL) {
			fun(*akt, adat);
			akt = akt->getKov();
		}
		return NULL;
	}
	

	void kiir(std::ostream& os, char szep = '\n') const {
		Bejegyzes* mozgo = elso;
		while (mozgo != NULL) {
			mozgo->kiir(os);
		}

	}

	void beolvas(std::istream& is);

};





#endif

