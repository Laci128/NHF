#define _CRT_SECURE_NO_WARNINGS

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
	Bejegyzes *elso; ///<
	Bejegyzes *akt;

public:
	///Konstruktor
	Telefonkonyv()
	{	
		elso = akt = nullptr;
	}

	///Masolo konstruktor
	Telefonkonyv(Telefonkonyv const& rhs) { *this = rhs; }

	///Ertekado operator
	Telefonkonyv const& operator=(Telefonkonyv const& rhs);
	

	///Destruktor
	~Telefonkonyv()
	{
		delete elso;
		delete akt;
		elso = akt = nullptr;
	};

	///Kitorli a torlendo Bejegyzest a Telefonkonyvbol
	void torol(Bejegyzes const& torlendo);
		

	///Hozzaadja a hozzaadando Bejegyzest a Telefonkonyvbe
	void hozzaad(Bejegyzes& hozzaadando);
	

	void kiir(std::ostream& os) const;
	void beolvas(std::istream& is);


	// megkeresi az első találatot a telefonkönyvben
	Bejegyzes* keres(String const& keresendo);
	
	//megkeresi az összes találatot a telefonkönyben és egy újba fűzi
	//lehet használni rajta a kiíratást
	Telefonkonyv keres_mind(String const& keresendo);

};

#endif

