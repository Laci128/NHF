#ifndef TELEFONKONYV_H
#define TELEFONKONYV_H

#include <iostream>
#include <algorithm>

#include "Szerializal.h"
#include "String.h"
#include "Bejegyzes.h"

#ifdef _MSC_VER
// MSC ne adjon figyelmeztető üzenetet a stringkezelő függvényekre.
#define _CRT_SECURE_NO_WARNINGS
#endif


class Telefonkonyv : public Szerializal
{
private:
	Bejegyzes *elso; ///a Telefonkonyv
	Bejegyzes *akt;
	Bejegyzes *utolso;

public:
	///Konstruktor
	Telefonkonyv()
	{
		elso = akt = new Bejegyzes;
	}

	///Masolo konstruktor
	Telefonkonyv(Telefonkonyv const &rhs);

	///Ertekado operator
	Telefonkonyv const &operator=(Telefonkonyv const &rhs);

	///Destruktor
	~Telefonkonyv()
	{
		delete elso;
		delete akt;
		elso = akt = NULL;
	};

	///Kitorli a torlendo Bejegyzest a Telefonkonyvbol
	void torol(Bejegyzes &torlendo);
		

	///Hozzaadja a hozzaadando Bejegyzest a Telefonkonyvbe
	void hozzaad(Bejegyzes const& hozzaadando);
	

	///Kikeres egy Bejegyzest a Telefonkonyvbol egy megadott adat alapjan
	//Nem jo???
	//template <class Funktor>
	//Bejegyzes* kereses(String const& adat, Funktor fun);
	/*{
		akt = elso;
		while (akt != NULL)
		{
			fun(*akt, adat);
			akt = akt->getKov();
		}
		return NULL;
	}*/

	void kiir(std::ostream& os) const;
	void beolvas(std::istream& is);

	// megkeresi az első találatot a telefonkönyvben
	Bejegyzes* find(const String keresendo);
	
	//megkeresi az összes találatot a telefonkönyben és egy újba fűzi
	//lehet használni rajta a kiíratást
	Telefonkonyv findAll(const String keresendo);

};

#endif

