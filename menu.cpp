#include "menu.h"
#include "String.h"
#include "Szerializal.h"
#include "Telefonkonyv.h"
#include "Bejegyzes.h"


#include <iostream>


void menu(Telefonkonyv const& telefonkonyv) {
	int menupont;

	do {
		std::cout << "~~~~~~~~~~~~TELEFONKONYV~~~~~~~~~~~~\n"
			<< "1. Bejegyzes hozzaadasa"
			<< "2. Bejegyzes torlese"
			<< "3. Bejegyzes keresese"
			<< "4. A telefonkonyv osszes bejegyzesenek kilistazasa"
			<< "0. Kilepes" << std::endl;

		std::cin >> menupont;

		switch (menupont)
		{
		case 1:

			break;
		case  2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 0:

			return;



		}

	} while (menupont != 0);

}
