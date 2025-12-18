#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include "zmogus.h"

double mediana(std::vector<int> v);

class Studentas : public Zmogus {
private:
    std::vector<int> nd_;
    int egz_;
    double galutinis_;

public:
    Studentas();
    Studentas(const std::string& vardas, const std::string& pavarde);
    Studentas(std::istream& is);

    Studentas(const Studentas& other);
    Studentas& operator=(const Studentas& other);
    ~Studentas();

    inline double galutinis() const { return galutinis_; }
    inline const std::vector<int>& nd() const { return nd_; }
    inline int egz() const { return egz_; }

    std::istream& nuskaitymas(std::istream& is, bool interaktyvus = true);
    double skaiciuotiVidurki() const;
    double skaiciuotiMediana() const;
    void apskaiciuotiGalutini(bool naudotiMediana);
    void spausdinti(std::ostream& os) const override;
    void setVardas(const std::string& v) { vardas_ = v; }
    void setPavarde(const std::string& p) { pavarde_ = p; }
    void setND(const std::vector<int>& nd) { nd_ = nd; }
    void setEgz(int e) { egz_ = e; }
};


std::istream& operator>>(std::istream& is, Studentas& st);
std::ostream& operator<<(std::ostream& os, const Studentas& st);

bool palyginimasVardas(const Studentas &a, const Studentas &b);
bool palyginimasPavarde(const Studentas &a, const Studentas &b);
bool palyginimasGalutinis(const Studentas &a, const Studentas &b);

#endif
