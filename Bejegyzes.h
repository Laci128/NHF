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
	/// Konstruktor
	///
	Bejegyzes(String const& vezetek , String const& kereszt )
		:vezeteknev(vezetek), keresztnev(kereszt), kov(nullptr)
	{}

	/// Parameter nelkuli konstruktor
	/// 
	Bejegyzes()
		:vezeteknev(), keresztnev(), kov(nullptr)
	{}


	//Osszehasonlito operator, hogy a leszarmazottaket megfeleloen hasznalja(?)
	virtual bool operator==(Bejegyzes const& rhs) = 0;


	String getVeznev() const { return vezeteknev; }
	void setVeznev(String const& vez) { vezeteknev = vez; }

	String getKernev() const { return keresztnev; }
	void setKernev(String const& ker) { keresztnev = ker; }

	Bejegyzes* getKov() const { return kov; }
	void setKov(Bejegyzes* kovetkezo) { kov = kovetkezo; }


	//ez kell??
	virtual Bejegyzes const& operator=(Bejegyzes const& rhs) { return *this; }  

	virtual void beolvas(std::istream& is) = 0;
	virtual void kiir(std::ostream& os) const = 0;

	virtual bool keres(String const& keresendo) = 0;


	

	/// Destruktor
	virtual ~Bejegyzes() {};


};

class Barat: public Bejegyzes, public Szerializal {
private:
	String becenev;
	String privat_telszam;
	
public:
	Barat(String const& vezetek, String const& kereszt, String const& nick, String const& priv_tel)
		:Bejegyzes(vezetek, kereszt), becenev(nick), privat_telszam(priv_tel)
	{}


	bool operator==(Barat const& rhs) {
		return(becenev == rhs.becenev && privat_telszam == rhs.privat_telszam && getVeznev() == rhs.getVeznev() && getKernev() == rhs.getKernev());
	}

	bool operator==(Bejegyzes const& rhs) {
		const Barat* p = dynamic_cast<const Barat*>(&rhs);
		if (p != nullptr)
			return (*this == *p);
		else
			return false;
	}

	Barat const& operator=(Barat const& rhs);


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
		return(munkahelyi_telszam == rhs.munkahelyi_telszam && getVeznev() == rhs.getVeznev() && getKernev() == rhs.getKernev());
	}

	bool operator==(Bejegyzes const& rhs) {
		const Munkatars* p = dynamic_cast<const Munkatars*>(&rhs);
		if (p != nullptr)
			return (*this == *p);
		else
			return false;
	}


	Munkatars const& operator=(Munkatars const& rhs);

	
	bool keres( String const& keresendo) ;

	
	void kiir(std::ostream& os) const;

	void beolvas(std::istream& is);

	~Munkatars() {}

};

#endif


