#include "Bejegyzes.h"

#ifdef _MSC_VER
// MSC ne adjon figyelmeztetõ üzenetet a stringkezelõ függvényekre.
#define _CRT_SECURE_NO_WARNINGS
#endif

bool Bejegyzes::find( const String keresendo) const{
    return (vezeteknev.contains(keresendo) || keresztnev.contains(keresendo));
}

bool Barat::find( const String keresendo) const{
    return (getVeznev().contains(keresendo) || getKernev().contains(keresendo) || becenev.contains(keresendo) || privat_telszam.contains(keresendo));
}

bool Munkatars::find( const String keresendo) const{
    return (getVeznev().contains(keresendo) || getKernev().contains(keresendo) || munkahelyi_telszam.contains(keresendo));
}
