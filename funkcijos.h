#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <string>
#include <vector>
#include "studentas.h"

using namespace std;

void nuskaitymas(const std::string& failoVardas, std::vector<Studentas>& studentai);
void studentuGeneravimas(std::vector<Studentas>& studentai, int kiekis, int ndKiekis);
void grupavimas(std::vector<Studentas>& studentai, std::vector<Studentas>& kietiakai, std::vector<Studentas>& vargsiukai);
void sugrupuotuSpausdinimas(const string& failoVardas, std::vector<Studentas>& studentai);
void spausdinimas(std::vector<Studentas>& studentai);
void spausdinimasEkrane(std::vector<Studentas>& studentai);

#endif