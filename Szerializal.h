#ifndef SZERIALIZAL_H
#define SZERIALIZAL_H

#include <iostream>

class Szerializal
{
public:	
	///
	virtual void kiir(std::ostream os) const = 0;

	///
	virtual void beolvas(std::istream& is) = 0;

	///Destruktor
	virtual ~Szerializal() {};

};


#endif
