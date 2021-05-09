#define _CRT_SECURE_NO_WARNINGS

#ifndef BEJEGYZES_H
#define BEJEGYZES_H

#include <iostream>

#include "Szerializal.h"
#include "String.hpp"
#include "memtrace.h"


class Bejegyzes 
{
private:
	String vezeteknev;
	String keresztnev;
	Bejegyzes* kov;     //pointer a kovetkezo Bejegyzesre Telefonkonyvben

public:
	/// Konstruktor
	///
	Bejegyzes(String const& vezetek , String const& kereszt )
		:vezeteknev(vezetek), keresztnev(kereszt), kov(nullptr)
	{}

	/// Parameter nelkuli konstruktor
	/// 
	Bejegyzes()
		:vezeteknev(""), keresztnev(""), kov(nullptr)
	{}


	String getVeznev() const { return vezeteknev; }
	void setVeznev(String const& vez) { vezeteknev = vez; }

	String getKernev() const { return keresztnev; }
	void setKernev(String const& ker) { keresztnev = ker; }

	Bejegyzes* getKov() const { return kov; }
	void setKov(Bejegyzes* kovetkezo) { kov = kovetkezo; }


	//Osszehasonlito operator, hogy a leszarmazottaket megfeleloen hasznalja
	virtual bool operator==(Bejegyzes const& rhs) = 0;

	virtual Bejegyzes& operator=(Bejegyzes const& rhs) = 0;
	//Bejegyzes& operator=(Bejegyzes const& rhs);

	virtual bool barat_e() = 0;

	virtual bool keres(String const& keresendo) = 0;

	virtual void beolvas(std::istream& is) = 0;
	virtual void kiir(std::ostream& os) const = 0;

	/// Destruktor
	virtual ~Bejegyzes() { delete kov; };


};

class Barat: public Bejegyzes, public Szerializal {
private:
	String becenev;
	String privat_telszam;
	
public:
	Barat(String const& vezetek, String const& kereszt, String const& nick, String const& priv_tel)
		:Bejegyzes(vezetek, kereszt), becenev(nick), privat_telszam(priv_tel)
	{}

	Barat() 
		:Bejegyzes(), becenev(""), privat_telszam("")
	{}

	
	Barat(Barat const& rhs) { *this = rhs; }

	bool operator==(Barat const& rhs);
	bool operator==(Bejegyzes const& rhs);

	Barat& operator=(Barat const& rhs);
	Bejegyzes& operator=(Bejegyzes const& rhs);

	bool barat_e() { return true; }

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

	Munkatars()
		:Bejegyzes(), munkahelyi_telszam("")
	{}

	Munkatars(Munkatars const& rhs) { *this = rhs; }

	bool operator==(Munkatars const& rhs);
	bool operator==(Bejegyzes const& rhs);

	Munkatars& operator=(Munkatars const& rhs);
	Bejegyzes& operator=(Bejegyzes const& rhs);

	bool barat_e() { return false; }

	bool keres( String const& keresendo) ;

	void kiir(std::ostream& os) const;
	void beolvas(std::istream& is);

	~Munkatars() {}

};

#endif


