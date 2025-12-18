else if (pasirinkimas == 3) {
        int kiekis;
        std::cout << "Iveskite studentu skaiciu: ";
        std::cin >> kiekis;

        for (int i = 0; i < kiekis; i++) {
            Studentas s;

            std::cout << "Iveskite " << i + 1 << " studento duomenis:\n";
            std::cin >> s;
            studentai.push_back(s);

            auto it = studentai.end();
            --it;
            std::cout << "Objekto adresas atmintyje: " << &(*it) << std::endl;
        }
    }