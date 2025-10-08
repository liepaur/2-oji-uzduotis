#include "studentas.h"
#include <algorithm>

double baloSkaiciavimas(const Studentas& s) {
    double suma = 0;
    for (int paz : s.nd) suma += paz;
    double nd_vidurkis = static_cast<double>(suma) / s.nd.size();
    return 0.4 * nd_vidurkis + 0.6 * s.egz;
}

double baloSkaiciavimasMediana(const Studentas& s) {
    vector<int> kopija = s.nd;
    sort(kopija.begin(), kopija.end());
    double mediana;
    size_t n = kopija.size();
    if (n % 2 == 0)
        mediana = (kopija[n/2 - 1] + kopija[n/2]) / 2.0;
    else
        mediana = kopija[n/2];
    return 0.4 * mediana + 0.6 * s.egz;
}

bool palyginimas(const Studentas& a, const Studentas& b) {
    return a.vardas < b.vardas;
}
