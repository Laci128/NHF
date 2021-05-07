#define _CRT_SECURE_NO_WARNINGS

#include "Bejegyzes.h"


/*
bool Bejegyzes::keres( String const& keresendo) {
    return (getVeznev() == keresendo || getKernev() == keresendo);
}*/

bool Barat::keres( String const& keresendo) {
    return (getVeznev() == keresendo || getKernev() == keresendo || becenev == keresendo || privat_telszam == keresendo );
}

bool Munkatars::keres( String const& keresendo) {
    return (getVeznev() == keresendo || getKernev()==keresendo || munkahelyi_telszam == keresendo);
}

/*
void  Bejegyzes::beolvas(std::istream& is) {
}


void  Bejegyzes::kiir(std::ostream& os) const {

}*/


Barat const& Barat::operator=(Barat const& rhs) {
    if (this == &rhs)
        return rhs;

    this->getVeznev() = rhs.getVeznev();
    this->getKernev() = rhs.getKernev();
    this->becenev = rhs.becenev;
    this->privat_telszam = rhs.privat_telszam;
    this->setKov(rhs.getKov());

    return *this;
}


Munkatars const& Munkatars::operator=(Munkatars const& rhs) {
    if (this == &rhs)
        return rhs;

    this->getVeznev() = rhs.getVeznev();
    this->getKernev() = rhs.getKernev();
    this->munkahelyi_telszam = rhs.munkahelyi_telszam;
    this->setKov(rhs.getKov());

    return *this;

}



void  Barat::beolvas(std::istream& is) {
    String ures;
    this->getVeznev() = ures;
    this->getKernev() = ures;
    this->becenev = ures;
    this->privat_telszam = ures;
    
    getVeznev().beolvas(is);
    getKernev().beolvas(is);
    becenev.beolvas(is);
    privat_telszam.beolvas(is);
}


void  Barat::kiir(std::ostream& os) const {
    getVeznev().kiir(os);
    getKernev().kiir(os);
    becenev.kiir(os);
    privat_telszam.kiir(os);

}


void  Munkatars::beolvas(std::istream& is) {
    String ures;
    this->getVeznev() = ures;
    this->getKernev() = ures;
    this->munkahelyi_telszam = ures;
    
    getVeznev().beolvas(is);
    getKernev().beolvas(is);
    munkahelyi_telszam.beolvas(is);
}


void  Munkatars::kiir(std::ostream& os) const {
    getVeznev().kiir(os);
    getKernev().kiir(os);
    munkahelyi_telszam.kiir(os);
}