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
	/*size_t db;               ///Bejegyzesek jelenlegi szama
	Bejegyzes** bejegyzesek;   ///Bejegyzesek dinamikus tombje*/
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
	void torol(Bejegyzes const& torlendo);

	///Hozzaadja a hozzaadando Bejegyzest a Telefonkonyvbe  
	void hozzaad(Bejegyzes const& hozzaadando);
	
	///Kikeres egy Bejegyzest a Telefonkonyvbol egy megadott adat alapjan
	template <class Funktor>
	Bejegyzes* kereses(String const& adat, Funktor fun) {
		akt = elso;
		while (akt != NULL) {
			fun(*akt, adat);
			akt = akt->kov;
		}
		return NULL;
	}


	void kiir(std::ostream os) const;

	void beolvas(std::istream& is) ;

};

bool keres_barat(Bejegyzes* megnezendo, String const& adat) {
	
}

bool keres_munkatars(Bejegyzes* megnezendo, String const& adat) {

}


#endif

