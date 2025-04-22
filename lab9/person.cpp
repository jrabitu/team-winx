#include "person.h"
#include <iostream>
using namespace std;

// анхдагч байгуулагч
Person::Person() {
  name = "Unknown";
  SSNum = "XXXXXX";
  age = 0;
}

// параметртэй байгуулагч
Person::Person(string name, string SSNum, int age) {
  this->name=name;
  this->SSNum=SSNum;
  this->age=age;
}

// Setter functions
void Person::setName(string name) { this->name = name;}
void Person::setSSNum(string SSNum){this->SSNum = SSNum;}
void Person::setAge(int age) {this->age = age;}

// Getter functions
string Person::getName() const {return name;}
string Person::getSSNum() const {return SSNum;}
int Person::getAge() const {return age;}

// Print function
void Person::printInfo() const {
  cout << "Name: " << name << endl;
  cout << "SSNum: " << SSNum << endl;
  cout << "Age: " << age << endl;
  cout << "-------------------------" << endl;
}
