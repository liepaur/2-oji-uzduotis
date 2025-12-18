#include "funkcijos.h"
#include "studentas.h"
#include "Timer.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

int main() {
    srand(time(0));
    Timer visas;
    std::vector<Studentas> studentai, kietiakai, vargsiukai;

    int pasirinkimas = 0;
    std::cout << "Pasirinkite duomenų šaltinį:\n"
              << "1 - Skaityti iš failo\n"
              << "2 - Generuoti atsitiktinai\n"
              << "3 - Įvesti rankiniu būdų\n";
    std::cin >> pasirinkimas;

    if (pasirinkimas == 1) {
        int failoPasirinkimas;
        std::cout << "Pasirinkite failo dydį:\n"
                  << "1 - 1000 įrašų\n"
                  << "2 - 10000 įrašų\n"
                  << "3 - 100000 įrašų\n"
                  << "4 - 1000000 įrašų\n"
                  << "5 - 10000000 įrašų\n";
        std::cin >> failoPasirinkimas;

        std::string failoVardas;
        if (failoPasirinkimas == 1)
            failoVardas = "studentai1000.txt";
        else if (failoPasirinkimas == 2)
            failoVardas = "studentai10000.txt";
        else if (failoPasirinkimas == 3)
            failoVardas = "studentai100000.txt";
        else if (failoPasirinkimas == 4)
            failoVardas = "studentai1000000.txt";
        else if (failoPasirinkimas == 5)
            failoVardas = "studentai10000000.txt";
        else {
            std::cout << "Tokio pasirinkimo nėra!\n";
            return 0;
        }

        Timer t;
        nuskaitymas(failoVardas, studentai);
        std::cout << studentai.size() << " studentų nuskaityta per " << t.elapsed() << " s.\n";
    }
    else if (pasirinkimas == 2) {
        int kiekis, ndKiekis;
        std::cout << "Įveskite studentų skaičių: ";
        std::cin >> kiekis;
        std::cout << "Įveskite namų darbų skaičių: ";
        std::cin >> ndKiekis;
        studentuGeneravimas(studentai, kiekis, ndKiekis);
    }
    else if (pasirinkimas == 3) {
    int kiekis;
    std::cout << "Įveskite studentų skaičių: ";
    std::cin >> kiekis;

    for (int i = 0; i < kiekis; i++) {
        Studentas s;

        std::cout << "\nĮveskite " << i + 1 << " studento duomenis:\n";

        std::string vardas;
        std::cout << "Vardas: ";
        std::cin >> vardas;
        s.setVardas(vardas);

        std::string pavarde;
        std::cout << "Pavardė: ";
        std::cin >> pavarde;
        s.setPavarde(pavarde);

        int ndKiekis;
        std::cout << "Įveskite namų darbų skaičių: ";
        std::cin >> ndKiekis;

        std::vector<int> nd(ndKiekis);
        for (int j = 0; j < ndKiekis; j++) {
            std::cout << "ND " << j + 1 << ": ";
            std::cin >> nd[j];
        }
        s.setND(nd);

        int egz;
        std::cout << "Egzamino balas: ";
        std::cin >> egz;
        s.setEgz(egz);

        studentai.push_back(s);

        auto it = studentai.end();
        --it;
        std::cout << "Objekto adresas atmintyje: " << &(*it) << std::endl;
    }
}

    else {
        std::cout << "Tokio pasirinkimo nėra!\n";
        return 0;
    }

    int GalutinioPasirinkimas;
    std::cout << "Pasirinkite galutinio balo skaičiavimo būdą:\n"
              << "1 - Vidurkis\n"
              << "2 - Mediana\n";
    std::cin >> GalutinioPasirinkimas;

    for (auto& s : studentai)
        s.apskaiciuotiGalutini(GalutinioPasirinkimas == 2);
    int RusiavimoPasirinkimas;
    std::cout << "Pasirinkite duomenų rūšiavimo būdą:\n"
              << "1 - Pagal vardą\n"
              << "2 - Pagal pavardę\n"
              << "3 - Pagal galutinį balą\n";
    std::cin >> RusiavimoPasirinkimas;

    if (RusiavimoPasirinkimas == 1)
        std::sort(studentai.begin(), studentai.end(), palyginimasVardas);
    else if (RusiavimoPasirinkimas == 2)
        std::sort(studentai.begin(), studentai.end(), palyginimasPavarde);
    else if (RusiavimoPasirinkimas == 3)
        std::sort(studentai.begin(), studentai.end(), palyginimasGalutinis);
    else {
        std::cout << "Tokio pasirinkimo nėra!\n";
        return 0;
    }

    std::cout << "Pasirinkite išvesties būdą:\n"
              << "1 - Į failą\n"
              << "2 - Paprastas išvedimas\n";

    int isvestiesBudas;
    std::cin >> isvestiesBudas;


    Timer t;
    grupavimas(studentai, kietiakai, vargsiukai);
    std::cout << studentai.size() << " studentų rūšiavimas užtruko: " << t.elapsed() << " s.\n";

    if( isvestiesBudas == 1 ) {
    t.reset();
    sugrupuotuSpausdinimas("kietiakai.txt", kietiakai);
    std::cout << "Kietiakų spausdinimas užtruko: " << t.elapsed() << " s.\n";

    t.reset();
    sugrupuotuSpausdinimas("vargsiukai.txt", vargsiukai);
    std::cout << "Vargsiukų spausdinimas užtruko: " << t.elapsed() << " s.\n";

    t.reset();
    spausdinimas(studentai);
    std::cout << studentai.size() << " studentų rezultatų išvedimas užtruko: " << t.elapsed() << " s.\n";
    }
    else if( isvestiesBudas == 2 ) {
        t.reset();
        spausdinimasEkrane(studentai);
        std::cout << studentai.size() << " studentų rezultatų išvedimas užtruko: " << t.elapsed() << " s.\n";
    }
    else {
        std::cout << "Tokio pasirinkimo nėra!\n";
        return 0;
    }

    std::cout << "Visa programa užtruko: " << visas.elapsed() << " s.\n";
}
