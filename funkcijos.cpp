#include "funkcijos.h"
#include "studentas.h" 
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>

using namespace std;

void nuskaitymas(const string& failoVardas, vector<Studentas>& studentai){
    ifstream in(failoVardas);
    if (!in.is_open()) {
        cout << "Nepavyko atidaryti failo: " << failoVardas << endl;
        return;
    }

    string eilute;
    getline(in, eilute); // skip header

    while (getline(in, eilute)) {
        stringstream ss(eilute);
        Studentas st;
        ss >> st.vardas >> st.pavarde;
        vector<int> laikini;
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

void studentuGeneravimas(vector<Studentas>& studentai, int kiekis, int ndKiekis){
    for (int i = 0; i < kiekis; i++) {
        Studentas st;
        st.vardas = "Vardas" + to_string(i + 1);
        st.pavarde = "Pavarde" + to_string(i + 1);

        for (int j = 0; j < ndKiekis; j++)
            st.nd.push_back(rand() % 10 + 1);

        st.egz = rand() % 10 + 1;
        studentai.push_back(st);
    }
}

void spausdinimas(vector<Studentas>& studentai){
    sort(studentai.begin(), studentai.end(), palyginimas);

    cout << fixed << setprecision(2);
    cout << left << setw(15) << "Vardas"
         << setw(15) << "Pavarde"
         << setw(15) << "Galutinis (Vid.)"
         << setw(15) << "Galutinis (Med.)" << endl;
    cout << string(60, '-') << endl;

    for (const Studentas& s : studentai){
        cout << left << setw(15) << s.vardas
             << setw(15) << s.pavarde
             << setw(15) << baloSkaiciavimas(s)
             << setw(15) << baloSkaiciavimasMediana(s) << endl;
    }
}
