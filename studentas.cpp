#include "studentas.h"
#include <algorithm>
#include <iterator>
#include <sstream>

double mediana(std::vector<int> v) {
    if (v.empty()) return 0.0;
    std::sort(v.begin(), v.end());
    size_t n = v.size();
    if (n % 2 == 0)
        return (v[n / 2 - 1] + v[n / 2]) / 2.0;
    else
        return v[n / 2];
}

Studentas::Studentas() : Zmogus(), egz_(0), galutinis_(0.0) {}

Studentas::Studentas(const std::string& vardas, const std::string& pavarde)
    : Zmogus(vardas, pavarde), egz_(0), galutinis_(0.0) {}

Studentas::Studentas(const Studentas &other)
    : Zmogus(other), nd_(other.nd_), egz_(other.egz_), galutinis_(other.galutinis_) {}

Studentas& Studentas::operator=(const Studentas &other) {
    if (this != &other) {
        Zmogus::operator=(other);
        nd_ = other.nd_;
        egz_ = other.egz_;
        galutinis_ = other.galutinis_;
    }
    return *this;
}

Studentas::~Studentas() {}

Studentas::Studentas(std::istream& is) {
    nuskaitymas(is, false);
}

std::istream& operator>>(std::istream& is, Studentas& st) {
    return st.nuskaitymas(is, true);
}

std::ostream& operator<<(std::ostream& os, const Studentas& st) {
    st.spausdinti(os);
    return os;
}

std::istream& Studentas::nuskaitymas(std::istream& is, bool interaktyvus) {
    if (interaktyvus) std::cout << "Vardas: ";
    is >> vardas_;

    if (interaktyvus) std::cout << "Pavarde: ";
    is >> pavarde_;

    int nd_kiek;
    if (interaktyvus) std::cout << "Iveskite namu darbu skaiciu: ";
    is >> nd_kiek;

    nd_.clear();
    for (int i = 0; i < nd_kiek; ++i) {
        int paz;
        if (interaktyvus) std::cout << "ND " << i + 1 << ": ";
        is >> paz;
        nd_.push_back(paz);
    }

    if (interaktyvus) std::cout << "Egzamino balas: ";
    is >> egz_;

    return is;
}


double Studentas::skaiciuotiVidurki() const {
    if (nd_.empty()) return 0.0;
    return std::accumulate(nd_.begin(), nd_.end(), 0.0) / nd_.size();
}

double Studentas::skaiciuotiMediana() const {
    return mediana(nd_);
}

void Studentas::apskaiciuotiGalutini(bool naudotiMediana) {
    double nd_rezultatas = naudotiMediana ? skaiciuotiMediana() : skaiciuotiVidurki();
    galutinis_ = 0.4 * nd_rezultatas + 0.6 * egz_;
}

void Studentas::spausdinti(std::ostream& os) const {
    os << std::left << std::setw(15) << vardas()
       << std::left << std::setw(15) << pavarde()
       << std::right << std::setw(5) << std::fixed << std::setprecision(2) << galutinis_;
}

bool palyginimasVardas(const Studentas &a, const Studentas &b) {
    return a.vardas() < b.vardas();
}

bool palyginimasPavarde(const Studentas &a, const Studentas &b) {
    return a.pavarde() < b.pavarde();
}

bool palyginimasGalutinis(const Studentas &a, const Studentas &b) {
    return a.galutinis() < b.galutinis();
}
