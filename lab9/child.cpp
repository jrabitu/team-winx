#include "child.h"
#include <iostream>
using namespace std;

//Анхдагч байгуулагч
Child::Child() : Person() {
    favoriteToy = "Unknown Toy";
}

Child::Child(string name, string SSNum, int age, string toy) : Person(name, SSNum, age) {
    favoriteToy = toy;
}

// Setter
void Child::setFavoriteToy(string toy) {favoriteToy = toy;}

// Getter
string Child::getFavoriteToy() const {return favoriteToy;}

// Print function
void Child::printInfo() const {
  Person::printInfo(); // Эх классын мэдээллийг хэвлэх
  cout << "Favorite toy: " << favoriteToy << endl;

}
