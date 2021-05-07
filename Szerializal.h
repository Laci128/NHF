#define _CRT_SECURE_NO_WARNINGS


#ifndef SZERIALIZAL_H
#define SZERIALIZAL_H

#include <iostream>


<<<<<<< HEAD
=======
#define _CRT_SECURE_NO_WARNINGS
>>>>>>> 5d622f23b80a08881370bd9b9aa0898055477c0d

class Szerializal
{
public:	
	///
	virtual void kiir(std::ostream& os) const = 0;

	///
	virtual void beolvas(std::istream& is) = 0;

	///Destruktor
	virtual ~Szerializal() {};

};


#endif
