#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <fstream>

#include "Szerializal.h"
#include "String.hpp"
#include "Bejegyzes.h"
#include "Telefonkonyv.h"
#include "memtrace.h"


int main(void) {	
	
	int Osszes_teszt = 37;
	int Hibas_teszt = 0;
	
	String vez1 = "Szabo";
	String ker1 = "Tibor";
	String munktel1 = "06201548236";

	String vez2 = "Meszaros";
	String ker2 = "Laszlo";
	String nick1 = "Laci";
	String privtel1 = "+36301234567";

	//Konstruktor tesztek
	//Teszt 1a
	Munkatars Szabo(vez1, ker1, munktel1);

	if (Szabo.getVeznev() != vez1 || Szabo.getKernev() != ker1 || Szabo.getMunkTel() != munktel1) {
		Hibas_teszt++;
		std::cout << "Hibas a Munkatars kontruktora!" << std::endl;
	}
	else
		std::cout << "Jo a Munkatars konstruktora" << std::endl;

	//Teszt 1b
	Barat Laci(vez2, ker2, nick1, privtel1);

	if (Laci.getVeznev() != vez2 || Laci.getKernev() != ker2 || Laci.getNick() != nick1 || Laci.getPrivTel() != privtel1 ) {
		Hibas_teszt++;
		std::cout << "Hibas a Barat kontruktora!\n" << std::endl;
	}
	else
		std::cout << "Jo a Barat konstruktora\n" << std::endl;
	


	//Parameternelkuli konstruktor tesztek
	//Teszt 2a
	Munkatars Szabo2;
	if (Szabo2.getVeznev() != "" || Szabo2.getKernev() != "" || Szabo2.getMunkTel() != "") {
		Hibas_teszt++;
		std::cout << "Hibas a Munkatars parameternelkuli kontruktora!" << std::endl;
	}
	else
		std::cout << "Jo a Munkatars parameternelkuli konstruktora" << std::endl;
		
	//Teszt 2b
	Barat Laci2;
	if (Laci2.getVeznev() != "" || Laci2.getKernev() != "" || Laci2.getNick() != "" || Laci2.getPrivTel() != "") {
		Hibas_teszt++;
		std::cout << "Hibas a Barat parameternelkuli kontruktora!\n" << std::endl;
	}
	else
		std::cout << "Jo a Barat parameternelkuli konstruktora\n" << std::endl;



	//Setter tesztek 
	//Teszt 3a
	Szabo2.setVeznev(vez1);
	Szabo2.setKernev(ker1);
	Szabo2.setMunkTel(munktel1);
	if (Szabo2.getVeznev() != vez1 || Szabo2.getKernev() != ker1 || Szabo2.getMunkTel() != munktel1) {
		Hibas_teszt++;
		std::cout << "Hibas a Munkatars valamelyik set fuggvenye!" << std::endl;
	}
	else
		std::cout << "Jok a Munkatars set fuggvenyei" << std::endl;
	
	//Teszt 3b
	Laci2.setVeznev(vez2);
	Laci2.setKernev(ker2);
	Laci2.setNick(nick1);
	Laci2.setPrivTel(privtel1);
	if (Laci2.getVeznev() != vez2 || Laci2.getKernev() != ker2 || Laci2.getNick() != nick1 || Laci2.getPrivTel() != privtel1) {
		Hibas_teszt++;
		std::cout << "Hibas a Barat valamelyik set fuggvenye!" << std::endl;
	}
	else
		std::cout << "Jok a Barat set fuggvenyei" << std::endl;

	//Teszt 3c
	Szabo2.setKov(&Laci2);
	if (Szabo2.getKov()->getVeznev() != Laci2.getVeznev() || Szabo2.getKov()->getKernev() != Laci2.getKernev()) {
		Hibas_teszt++;
		std::cout << "Hibas a Bejegyzes setKov fuggvenye!\n" << std::endl;
	}
	else
		std::cout << "Jo a Bejegyzes setKov fuggvenye\n" << std::endl;



	//Osszehasonlito operator tesztek
	//Teszt 4a
	if (((Szabo == Szabo2)) != (Szabo.getVeznev() == Szabo2.getVeznev() && Szabo.getKernev() == Szabo2.getKernev() && Szabo.getMunkTel() == Szabo2.getMunkTel())) {
		Hibas_teszt++;
		std::cout << "Hibas a Munkatars osszehasonlito operatora!" << std::endl;
	}
	else
		std::cout << "Jo a Munkatars osszehasonlito operatora" << std::endl;

	//Teszt 4b
	if ((Laci == Laci2) != (Laci.getVeznev() == Laci2.getVeznev() && Laci.getKernev() == Laci2.getKernev() && Laci.getNick() == Laci2.getNick() && Laci.getPrivTel() == Laci2.getPrivTel())) {
		Hibas_teszt++;
		std::cout << "Hibas a Barat osszehasonlito operatora!" << std::endl;
	}
	else
		std::cout << "Jo a Barat osszehasonlito operatora" << std::endl;
	
	//Teszt 4c
	Bejegyzes* Bej_Szabo = &Szabo;
	Bejegyzes* Bej_Szabo2 = &Szabo2;
	if (((*Bej_Szabo == *Bej_Szabo2)) != (Bej_Szabo->getVeznev() == Bej_Szabo2->getVeznev() && Bej_Szabo->getKernev() == Bej_Szabo2->getKernev())) {
		Hibas_teszt++;
		std::cout << "Hibas a Munkatars Bejegyzeses osszehasonlito operatora!" << std::endl;
	}
	else
		std::cout << "Jo a Munkatars Bejegyzeses osszehasonlito operatora" << std::endl;

	//Teszt 4d
	Bejegyzes* Bej_Laci = &Laci;
	Bejegyzes* Bej_Laci2 = &Laci2;
	if ((*Bej_Laci == *Bej_Laci2) != (Bej_Laci->getVeznev() == Bej_Laci2->getVeznev() && Bej_Laci->getKernev() == Bej_Laci2->getKernev())){
		Hibas_teszt++;
		std::cout << "Hibas a Barat Bejegyzeses osszehasonlito operatora!\n" << std::endl;
	}
	else
		std::cout << "Jo a Barat Bejegyzeses osszehasonlito operatora\n" << std::endl;


	//Masolo kontstruktor tesztek
	//Teszt 5a
	Munkatars Szabo3(Szabo);
	if (!(Szabo == Szabo3)) {
		Hibas_teszt++;
		std::cout << "Hibas a Munkatars masolo kontruktora!" << std::endl;
	}
	else
		std::cout << "Jo a Munkatars masolo konstruktora" << std::endl;
		
	//Teszt 5b
	Barat Laci3(Laci);
	if (!(Laci == Laci3)) {
		Hibas_teszt++;
		std::cout << "Hibas a Barat masolo kontruktora!\n" << std::endl;
	}
	else
		std::cout << "Jo a Barat masolo konstruktora\n" << std::endl;



	//Ertekado operator tesztek
	//Teszt 6a
	Munkatars Szabo4;
	Szabo4 = Szabo;
	if (!(Szabo == Szabo4)) {
		Hibas_teszt++;
		std::cout << "Hibas a Munkatars ertekado operatora!" << std::endl;
	}
	else
		std::cout << "Jo a Munkatars ertekado operatora" << std::endl;

	//Teszt 6b
	Barat Laci4;
	Laci4 = Laci;
	if (!(Laci == Laci4)) {
		Hibas_teszt++;
		std::cout << "Hibas a Barat ertekado operatora!" << std::endl;
	}
	else
		std::cout << "Jo a Barat ertekado operatora" << std::endl;

	//Teszt 6c
	Munkatars Szabo5;
	Bejegyzes* Bej_Szabo5 = &Szabo5;
	*Bej_Szabo5 = *Bej_Szabo;
	if (!(*Bej_Szabo == *Bej_Szabo5)) {
		Hibas_teszt++;
		std::cout << "Hibas a Munkatars Bejegyzeses ertekado operatora!" << std::endl;
	}
	else {
	try {
		*Bej_Szabo = *Bej_Laci;
	}
	catch (const char* hiba) {
		std::cout << hiba << std::endl;
		std::cout << "Jo a Munkatars Bejegyzeses ertekado operatora" << std::endl;
	}
	}
	//Teszt 6d
	Barat Laci5;
	Bejegyzes* Bej_Laci5 = &Laci5;
	*Bej_Laci5 = *Bej_Laci;
	if(!(*Bej_Laci == *Bej_Laci5)){
		Hibas_teszt++;
		std::cout << "Hibas a Barat Bejegyzeses ertekado operatora!\n" << std::endl;
	}
	else {
		try {
			*Bej_Laci = *Bej_Szabo;
		}
		catch (const char* hiba){
			std::cout << hiba << std::endl;
			std::cout << "Jo a Barat Bejegyzeses ertekado operatora\n" << std::endl;
		}
	}



	//barat_e fuggveny tesztek
	//Teszt 7a
	Bejegyzes* bejegyzes = &Szabo;
	if ((bejegyzes->barat_e()) == true) {
		Hibas_teszt++;
		std::cout << "Hibas a Munkatars barat_e fuggvenye!" << std::endl;
	}
	else
		std::cout << "Jo a Munkatars barat_e fuggvenye" << std::endl;

	//Teszt 7b
	bejegyzes = &Laci;
	if ((bejegyzes->barat_e()) == false) {
		Hibas_teszt++;
		std::cout << "Hibas a Barat barat_e fuggvenye!\n" << std::endl;
	}
	else
		std::cout << "Jo a Barat barat_e fuggvenye\n" << std::endl;



	//benne_van_e fuggveny tesztek
	//Teszt 8a
	bejegyzes = &Szabo;
	if(bejegyzes->benne_van_e(vez1) == false){
		Hibas_teszt++;
		std::cout << "Hibas a Munkatars benne_van_e fuggvenye!" << std::endl;
	}
	else
		std::cout << "Jo a Munkatars benne_van_e fuggvenye" << std::endl;

	//Teszt 8b
	bejegyzes = &Laci;
	if ((bejegyzes->benne_van_e(vez2)) == false) {
		Hibas_teszt++;
		std::cout << "Hibas a Barat benne_van_e fuggvenye!\n" << std::endl;
	}
	else
		std::cout << "Jo a Barat benne_van_e fuggvenye\n" << std::endl;



	//String kiir/beolvas tesztje
	//Teszt 9a
	String Alma = "Alma";
	std::cout << "\tA vart szo: "<< "Alma" << std::endl;
	std::cout << "\tA kiirt szo: ";
	Alma.kiir(std::cout);
	std::cout << std::endl;

	std::ofstream string_kiir;
	string_kiir.open("Test_string_kiir.txt");
	Alma.kiir(string_kiir);
	string_kiir.close();

	String Alma2;
	std::ifstream string_kiir_teszt;
	string_kiir_teszt.open("Test_string_kiir.txt");
	Alma2.beolvas(string_kiir_teszt);
	string_kiir_teszt.close();
	if (strcmp(Alma.c_str(), Alma2.c_str()) != 0) {
		Hibas_teszt++;
		std::cout << "Hibas a String kiirasa!\n" << std::endl;
	}
	else
		std::cout << "Jo a String kiirasa!\n" << std::endl;

	//Teszt 9b
	String Korte;
	std::ifstream string_beolvas;
	string_beolvas.open("Test_string_beolvas.txt");
	Korte.beolvas(string_beolvas);
	string_beolvas.close();

	std::cout << "\tA vart szo: " << "Korte" << std::endl;
	std::cout << "\tA beolvasott szo: ";
	Korte.kiir(std::cout);
	std::cout << std::endl;

	if (strcmp("Korte", Korte.c_str()) != 0) {
		Hibas_teszt++;
		std::cout << "Hibas a String beolvasasa!\n" << std::endl;
	}
	else
		std::cout << "Jo a String beolvasasa!\n" << std::endl;



	//A Munkatars beolvas/kiir tesztje
	//Teszt 10a
	Munkatars Szabo_beolvasott;
	std::ifstream munkatars_beolvas;
	munkatars_beolvas.open("Test_munkatars_beolvas.txt");
	Szabo_beolvasott.beolvas(munkatars_beolvas);
	munkatars_beolvas.close();
	if (!(Szabo == Szabo_beolvasott)) {
		Hibas_teszt++;
		std::cout << "Hibas a Munkatars beolvasasa!" << std::endl;
	}
	else
		std::cout << "Jo a Munkatars beolvasasa" << std::endl;

	//Teszt 10b
	Munkatars Szabo_kiirando = Szabo;

	std::ofstream munkatars_kiir;
	munkatars_kiir.open("Test_munkatars_kiir.txt");
	Szabo_kiirando.kiir(munkatars_kiir);
	munkatars_kiir.close();

	std::ifstream munkatars_kiir_teszt;
	munkatars_kiir_teszt.open("Test_munkatars_kiir.txt");
	Szabo_beolvasott.beolvas(munkatars_kiir_teszt);
	munkatars_kiir_teszt.close();
	if (!(Szabo_beolvasott == Szabo_kiirando)) {
		Hibas_teszt++;
		std::cout << "Hibas a Munkatars kiirasa!\n" << std::endl;
	}
	else
		std::cout << "Jo a Munkatars kiirasa\n" << std::endl;



	//Barat beolvas/kiir tesztje
	//Teszt 11a
	Barat Laci_beolvasott;
	std::ifstream barat_beolvas;
	barat_beolvas.open("Test_barat_beolvas.txt");
	Laci_beolvasott.beolvas(barat_beolvas);
	barat_beolvas.close();
	if (!(Laci == Laci_beolvasott)) {
		Hibas_teszt++;
		std::cout << "Hibas a Barat beolvasasa!" << std::endl;
	}
	else
		std::cout << "Jo a Barat beolvasasa" << std::endl;
	
	//Teszt 11b
	Barat Laci_kiirando = Laci;

	std::ofstream barat_kiir;
	barat_kiir.open("Test_barat_kiir.txt");
	Laci_kiirando.kiir(barat_kiir);
	barat_kiir.close();

	std::ifstream barat_kiir_teszt;
	barat_kiir_teszt.open("Test_barat_kiir.txt");
	Laci_beolvasott.beolvas(barat_kiir_teszt);
	barat_kiir_teszt.close();
	if (!(Laci_beolvasott == Laci_kiirando)) {
		Hibas_teszt++;
		std::cout << "Hibas a Barat kiirasa!\n" << std::endl;
	}
	else
		std::cout << "Jo a Barat kiirasa\n" << std::endl;



	//Telefonkonyv osszehasonlito operator tesztje
	//Teszt 12
	Telefonkonyv T4;
	Telefonkonyv T5;
	T4.hozzaad(Laci);
	T4.hozzaad(Szabo);
	T5.hozzaad(Laci);
	T5.hozzaad(Szabo);
	if (!(T4 == T5)) {
		Hibas_teszt++;
		std::cout << "Hibas a Telefonkonyv osszehasonlito operatora!\n" << std::endl;
	}
	else
		std::cout << "Jo a Telefonkonyv osszehasonlito operatora\n" << std::endl;

	
	//Telefonkonyv ertekado operator tesztje
	//Teszt 13
	Telefonkonyv T6;
	
	Telefonkonyv ures_lesz;
	Telefonkonyv ures;
	
	ures_lesz = ures;
		
	T6 = T4;

	if (!(T4 == T6) && !(ures_lesz == ures)) {
		Hibas_teszt++;
		std::cout << "Hibas a Telefonkonyv ertekado operatora!\n" << std::endl;
	}
	else
		std::cout << "Jo a Telefonkonyv ertekado operatora\n" << std::endl;


	//Telefonkonyv masolo konstruktor tesztje
	//Teszt 14
	Telefonkonyv T7(T4);
	if (!(T4 == T7)) {
		Hibas_teszt++;
		std::cout << "Hibas a Telefonkonyv masolo konstruktora!\n" << std::endl;
	}
	else
		std::cout << "Jo a Telefonkonyv masolo konstruktora\n" << std::endl;


	//Telefonkonyv kiir es beolvas tesztje
	//Teszt 15a
	Telefonkonyv T1;
	
	std::ifstream telefonkonyv_olvasas;
	telefonkonyv_olvasas.open("Test_telefonkonyv_beolvas.txt");
	T1.beolvas(telefonkonyv_olvasas);
	telefonkonyv_olvasas.close();
	
	
	std::cout << "****A beolvasando txt tartalma****\n"
		<< "Meszaros Laszlo Laci +36301234567 \n"
		<< "Nagy Istvan 06209876543 \n"
		<< "Halasi Peter Peti 06304561237 \n";
	
	std::cout << "****A beolvasott szoveg****" << std::endl;
	T1.kiir(std::cout);

	//Ellenorizzuk a belolvasast
	Telefonkonyv T2;
	T2.hozzaad(Laci);

	String vez3 = "Nagy";
	String ker3 = "Istvan";
	String munktel2 = "06209876543";
	Munkatars Nagy(vez3, ker3, munktel2);
	T2.hozzaad(Nagy);

	String vez4 = "Halasi";
	String ker4 = "Peter";
	String nick2 = "Peti";
	String privtel2 = "06304561237";
	Barat Peti(vez4, ker4, nick2, privtel2);
	T2.hozzaad(Peti);
	
	if (!(T1 == T2)) {
		Hibas_teszt++;
		std::cout << "\nHibas a Telefonkonyv beolvasasa!\n" << std::endl;
	}
	else
		std::cout << "\nJo a Telefonkonyv beolvasasa\n" << std::endl;

	//Teszt 15b
	Telefonkonyv ures2;
	try {
		ures2.kiir(std::cout);
	}
	catch (const char* hiba) {
		std::cout << hiba << std::endl;
	}



	std::ofstream telefonkonyv_kiir;
	telefonkonyv_kiir.open("Test_telefonkonyv_kiir.txt");
	T2.kiir(telefonkonyv_kiir);
	telefonkonyv_kiir.close();

	Telefonkonyv T3;
	std::ifstream telefonkonyv_kiir_teszt;
	telefonkonyv_kiir_teszt.open("Test_telefonkonyv_kiir.txt");
	T3.beolvas(telefonkonyv_kiir_teszt);
	telefonkonyv_kiir_teszt.close();

	if (!(T3 == T2)) {
		Hibas_teszt++;
		std::cout << "Hibas a Telefonkonyv kiirasa!\n" << std::endl;
	}
	else
		std::cout << "Jo a Telefonkonyv kiirasa\n" << std::endl;


	//Telefonkonyv hozzaad tesztje
	//Teszt 16
	Telefonkonyv T8;
	Telefonkonyv T9;

	T8.hozzaad(Laci);
	T9.hozzaad(Laci);
	T8.hozzaad(Szabo);
	T9.hozzaad(Szabo);
	
	if (T8 == T9) {
		T9.hozzaad(Peti);
		if (T8 == T9) {
			Hibas_teszt++;
			std::cout << "Hibas a Telefonkonyv hozzaadasa!\n" << std::endl;
		}
		else {
			try{
				T8.hozzaad(Szabo);
			}
			catch (const char* hiba)
			{
				std::cout << hiba << std::endl;		
				std::cout << "Jo a Telefonkonyv hozzaadasa\n" << std::endl;

			}
		}
	}
	else{
		Hibas_teszt++;
		std::cout << "Hibas a Telefonkonyv hozzaadasa!\n" << std::endl;
	}

	//Telefonkonyv torles tesztje
	//Teszt 17
	Telefonkonyv T10;
	T10.hozzaad(Laci);
	T10.hozzaad(Szabo);
	T10.hozzaad(Peti);

	T10.torol(Laci);
	T10.torol(Peti);

	Telefonkonyv T11;
	T11.hozzaad(Szabo);

	if (!(T10 == T11)) {
		Hibas_teszt++;
		std::cout << "Hibas a Telefonkonyv torlese!\n" << std::endl;
	}

	try{
		T10.torol(Peti);
	}
	catch (const char* hiba){
		std::cout << hiba << std::endl;
		std::cout << "Jo a Telefonkonyv torlese\n" << std::endl;
	}


	//Telefonkonyv keres tesztje

	Bejegyzes* talalat1 = T1.keres(nick2);  //< nick2 ==  Peti


	String munktel3 = "+361587425";
	Bejegyzes* talalat2 = T1.keres(munktel3);  

	if ((*talalat1 == Peti) && (talalat2 == nullptr)) 
		std::cout << "Jo a Telefonkonyv keresese\n" << std::endl;
	else {
		Hibas_teszt++;
		std::cout << "Hibas a Telefonkonyv keresese!\n" << std::endl;
	}


	std::cout << "\nHibas/Osszes teszt: " << Hibas_teszt << "/" << Osszes_teszt << std::endl;

	if (Hibas_teszt == 0)
		std::cout << "\n****Az osszes teszt hibatlan!****" << std::endl;


	return 0;
}