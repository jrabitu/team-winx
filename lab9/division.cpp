#include "division.h"
#include <iostream>
using namespace std;

//анхдагч байгуулагч
Division::Division() {
  divisionName = "Unknown";
}

///параметртэй байгуулагч
Division::Division(string name) {divisionName = name;}

// Setter function
void Division::setDivisionName(string name) {divisionName = name;}

// Getter function
string Division::getDivisionName() const {return divisionName;}

// Print function
void Division::printInfo() const {
    cout << "Division - Name: " << divisionName << endl;
}