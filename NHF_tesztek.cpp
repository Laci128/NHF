#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>

#include "Szerializal.h"
#include "String.h"
#include "Bejegyzes.h"
#include "Telefonkonyv.h"
#include "memtrace.h"


int main(void) {	
	
	int Osszes_teszt = 0;
	int Hibas_teszt = 0;

//#if 0
	
	String vez1 = "Szabo";
	String ker1 = "Tibor";
	String munktel1 = "06201548236";
	Munkatars Szabo(vez1, ker1, munktel1);

	String vez2 = "Meszaros";
	String ker2 = "Laszlo";
	String nick1 = "Laci";
	String privtel1 = "+36301234567";
	Barat Laci(vez2, ker2, nick1, privtel1);

	String vez3 = "Halasi";
	String ker3 = "Peter";
	String nick2 = "Peti";
	String privtel2 = "06304561237";
	Barat Peti(vez3, ker3, nick2, privtel2);
	
#if 0
	Telefonkonyv T1;
	Telefonkonyv T2;

	std::ifstream olvasott_fajl;
	olvasott_fajl.open("Test_beolvas.txt");
	T1.beolvas(olvasott_fajl);
	olvasott_fajl.close();


	Bejegyzes* talalat = T1.keres(nick2);
	talalat->kiir(std::cout);

	T1.torol_mind();

	
	T1.kiir(std::cout);
	std::cout << std::endl;
	T1.hozzaad(Szabo);
	T1.kiir(std::cout);
	
	T2.hozzaad(Szabo);
	T2.kiir(std::cout);
	std::cout << std::endl;
	T2.hozzaad(Peti);
	T2.kiir(std::cout);

	
#endif

#if 0
	Bejegyzes* barat1 = &Laci;
	Bejegyzes* barat2 = &Peti;

	barat1->kiir(std::cout);
	barat2->kiir(std::cout);

	*barat1 = *barat2;

	std::cout << std::endl;
	barat1->kiir(std::cout);
	barat2->kiir(std::cout);
#endif


#if 0
	std::cout << "Torles elott:" << std::endl;
	T1.kiir(std::cout);
	T1.torol_mind();
	std::cout << "Torles utan:" << std::endl;
	try
	{
		T1.kiir(std::cout);
	}
	catch (const char* hiba)
	{
		std::cerr << hiba << std::endl;
	}
#endif

#if 0
	T2 = T1;
	std::cout << "T1:"<< std::endl;
	T1.kiir(std::cout);
	std::cout << "T2:"<< std::endl;
	T2.kiir(std::cout);
	std::cout << std::endl;
	std::cout << std::endl;

	T2.hozzaad(Szabo);

	T1.kiir(std::cout);
	std::cout << std::endl;
	T2.kiir(std::cout);
	std::cout << std::endl;
	std::cout << std::endl;


	T2.torol(Peti);
	T1.kiir(std::cout);
	std::cout << std::endl;
	T2.kiir(std::cout);
#endif

#if 0
	try
	{
		T1.hozzaad(Szabo);
		//T1.hozzaad(Laci);
		
	}
	catch (const char* hiba)
	{
		std::cerr << hiba << std::endl;
	}
	
	try
	{
		T1.torol(Laci);  //< elejerol torol
		T1.torol(Peti);   //< belsejebol torol
		T1.torol(Szabo);  //< vegerol torol
	}
	catch (const char* hiba)
	{
		std::cerr << hiba << std::endl;

	}

	T1.kiir(std::cout);

	
	std::ofstream irando_fajl;
	irando_fajl.open("Test_kiir.txt");
	T1.kiir(irando_fajl);
	irando_fajl.close();
	
#endif


	std::cout << "Hibas tesztek/Osszes teszt: " << Hibas_teszt << "/" << Osszes_teszt << std::endl;

	if (Hibas_teszt == 0)
		std::cout << "\nAz osszes teszt hibatlan!" << std::endl;


	return 0;
}