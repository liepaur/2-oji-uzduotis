#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
#include <iostream>

class Zmogus {
protected:
    std::string vardas_;
    std::string pavarde_;

public:
    Zmogus() : vardas_(""), pavarde_("") {}
    Zmogus(const std::string& vardas, const std::string& pavarde) 
        : vardas_(vardas), pavarde_(pavarde) {}

    virtual ~Zmogus() = default;  

    virtual void spausdinti(std::ostream& os) const = 0;

    std::string vardas() const { return vardas_; }
    std::string pavarde() const { return pavarde_; }
};

#endif
