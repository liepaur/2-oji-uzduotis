#include "studentas.h"
#include <algorithm>
#include <iterator>

double mediana(std::vector<int> v) {
    if (v.empty()) return 0.0;
    std::sort(v.begin(), v.end());
    size_t n = v.size();
    if (n % 2 == 0) {
        return (v[n / 2 - 1] + v[n / 2]) / 2.0;
    }
    else {
        return v[n / 2];
    }
}

std::istream& Studentas::nuskaitymas(std::istream& is) {
    is >> vardas_ >> pavarde_;
    int paz;
    nd_.clear();
    while (is >> paz) {
        nd_.push_back(paz);
    }

    if(!nd_.empty()) {
        egz_ = nd_.back();
        nd_.pop_back();
    } else {
        egz_ = 0;
    }
    return is;
}

double Studentas::skaiciuotiVidurki() const {
    if (nd_.empty()) return 0.0;
    double vidurkis = std::accumulate(nd_.begin(), nd_.end(), 0.0) / nd_.size();
    return vidurkis;
}

double Studentas::skaiciuotiMediana() const {
    return mediana(nd_);
}

void Studentas::apskaiciuotiGalutini(bool naudotiMediana) {
    double nd_rezultatas = naudotiMediana ? skaiciuotiMediana() : skaiciuotiVidurki();
    galutinis_ = 0.4 * nd_rezultatas + 0.6 * egz_;
}

void Studentas::spausdinti(std::ostream& os) const {
    os << std::left << std::setw(15) << vardas_
       << std::left << std::setw(15) << pavarde_
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