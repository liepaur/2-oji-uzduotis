#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
};

void nuskaitymas(const string& failoVardas, vector<Studentas>& studentai);
double baloSkaiciavimas(const Studentas& s);
double baloSkaiciavimasMediana(const Studentas& s);
void spausdinimas(const vector<Studentas>& studentai);

int main() {
    vector<Studentas> studentai;
    nuskaitymas("studentai10000.txt", studentai);
    spausdinimas(studentai);
}

// Funkcija failo nuskaitymui
void nuskaitymas(const string& failoVardas, vector<Studentas>& studentai) {
    ifstream in(failoVardas);
    string eilute;
    getline(in, eilute);

    while (in.peek() != EOF) { 
        getline(in, eilute);

        stringstream ss(eilute);
        Studentas st;
        ss >> st.vardas >> st.pavarde;

        vector<int> laikini;
        int paz;

        while (ss >> paz) {
            laikini.push_back(paz);
        }

        if (!laikini.empty()) {
            st.egz = laikini.back();
            laikini.pop_back();
            st.nd = laikini;
        }

        studentai.push_back(st);
    }
    in.close();
}

//Funkcija balo skaiciavimui su vidurkiu
double baloSkaiciavimas(const Studentas& s) {
    double nd_vidurkis = 0;
    double suma=0;
    for (size_t i = 0; i < s.nd.size(); i++) {
        suma += s.nd[i];
    }
    nd_vidurkis = static_cast<double>(suma) / s.nd.size();
    return 0.4 * nd_vidurkis + 0.6 * s.egz;
}

//Funkcija balo skaiciavimui su mediana
double baloSkaiciavimasMediana(const Studentas& s) {
    vector<int> kopija = s.nd;
    sort(kopija.begin(), kopija.end());
    double mediana;
    size_t n = kopija.size();
    if (n % 2 == 0) {
        mediana = (kopija[n/2 - 1] + kopija[n/2]) / 2.0;
    } else {
        mediana = kopija[n/2];
    }
    return 0.4 * mediana + 0.6 * s.egz;
}

// Funkcija galutinio balo spausdinimui
void spausdinimas(const vector<Studentas>& studentai) {
    cout << fixed << setprecision(2);
    cout << "Vardas " 
         << "Pavarde " 
         << "Galutinis (Vid.)" 
         << "Galutinis (Med.) "
         << endl;
    for (size_t i = 0; i < studentai.size(); ++i) {
        cout << studentai[i].vardas << " "
             << studentai[i].pavarde << " "
             << baloSkaiciavimas(studentai[i]) << " "
             << baloSkaiciavimasMediana(studentai[i]) << " "
             << endl;
    }
}
