#ifndef BEJEGYZES_H
#define BEJEGYZES_H

#include <iostream>

#include "Szerializal.h"
#include "String.h"

class Bejegyzes : public Szerializal
{
private:
	String vezeteknev;
	String keresztnev;
	Bejegyzes* kov;       //pointer a kovetkezo Bejegyzesre Telefonkonyvben

public:
	///Konstruktor
	Bejegyzes(String const& vezetek, String const& kereszt)
		:vezeteknev(vezetek), keresztnev(kereszt), kov(NULL)
	{}

	/// Destruktor
	virtual ~Bejegyzes() {}


};

class Barat: public Bejegyzes {
private:
	String becenev;
	String privat_telszam;
	
public:
	Barat(String const& vezetek, String const& kereszt, String const& nick, String const& priv_tel)
		:Bejegyzes(vezetek, kereszt), becenev(nick), privat_telszam(priv_tel)
	{}


	void kiir(std::ostream os) const;

	void beolvas(std::istream& is);

	~Barat() {}


};

class Munkatars: public Bejegyzes {
private:
	String munkahelyi_telszam;

public:
	Munkatars(String const& vezetek, String const& kereszt, String const& munk_tel)
		:Bejegyzes(vezetek, kereszt), munkahelyi_telszam(munk_tel)
	{}


	void kiir(std::ostream os) const;

	void beolvas(std::istream& is);

	~Munkatars() {}

};

#endif