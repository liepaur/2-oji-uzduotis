#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "funkcijos.h"
using namespace std;

int main(){
    srand(time(0));
    vector<Studentas> studentai;
    int pasirinkimas;

    cout << "Pasirinkite duomenų šaltinį:" << endl
         << "1 - Skaityti iš failo" << endl
         << "2 - Generuoti atsitiktinai" << endl;
    cin >> pasirinkimas;

    if (pasirinkimas == 1){
        nuskaitymas("studentai1000000.txt", studentai);
    } 
    else if (pasirinkimas == 2){
        int kiekis, ndKiekis;
        cout << "Įveskite studentų skaičių: ";
        cin >> kiekis;
        cout << "Įveskite namų darbų skaičių: ";
        cin >> ndKiekis;
        studentuGeneravimas(studentai, kiekis, ndKiekis);
    } 
    else {
        cout << "Tokio pasirinkimo nėra!" << endl;
        return 0;
    }

    spausdinimas(studentai);
    return 0;
}
