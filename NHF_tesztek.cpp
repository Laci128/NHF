#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>

#include "Szerializal.h"
#include "String.h"
#include "Bejegyzes.h"
#include "Telefonkonyv.h"


int main(void) 
{	
	int Osszes_teszt = 3;
	int Hibas_teszt = 0;

	String veznev = "Meszaros";
	String kernev = "Laszlo";
	String priv_tel = "06123456789";
	String mun_tel = "06987654321";
	String becenev = "Laci";

	Bejegyzes b0(veznev, kernev, priv_tel, mun_tel, becenev);

	Telefonkonyv T0;
	Telefonkonyv T1;

	///Teszt1
	T0.hozzaad(b0);
	if (T0.kereses(b0) == b0)
		std::cout << "Sikeres a bejegyzes hozzadasa.\n" << std::endl;
	else 
	{
		std::cout << "Sikertelen a bejegyzes hozzadasa.\n" << std::endl;
		Hibas_teszt++;
	}

	String veznev1 = "Joska";
	String kernev1 = "Istvan";
	String priv_tel1 = "06301234567";
	String mun_tel1 = "06207654321";
	String becenev1 = "Pista";
	Bejegyzes b1(veznev1, kernev1, priv_tel1, mun_tel1, becenev1);
	T0.hozzaad(b1);

	//Teszt2
	T0 = T1;
	if (T0.kereses(b0) == T1.kereses(b0) && T0.kereses(b1) == T1.kereses(b1))
		std::cout << "Sikeres a telefonkonyv masolasa.\n" << std::endl;
	else
	{
		std::cout << "Sikertelen a telefonkonyv masolasa.\n" << std::endl;
		Hibas_teszt++;
	}

	//Teszt3
	T0.torol(b0);
	try
	{
		b1 = T0.kereses(b0);
		if (b1 == b0) 
		{
			std::cout << "Az elvileg torolt bejegyzes sikeresen masolodott, azaz a kereses megtalalta a telefonkonyvben. A torles sikertelen\n" << std::endl;
			Hibas_teszt++;
		}
	}
	catch (const char* Error_text)
	{
		std::cout << "A kereses altal dobott hiba: " << Error_text << "\n";
		std::cout << "Azaz a kereses nem talalta a torolt elemet. Sikeres torles!\n" << std::endl;
	}

	std::cout << "Hibas tesztek/Osszes teszt: " << Hibas_teszt << "/" << Osszes_teszt << std::endl;

	if(Hibas_teszt == 0)
		std::cout << "\nHurra, az osszes teszt hibatlan!"  << std::endl;


	return 0;
}