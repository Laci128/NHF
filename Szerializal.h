#ifndef SZERIALIZAL_H
#define SZERIALIZAL_H

#include <iostream>


#ifdef _MSC_VER
// MSC ne adjon figyelmeztet� �zenetet a stringkezel� f�ggv�nyekre.
#define _CRT_SECURE_NO_WARNINGS
#endif

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
