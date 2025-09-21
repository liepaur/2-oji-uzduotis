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

int main() {
    vector<Studentas> studentai;
    nuskaitymas("studentai10000.txt", studentai);
}

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
