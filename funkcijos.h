#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <string>
#include <vector>
#include "studentas.h"
using namespace std;

void nuskaitymas(const string& failoVardas, vector<Studentas>& studentai);
void studentuGeneravimas(vector<Studentas>& studentai, int kiekis, int ndKiekis);
void spausdinimas(vector<Studentas>& studentai);

#endif