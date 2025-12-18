void nuskaitymas(const std::string& failoVardas, std::vector<Studentas>& studentai){
    std::ifstream in(failoVardas);
    if (!in.is_open()) {
        std::cout << "Nepavyko atidaryti failo: " << failoVardas << std::endl;
        return;
    }

    std::string eilute;
    getline(in, eilute);

    while (getline(in, eilute)) {
        std::stringstream ss(eilute);
        Studentas st(ss);
        st.apskaiciuotiGalutini(false);
        studentai.push_back(st);
    }

    in.close();
}