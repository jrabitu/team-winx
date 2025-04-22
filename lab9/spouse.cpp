#include "spouse.h"
#include <iostream>
using namespace std;

//Анхдагч байгуулагч
Spouse::Spouse() :Person(){
  anniversaryDate="Unknown";
}

//Параметртэй байгуулагч
Spouse::Spouse(string name, string SSNum, int age, string anniversaryDate) : Person(name, SSNum, age) {
    this->anniversaryDate = anniversaryDate;
}

//Setter
void Spouse::setAnniversaryDate(string anniversaryDate) {
    this->anniversaryDate = anniversaryDate;
}

//Getter
string Spouse::getAnniversaryDate() const{
  return anniversaryDate;
}

void Spouse::printInfo() const {
    Person::printInfo(); // Эх классын printInfo-г дуудаж байна
    cout << "Anniversary Date: " << anniversaryDate << endl;
}

Spouse::~Spouse() {
    // Destructor
    cout << "Spouse object destroyed." << endl;
}