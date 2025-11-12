#include "studentas.h"
#include <algorithm>
#include <iterator>

double baloSkaiciavimas(const Studentas& s) {
    double suma = 0;
    for (int paz : s.nd) suma += paz;
    double nd_vidurkis = static_cast<double>(suma) / s.nd.size();
    return 0.4 * nd_vidurkis + 0.6 * s.egz;
}

double baloSkaiciavimasMediana(const Studentas& s) {
    if (s.nd.empty()) return 0.0;
    list<int> kopija = s.nd;
    kopija.sort();
    size_t n = kopija.size();
    auto it = kopija.begin();
    
    double mediana;
    if (n % 2 == 0) {
        advance(it, n / 2 - 1);
        double first = *it;
        advance(it, 1);
        double second = *it;
        mediana = (first + second) / 2.0;
    }
    else {
        advance(it, n / 2);
        mediana = *it;
    }
    return 0.4 * mediana + 0.6 * s.egz;
}

bool palyginimasVardas(const Studentas &a, const Studentas &b) {
    return a.vardas < b.vardas;
}

bool palyginimasPavarde(const Studentas &a, const Studentas &b) {
    return a.pavarde < b.pavarde;
}

bool palyginimasGalutinis(const Studentas &a, const Studentas &b) {
    return a.galutinis < b.galutinis;
}
