#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
using namespace std;

struct Studentas{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
};

double baloSkaiciavimas(const Studentas& s);
double baloSkaiciavimasMediana(const Studentas& s);
bool palyginimas(const Studentas& a, const Studentas& b);

#endif