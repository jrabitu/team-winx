#ifndef DIVISION_H
#define DIVISION_H
#include <string>
using namespace std;

// Division класс нь байгууллагын хэлтсийн нэр болон ID-г хадгална
class Division {
private:
    string divisionName;

public:
    Division();
    Division(string name);

    void setDivisionName(string name);
    string getDivisionName() const;

    void printInfo() const;
};

#endif
