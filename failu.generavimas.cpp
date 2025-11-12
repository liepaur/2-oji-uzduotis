#include <fstream>
#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <iomanip>
using namespace std;

void failoKurimas(const string &failas, int kiekis);

int main(){
    srand(time(0));
    /*ofstream file;
    file.open("studentai1000.txt");
    if (!file.is_open())
    {
        cout << "Failas nesukurtas" << endl;
        return 1;
    }

    file << "Vardas Pavarde ND1 ND2 ND3 ND4 ND5 Egzaminas" << endl;
    for (int i = 1; i <= 1000; i++){
        file << "Vardas" << i << " Pavarde" << i;
        for (int j = 0; j < 5; j++){
            file << " " << (rand() % 10 + 1);
    file.close();
    return 0;}*/
    failoKurimas("studentai1000.txt", 1000);
    failoKurimas("studentai10000.txt", 10000);
    failoKurimas("studentai100000.txt", 1000000);
    failoKurimas("studentai1000000.txt", 1000000);
    failoKurimas("studentai10000000.txt", 10000000);
}


void failoKurimas(const string & failas, int kiekis){
    ofstream file(failas, ios::trunc);
    if (!file.is_open())
    {
        cout << "Failas nesukurtas" << endl;
    }

    file << "Vardas" << setw(20) << "Pavarde" << setw(20) << "ND1" <<setw(10) << "ND2" <<setw(10)<< "ND3" <<setw(10) << "ND4" <<setw(10)<< "ND5"<<setw(10)<<  "Egzaminas" ;
    for (int i = 1; i <= kiekis; i++){
        file << endl << "Vardas" << i << setw(20) << " Pavarde" << i;
        for (int j = 0; j < 5; j++){
            file << setw(10) << " " << (rand() % 10 + 1);
        }
    }
    file.close();
}   

