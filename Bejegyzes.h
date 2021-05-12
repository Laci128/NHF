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

	//getter es setter fuggvenyek
	//hogy az osztalyon kivul is hozzajuk lehessen ferni
	String getVeznev() const { return vezeteknev; }
	void setVeznev(String const& vez) { vezeteknev = vez; }

	String getKernev() const { return keresztnev; }
	void setKernev(String const& ker) { keresztnev = ker; }

	Bejegyzes* getKov() const { return kov; }
	void setKov(Bejegyzes* kovetkezo) { kov = kovetkezo; }


	//Virtualisok fgv-ek a a leszarmazottaknal létrehozva
	virtual bool operator==(Bejegyzes const& rhs) = 0;

	virtual Bejegyzes& operator=(Bejegyzes const& rhs) = 0;

	//A leszarmazottak tipusanak lekerdezeshez
	//Ha Barat igazat vissza
	//Egyebkent Munkatars es hamisat
	virtual bool barat_e() = 0;


	//A leszarmazott osztalyoknal megnezi, hogy
	//Valamelyik parametere megegyezik a keresendo Stringgel
	virtual bool benne_van_e(String const& keresendo) = 0;

	
	virtual void beolvas(std::istream& is) = 0;
	virtual void kiir(std::ostream& os) const = 0;

	/// Destruktor
	virtual ~Bejegyzes() {};


};


class Munkatars: public Bejegyzes, public Szerializal {
private:
	String munkahelyi_telszam;

public:
	/// Konstruktor
	///
	Munkatars(String const& vezetek, String const& kereszt, String const& munk_tel)
		:Bejegyzes(vezetek, kereszt), munkahelyi_telszam(munk_tel)
	{}

	Munkatars()
		:Bejegyzes(), munkahelyi_telszam("")
	{}

	String getMunkTel() const { return munkahelyi_telszam; }
	void setMunkTel(String const& munktel) { munkahelyi_telszam = munktel; }


	Munkatars(Munkatars const& rhs) { *this = rhs; }

	bool operator==(Munkatars const& rhs);
	bool operator==(Bejegyzes const& rhs);

	Munkatars& operator=(Munkatars const& rhs);
	Bejegyzes& operator=(Bejegyzes const& rhs);

	bool barat_e() { return false; }

	bool benne_van_e( String const& keresendo) ;

	void kiir(std::ostream& os) const;
	void beolvas(std::istream& is);

	~Munkatars() {}

};



class Barat : public Bejegyzes, public Szerializal {
private:
	String becenev;
	String privat_telszam;

public:
	/// Konstruktor
	///
	Barat(String const& vezetek, String const& kereszt, String const& nick, String const& priv_tel)
		:Bejegyzes(vezetek, kereszt), becenev(nick), privat_telszam(priv_tel)
	{}

	Barat()
		:Bejegyzes(), becenev(""), privat_telszam("")
	{}

	String getNick() const { return becenev; }
	void setNick(String const& nick) { becenev = nick; }

	String getPrivTel() const { return privat_telszam; }
	void setPrivTel(String const& privtel) { privat_telszam = privtel; }

	Barat(Barat const& rhs) { *this = rhs; }

	bool operator==(Barat const& rhs);
	bool operator==(Bejegyzes const& rhs);

	Barat& operator=(Barat const& rhs);
	Bejegyzes& operator=(Bejegyzes const& rhs);

	bool barat_e() { return true; }

	bool benne_van_e(String const& keresendo);

	void kiir(std::ostream& os) const;
	void beolvas(std::istream& is);


	~Barat() {}


};

#endif