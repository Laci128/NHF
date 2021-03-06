#define _CRT_SECURE_NO_WARNINGS

#ifndef TELEFONKONYV_H
#define TELEFONKONYV_H

#include <iostream>
#include <algorithm>

#include "Szerializal.h"
#include "String.hpp"
#include "Bejegyzes.h"
#include "memtrace.h"

#include <typeinfo>

/// Osztaly ami lancolt listaban tarol
/// Bejegyzes pointereket
class Telefonkonyv : public Szerializal
{
private:
	Bejegyzes *elso; ///< Pointer az elso elemre
	Bejegyzes *akt; //< Pointer az aktualis elemre (fuggvenyeknel kell)

public:
	///Konstruktor
	Telefonkonyv()
	{	
		elso = akt = nullptr;
	}

	///Masolo konstruktor
	Telefonkonyv(Telefonkonyv const& rhs) { *this = rhs; }


	///Ertekado operator
	Telefonkonyv& operator=(Telefonkonyv const& rhs);

	//Osszehasonlito operator
	bool operator==(Telefonkonyv const& rhs);
	

	///Destruktor
	~Telefonkonyv() {
		torol_mind();
	}

	//Minden Bejegyzest torol a Telefonkonyvbol
	void torol_mind();
	

	///Kitorli a torlendo Bejegyzest a Telefonkonyvbol
	void torol(Bejegyzes& torlendo);
		

	///Hozzaadja a hozzaadando Bejegyzest a Telefonkonyvbe
	void hozzaad(Bejegyzes& hozzaadando);
	

	void kiir(std::ostream& os) const;
	void beolvas(std::istream& is);


	//Megkeresi az elso talalatot a telefonkönyvben
	Bejegyzes* keres(String const& keresendo);
	


};

#endif

