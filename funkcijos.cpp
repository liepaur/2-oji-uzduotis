#include "funkcijos.h"
#include "studentas.h" 
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>

void nuskaitymas(const std::string& failoVardas, std::vector<Studentas>& studentai){
    std::ifstream in(failoVardas);
    if (!in.is_open()) {
        std::cout << "Nepavyko atidaryti failo: " << failoVardas << std::endl;
        return;
    }

    std::string eilute;
    getline(in, eilute);

    while (getline(in, eilute)) {
        std::stringstream ss(eilute);
        Studentas st;
        st.apskaiciuotiGalutini(false);
        studentai.push_back(st);
    }

    in.close();
}

void studentuGeneravimas(std::vector <Studentas>& studentai, int kiekis, int ndKiekis){
    for (int i = 0; i < kiekis; ++i){
        std::stringstream ss;
        ss << "Vardas" << i+1 << " Pavarde" << i+1;
        for(int j=0; j < ndKiekis; ++j){
            ss << rand() % 10 + 1 << " ";
        }
        ss << rand() % 10 + 1;

        Studentas st(ss);
        st.apskaiciuotiGalutini(false);
        studentai.push_back(st);
    }
}

void spausdinimas(std::vector<Studentas>& studentai){
    std::ofstream out("rezultatai.txt");
    out << fixed << setprecision(2);
    out << std::left << setw(20) << "Vardas"
         << std::setw(20) << "Pavarde"
         << std::setw(20) << "Galutinis (Vid.)"
         << std::setw(20) << "Galutinis (Med.)" << endl;
    out << std::string(60, '-') << endl;

    for(const auto& s: studentai)
    {
        s.spausdinti(out);
    }
}

void grupavimas(std::vector<Studentas>& studentai, std::vector<Studentas>& kietiakai, std::vector<Studentas>& vargsiukai){
    for(const auto& s : studentai){
        if(s.galutinis() >= 5.0){
            kietiakai.push_back(s);
        } 
        else {
            vargsiukai.push_back(s);
        }
}
}


void sugrupuotuSpausdinimas(const std::string& failoVardas, std::vector<Studentas>& studentai){
    std::ofstream out(failoVardas);
    out << fixed << setprecision(2);
    out << std::left << setw(20) << "Vardas"
        << std::setw(20) << "Pavarde"
        << std::setw(20) << "Galutinis (Vid.)"
        << std::setw(20) << "Galutinis (Med.)"
        << endl;
    out << "-----------------------------------------------------------------------" << endl;
    for (const auto& s : studentai){
        s.spausdinti(out);
    }
}


void spausdinimasEkrane(std::vector<Studentas>& studentai){
    std:: cout << fixed << setprecision(2);
    std:: cout << std::left << setw(20) << "Vardas"
         << std::setw(20) << "Pavarde"
         << std::setw(20) << "Galutinis (Vid.)"
         << std::setw(20) << "Galutinis (Med.)" << endl;
    std::cout << std::string(60, '-') << endl;

    for(const auto& s: studentai)
    {
        s.spausdinti(std::cout);
    }
}