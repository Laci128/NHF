#define _CRT_SECURE_NO_WARNINGS


#ifndef SZERIALIZAL_H
#define SZERIALIZAL_H

#include <iostream>
#include "memtrace.h"


/// Absztrakt interfesz osztaly sorositashoz/perszisztenciahoz
/// 
class Szerializal
{
public:	
	/// Streamre kiiro fuggveny 
	/// 
	virtual void kiir(std::ostream& os) const = 0;

	/// Streamrol beolvaso fuggveny
	/// 
	virtual void beolvas(std::istream& is) = 0;

	/// Destruktor
	/// 
	virtual ~Szerializal() {};

};


#endif
