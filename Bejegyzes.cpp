#define _CRT_SECURE_NO_WARNINGS

#include "Bejegyzes.h"


bool Barat::keres( String const& keresendo) {
    return (getVeznev() == keresendo || getKernev() == keresendo || becenev == keresendo || privat_telszam == keresendo );
}

bool Munkatars::keres( String const& keresendo) {
    return (getVeznev() == keresendo || getKernev()==keresendo || munkahelyi_telszam == keresendo);
}



Barat const& Barat::operator=(Barat const& rhs) {
    if (this == &rhs)
        return rhs;

    getVeznev() = rhs.getVeznev();
    getKernev() = rhs.getKernev();
    becenev = rhs.becenev;
    privat_telszam = rhs.privat_telszam;
    setKov(rhs.getKov());

    return *this;
}


Munkatars const& Munkatars::operator=(Munkatars const& rhs) {
    if (this == &rhs)
        return rhs;

    getVeznev() = rhs.getVeznev();
    getKernev() = rhs.getKernev();
    munkahelyi_telszam = rhs.munkahelyi_telszam;
    setKov(rhs.getKov());

    return *this;

}



void Barat::beolvas(std::istream& is) {
    getVeznev().beolvas(is);
    getKernev().beolvas(is);
    privat_telszam.beolvas(is);

}


void Barat::kiir(std::ostream& os) const {
    getVeznev().kiir(os);
    getKernev().kiir(os);
    becenev.kiir(os);
    privat_telszam.kiir(os);

}


void Munkatars::beolvas(std::istream& is) {
    getVeznev().beolvas(is);
    getKernev().beolvas(is);
    munkahelyi_telszam.beolvas(is);
}





void Munkatars::kiir(std::ostream& os) const {
    getVeznev().kiir(os);
    getKernev().kiir(os);
    munkahelyi_telszam.kiir(os);
}
