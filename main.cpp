#include "funkcijos.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "Timer.h"

using namespace std;

int main(){
    srand(time(0));
    list<Studentas> studentai, kietiakai, vargsiukai;
    Timer t;
    Timer visas;
    int pasirinkimas = 0;
    
    cout << "Pasirinkite duomenų šaltinį:" << endl
        << "1 - Skaityti iš failo" << endl
        << "2 - Generuoti atsitiktinai" << endl;
        cin >> pasirinkimas;

    if (pasirinkimas == 1){
        int failoPasirinkimas;
        cout << "Pasirinkite failo dydį" << endl;
        cout << "1 - 1000 įrašų" << endl;
        cout << "2 - 10000 įrašų" << endl;
        cout << "3 - 100000 įrašų" << endl;
        cout << "4 - 1000000 įrašų" << endl;
        cout << "5 - 10000000 įrašų" << endl;
        cout << flush;
        cin >> failoPasirinkimas;

        auto start = std::chrono::high_resolution_clock::now();
        if (failoPasirinkimas == 1)
            nuskaitymas("studentai1000.txt", studentai);
        else if (failoPasirinkimas == 2)
            nuskaitymas("studentai10000.txt", studentai);
        else if (failoPasirinkimas == 3)
            nuskaitymas("studentai100000.txt", studentai);
        else if (failoPasirinkimas == 4)
            nuskaitymas("studentai1000000.txt", studentai);
        else if (failoPasirinkimas == 5)    
            nuskaitymas("studentai10000000.txt", studentai);
        else{
            cout << "Tokio pasirinkimo nėra!" << endl;
            return 0;
        }
        cout << studentai.size() << " Duomenų nuskaitymas užtruko: " << t.elapsed() << " s\n";

    }

    else if (pasirinkimas == 2){
        int kiekis, ndKiekis;
        cout << "Įveskite studentų skaičių: ";
        cin >> kiekis;
        cout << "Įveskite namų darbų skaičių: ";
        cin >> ndKiekis;
        studentuGeneravimas(studentai, kiekis, ndKiekis);
    }

    else{
        cout << "Tokio pasirinkimo nėra!" << endl;
        return 0;
    }

    t.reset();
    grupavimas(studentai, kietiakai, vargsiukai);
    cout << studentai.size() << " Duomenų rūšiavimas užtruko: " << t.elapsed() << " s\n";
    
    kietiakai.sort(palyginimas);
    vargsiukai.sort(palyginimas);
    
    t.reset();
    sugrupuotuSpausdinimas("kietiahkai.txt", kietiakai);
    cout << "Kietiakų spausdinimas užtruko: " << t.elapsed() << " s\n";
    
    t.reset();
    cout << "Vargsiukų spausdinimas užtruko: " << t.elapsed() << " s\n";
    sugrupuotuSpausdinimas("vargsiukai.txt", vargsiukai);

    cout << "Duomenų įrašymas į failus užtruko: " << t.elapsed() << " s\n";
    
    studentai.sort(palyginimas);
    spausdinimas(studentai);
    cout << studentai.size() << " Duomenų visos programos vykdymas užtruko: " << visas.elapsed() << " s\n";
}
