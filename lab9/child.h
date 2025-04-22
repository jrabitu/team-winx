#ifndef CHILD_H
#define CHILD_H
#include "person.h"
#include <string>
using namespace std;

// Child класс нь Person классаас удамшсан бөгөөд дуртай тоглоомыг нэмэлтээр хадгална
class Child : public Person {
private:
    string favoriteToy; // дуртай тоглоом

public:
    Child(); // Анхдагч байгуулагч
    Child(string name, string SSNum, int age, string favoriteToy); // Параметрт байгуулагч

    void setFavoriteToy(string favoriteToy);
    string getFavoriteToy() const;

    void printInfo() const override;
    ~Child() override {}
};

#endif
