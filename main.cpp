#include "String.h"
#include "Szerializal.h"
#include "Telefonkonyv.h"
#include "Bejegyzes.h"

#include <iostream>


int main(){

	int fomenu() {
		int menupont;

		do {
			std::cout << "~~~~~~~~~~~~TELEFONKONYV~~~~~~~~~~~~\n"
				<< "1. Bejegyzes hozzaadasa"
				<< "2. Bejegyzes torlese"
				<< "3. Bejegyzes keresese"
				<< "4. A telefonkonyv osszes bejegyzesenek kilistazasa"
				<< "0. Kilepes" << std::endl;


		} while (menupont != 0)


	}






	return 0;
}