#include "funkcijos.h"
#include "studentas.h" 
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>

using namespace std;

void nuskaitymas(const string& failoVardas, list<Studentas>& studentai){
    ifstream in(failoVardas);
    if (!in.is_open()) {
        cout << "Nepavyko atidaryti failo: " << failoVardas << endl;
        return;
    }
    Studentas st;
    string eilute;
    getline(in, eilute);

    while (getline(in, eilute)) {
        stringstream ss(eilute);
        ss >> st.vardas >> st.pavarde;
        list<int> laikini;
        int paz;
        while (ss >> paz) laikini.push_back(paz);

        if (!laikini.empty()) {
            st.egz = laikini.back();
            laikini.pop_back();
            st.nd = laikini;
        }
        studentai.push_back(st);
    }

    in.close();
}

void studentuGeneravimas(list<Studentas>& studentai, int kiekis, int ndKiekis){
    Studentas st;
    for (int i = 0; i < kiekis; i++) {
        st.vardas = "Vardas" + to_string(i + 1);
        st.pavarde = "Pavarde" + to_string(i + 1);

        for (int j = 0; j < ndKiekis; j++)
            st.nd.push_back(rand() % 10 + 1);

        st.egz = rand() % 10 + 1;
        studentai.push_back(st);
    }
}

void spausdinimas(list<Studentas>& studentai){
    ofstream out("rezultatai.txt");
    out << fixed << setprecision(2);
    out << left << setw(20) << "Vardas"
         << setw(20) << "Pavarde"
         << setw(20) << "Galutinis (Vid.)"
         << setw(20) << "Galutinis (Med.)" << endl;
    out << string(60, '-') << endl;

    for (const Studentas& s : studentai){
        out << left << setw(20) << s.vardas
             << setw(20) << s.pavarde
             << setw(20) << s.galutinis << endl;
    }
}

void grupavimas(list<Studentas>& studentai, list<Studentas>& kietiakai, list<Studentas>& vargsiukai){
    for (const Studentas& s : studentai){
        if (baloSkaiciavimas(s) >= 5.0){
            kietiakai.push_back(s);
        }
        else{
            vargsiukai.push_back(s);
        }
    }
}

void sugrupuotuSpausdinimas(const string& failoVardas, list<Studentas>& studentai){
    ofstream out(failoVardas);
    out << fixed << setprecision(2);
    out << left << setw(20) << "Vardas"
        << setw(20) << "Pavarde"
        << setw(20) << "Galutinis (Vid.)"
        << setw(20) << "Galutinis (Med.)"
        << endl;
    out << "-----------------------------------------------------------------------" << endl;
    for (const Studentas& s : studentai){
        out << left << setw(20) << s.vardas
            << setw(20) << s.pavarde
            << setw(20) << s.galutinis
            << endl;
    }
    out.close();
}

