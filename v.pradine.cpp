#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
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
void studentuGeneravimas(vector<Studentas>& studentai, int kiekis, int ndKiekis);
void spausdinimas(const vector<Studentas>& studentai);

int main() {
    vector<Studentas> studentai;
    int pasirinkimas;
    srand(time(0));
    cout << "Pasirinkite duomenų šaltinį:" << endl;
    cout << "1 - Skaityti iš failo" << endl;
    cout << "2 - Generuoti atsitiktinai" <<endl;
    cin >> pasirinkimas;
    if (pasirinkimas == 1){
        nuskaitymas("studentai10000.txt", studentai);
    }
    else if (pasirinkimas == 2){
        int kiekis, ndKiekis;
        cout << "Įveskite studentų skaičių:";
        cin >> kiekis;
        cout << "Įveskite namų darbų skaičių: ";
        cin >> ndKiekis;
        studentuGeneravimas(studentai, kiekis, ndKiekis);
    } else {
        cout << "Tokio pasirinkimo nėra!" << endl;
    }
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

//Funkcija atsitiktiniam rezultatu generavimui
void studentuGeneravimas(vector<Studentas>& studentai, int kiekis, int ndKiekis){
    for (int i = 0; i < kiekis; i++) {
        Studentas st;
        st.vardas = "Vardas" + to_string(i+1);
        st.pavarde = "Pavarde" + to_string(i+1);
        for (int j = 0; j < ndKiekis; j++) {
            st.nd.push_back(rand() % 10 + 1);
        }
        st.egz = rand() % 10 + 1; 
        studentai.push_back(st);
    }
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
