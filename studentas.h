#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <list>
#include <numeric>   
#include <algorithm> 
using namespace std;

struct Studentas{
    string vardas;
    string pavarde;
    list<int> nd;
    int egz;
    double galutinis;
};

double baloSkaiciavimas(const Studentas& s);
double baloSkaiciavimasMediana(const Studentas& s);
bool palyginimasVardas(const Studentas &a, const Studentas &b);
bool palyginimasPavarde(const Studentas &a, const Studentas &b);
bool palyginimasGalutinis(const Studentas &a, const Studentas &b);
#endif