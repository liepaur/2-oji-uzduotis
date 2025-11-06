#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <string>
#include <vector>
#include "studentas.h"

using namespace std;


void nuskaitymas(const string& failoVardas, list<Studentas>& studentai);
void studentuGeneravimas(list<Studentas>& studentai, int kiekis, int ndKiekis);
void grupavimas(list<Studentas>& studentai, list<Studentas>& kietiakai, list<Studentas>& vargsiukai);
void sugrupuotuSpausdinimas(const string& failoVardas, list<Studentas>& studentai);
void spausdinimas(list<Studentas>& studentai);

#endif