#define _CRT_SECURE_NO_WARNINGS

#ifndef BEJEGYZES_H
#define BEJEGYZES_H

#include <iostream>

#include "Szerializal.h"
#include "String.h"


class Bejegyzes
{
private:
	String vezeteknev;
	String keresztnev;
	Bejegyzes* kov;     //pointer a kovetkezo Bejegyzesre Telefonkonyvben

public:
	///Konstruktor
	Bejegyzes(String const& vezetek , String const& kereszt )
		:vezeteknev(vezetek), keresztnev(kereszt), kov(NULL)
	{}
	Bejegyzes()	//
		:vezeteknev(), keresztnev(), kov(NULL)
	{}
	String getVeznev() const { return vezeteknev; }
	String getKernev() const { return keresztnev; }
	Bejegyzes* getKov() const { return kov; }
	void setKov(Bejegyzes* kovetkezo) { kov = kovetkezo; }
	void beolvas(std::istream& is);
	void kiir(std::ostream& os) const;
	bool keres(String const& keresendo) ;
	//Virtualis osszehasonlito operator, hogy a leszarmazottaket megfeleloen hasznalja?
	//virtual bool operator==(Bejegyzes const& rhs) = 0;

	/// Destruktor
	virtual ~Bejegyzes() {}


};

class Barat: public Bejegyzes, public Szerializal{
private:
	String becenev;
	String privat_telszam;
	
public:
	Barat(String const& vezetek, String const& kereszt, String const& nick, String const& priv_tel)
		:Bejegyzes(vezetek, kereszt), becenev(nick), privat_telszam(priv_tel)
	{}


	bool operator==(Barat const& rhs) {
		return(this->becenev == rhs.becenev && this->privat_telszam == rhs.privat_telszam && this->getVeznev() == rhs.getVeznev() && this->getKernev() == rhs.getKernev());
	}


	bool keres( String const& keresendo) ;


	void kiir(std::ostream& os) const;

	void beolvas(std::istream& is);




	~Barat() {}


};

class Munkatars: public Bejegyzes, public Szerializal {
private:
	String munkahelyi_telszam;

public:
	Munkatars(String const& vezetek, String const& kereszt, String const& munk_tel)
		:Bejegyzes(vezetek, kereszt), munkahelyi_telszam(munk_tel)
	{}

	bool operator==(Munkatars const& rhs) {
		return(this->munkahelyi_telszam == rhs.munkahelyi_telszam && this->getVeznev() == rhs.getVeznev() && this->getKernev() == rhs.getKernev());
	}


	
	bool keres( String const& keresendo) ;

	
	void kiir(std::ostream& os) const;

	void beolvas(std::istream& is);

	~Munkatars() {}

};

#endif