#include "funkcijos.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "Timer.h"
#include "studentas.h"

using namespace std;

int main(){
    srand(time(0));
    list<Studentas> studentai, kietiakai, vargsiukai, galutinis;
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

    cout << "Pasirinkite galutinio balo skaičiavimo būdą:" << endl
        << "1 - Vidurkis" << endl
        << "2 - Mediana" << endl;
    int GalutinioPasirinkimas;
    cin >> GalutinioPasirinkimas;
    if(GalutinioPasirinkimas !=1 && GalutinioPasirinkimas !=2){
        cout << "Tokio pasirinkimo nėra!" << endl;
        return 0;
    }
    else if(GalutinioPasirinkimas == 1){
        for(auto& s : studentai){
            s.galutinis = baloSkaiciavimas(s);
        }
    }
    else if(GalutinioPasirinkimas == 2){
        for(auto& s : studentai){
            s.galutinis = baloSkaiciavimasMediana(s);
        }
    }

    cout << "Pasirinkite duomenų rūšiavimo būdą:" << endl
        << "1 - Pagal vardą" << endl
        << "2 - Pagal pavardę" << endl
        << "3 - Pagal galutinį balą" << endl;
    int RusiavimoPasirinkimas;
    cin >> RusiavimoPasirinkimas;
    if(RusiavimoPasirinkimas !=1 && RusiavimoPasirinkimas !=2 && RusiavimoPasirinkimas !=3){
        cout << "Tokio pasirinkimo nėra!" << endl;
        return 0;
    }
    else if(RusiavimoPasirinkimas == 1)
        studentai.sort(palyginimasVardas);
    else if(RusiavimoPasirinkimas == 2)
        studentai.sort(palyginimasPavarde);
    else if(RusiavimoPasirinkimas == 3)
        studentai.sort(palyginimasGalutinis);

    t.reset();
    grupavimas(studentai, kietiakai, vargsiukai);
    cout << studentai.size() << " Duomenų rūšiavimas užtruko: " << t.elapsed() << " s\n";
    
    t.reset();
    sugrupuotuSpausdinimas("kietiahkai.txt", kietiakai);
    cout << "Kietiakų spausdinimas užtruko: " << t.elapsed() << " s\n";
    
    t.reset();
    cout << "Vargsiukų spausdinimas užtruko: " << t.elapsed() << " s\n";
    sugrupuotuSpausdinimas("vargsiukai.txt", vargsiukai);

    cout << "Duomenų įrašymas į failus užtruko: " << t.elapsed() << " s\n";
    
    spausdinimas(studentai);
    cout << studentai.size() << " Duomenų visos programos vykdymas užtruko: " << visas.elapsed() << " s\n";
}
