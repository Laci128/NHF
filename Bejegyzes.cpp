#define _CRT_SECURE_NO_WARNINGS

#include "Bejegyzes.h"



bool Bejegyzes::keres( String const& keresendo) {
    return (getVeznev() == keresendo || getKernev() == keresendo);
}

bool Barat::keres( String const& keresendo) {
    return (getVeznev() == keresendo || getKernev() == keresendo || becenev == keresendo || privat_telszam == keresendo );
}

bool Munkatars::keres( String const& keresendo) {
    return (getVeznev() == keresendo || getKernev()==keresendo || munkahelyi_telszam == keresendo);
}


void  Bejegyzes::beolvas(std::istream& is) {
}


void  Bejegyzes::kiir(std::ostream& os) const {

}


void  Barat::beolvas(std::istream& is) {
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
    getVeznev().beolvas(is);
    getKernev().beolvas(is);
    munkahelyi_telszam.beolvas(is);
}


void  Munkatars::kiir(std::ostream& os) const {
    getVeznev().kiir(os);
    getKernev().kiir(os);
    munkahelyi_telszam.kiir(os);
}