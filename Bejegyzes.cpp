#define _CRT_SECURE_NO_WARNINGS

#include "Bejegyzes.h"
#include "memtrace.h"

//------------------------------------Munkatars------------------------------------

bool Munkatars::operator==(Munkatars const& rhs) const {
    return(munkahelyi_telszam == rhs.munkahelyi_telszam && getVeznev() == rhs.getVeznev() && getKernev() == rhs.getKernev());
}


bool Munkatars::operator==(Bejegyzes const& rhs) const {
    const Munkatars* p = dynamic_cast<const Munkatars*>(&rhs);
    if (p != nullptr)
        return (*this == *p);
    else
        return false;
}


Munkatars& Munkatars::operator=(Munkatars const& rhs) {
    if (this == &rhs)
        return *this;

    setVeznev(rhs.getVeznev());
    setKernev(rhs.getKernev());
    munkahelyi_telszam = rhs.munkahelyi_telszam;
    setKov(nullptr);

    return *this;
}


Bejegyzes& Munkatars::operator=(Bejegyzes const& rhs) {
    const Munkatars* ptr = dynamic_cast<const Munkatars*>(&rhs);
    if (ptr != nullptr) {
        *this = *ptr;
        return *this;
    }
    else
        throw "A jobboldali nem Munkatars!";
}


bool Munkatars::benne_van_e(String const& keresendo) const {
    return (getVeznev() == keresendo || getKernev() == keresendo || munkahelyi_telszam == keresendo);
}


void Munkatars::kiir(std::ostream& os) const {
    getVeznev().kiir(os);
    getKernev().kiir(os);
    munkahelyi_telszam.kiir(os);
}


void Munkatars::beolvas(std::istream& is) {
    String temp;
    temp.beolvas(is);
    setVeznev(temp);
    temp.beolvas(is);
    setKernev(temp);
    munkahelyi_telszam.beolvas(is);
}


//------------------------------------Barat------------------------------------

bool Barat::operator==(Barat const& rhs) const {
    return(becenev == rhs.becenev && privat_telszam == rhs.privat_telszam && getVeznev() == rhs.getVeznev() && getKernev() == rhs.getKernev());
}


bool Barat::operator==(Bejegyzes const& rhs) const {
    const Barat* ptr = dynamic_cast<const Barat*>(&rhs);
    if (ptr != nullptr)
        return (*this == *ptr);
    else
        return false;
}


Barat& Barat::operator=(Barat const& rhs) {
    if (this == &rhs)
        return *this;

    setVeznev(rhs.getVeznev());
    setKernev(rhs.getKernev());
    becenev = rhs.becenev;
    privat_telszam = rhs.privat_telszam;
    setKov(nullptr);

    return *this;
}


Bejegyzes& Barat::operator=(Bejegyzes const& rhs) {
    const Barat* ptr = dynamic_cast<const Barat*>(&rhs);
    if (ptr != nullptr) {
        *this = *ptr;
        return *this;
    }
    else
        throw "A jobboldali nem Barat!";
}


bool Barat::benne_van_e(String const& keresendo) const {
    return (getVeznev() == keresendo || getKernev() == keresendo || becenev == keresendo || privat_telszam == keresendo);
}

void Barat::kiir(std::ostream& os) const {
    getVeznev().kiir(os);
    getKernev().kiir(os);
    becenev.kiir(os);
    privat_telszam.kiir(os);
}


void Barat::beolvas(std::istream& is) {
    String temp;
    temp.beolvas(is);
    setVeznev(temp);
    temp.beolvas(is);
    setKernev(temp);
    becenev.beolvas(is);
    privat_telszam.beolvas(is);
}



