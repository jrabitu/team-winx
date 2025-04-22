#ifndef SPOUSE_H
#define SPOUSE_H
#include "person.h"
#include <string>
using namespace std;

// Spouse класс нь Person классыг удамшуулсан бөгөөд нэмэлтээр гэрлэсэн огноо хадгална
class Spouse : public Person {
  private:
    string anniversaryDate;  // Гэрлэсэн огноо
  public:
    Spouse(); // анхдагч байгуулагч
    Spouse(string name, string SSNum, int age, string anniversaryDate); // параметртэй байгуулагч

    void setAnniversaryDate(string anniversaryDate);
    string getAnniversaryDate() const;

    void printInfo() const override; // // Person-н printInfo-г override хийнэ
    ~Spouse() override; // устгагч
};

#endif