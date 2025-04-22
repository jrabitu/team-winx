#include "jobdescription.h"
#include <iostream>
using namespace std;

// Анхдагч байгуулагч
JobDescription::JobDescription() {
    description = "Unknown job description";
}

// Параметрт байгуулагч
JobDescription::JobDescription(string description) {
    this->description = description;
}

// setter
void JobDescription::setDescription(string description) {
    this->description = description;
}

// getter
string JobDescription::getDescription() const {
    return description;
}

// Хэвлэх функц
void JobDescription::printInfo() const {
    cout << "Job description: " << description << endl;
}
