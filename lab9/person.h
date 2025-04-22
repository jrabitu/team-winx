#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

// Person нь эх класс бөгөөд нэр, нас,  регистрийн дугаар (SSNum) зэрэг мэдээллийг хадгална

class Person{
  protected:
    string name;
    string SSNum;
    int age;

  public:
    Person(); // анхдагч байгуулагч
    Person(string name, string SSNum, int age); //параметртэй байгуулагч
    
    void setName(string name);
    void setSSNum(string SSNum);
    void setAge(int age);

    string getSSNum() const;
    string getName() const;
    int getAge() const;

    virtual void printInfo() const = 0; // pure virtual function
    virtual ~Person(){} //устгагч 
};

#endif