#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <sstream>

double mediana(std::vector<int> v);

class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> nd_;
    int egz_;
    double galutinis_;

public:
    Studentas() : egz_(0), galutinis_(0.0) {}
    Studentas(std::istream& is) { nuskaitymas(is); }

    inline std::string vardas() const { return vardas_; }
    inline std::string pavarde() const { return pavarde_; }
    inline double galutinis() const { return galutinis_; }
    inline const std::vector<int>& nd() const { return nd_; }
    inline int egz() const { return egz_; }

    std::istream& nuskaitymas(std::istream& is);

    double skaiciuotiVidurki() const;
    double skaiciuotiMediana() const;
    void apskaiciuotiGalutini(bool naudotiMediana = false);

    void spausdinimas(std::ostream& os) const;
};

bool palyginimasVardas(const Studentas &a, const Studentas &b);
bool palyginimasPavarde(const Studentas &a, const Studentas &b);
bool palyginimasGalutinis(const Studentas &a, const Studentas &b);

#endif
