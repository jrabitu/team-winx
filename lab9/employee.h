#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "person.h"
#include "spouse.h"
#include "child.h"
#include "division.h"
#include "jobDescription.h"
#include <vector>
using namespace std;

// Employee класс нь Person-оос удамшиж,
// Employee класс нь ажилтаны компанид харьяалагдах бүх мэдээллийг агуулна

class Employee : public Person {
private:
  string companyID;
  string title;
  string startDate;
  Spouse* spouse;                  // 0..1
  vector<Child> children;          // 0..n
  Division* division;              // 1
  vector<JobDescription*> jobs;    // 1..n

public:
  Employee();
  Employee(string name, string SSNum, int age,
    string companyID, string title, string startDate,
    Division* division, JobDescription* job);

  void setSpouse(Spouse* s);
  void addChild(Child c);
  void addJob(JobDescription* job);

  void printInfo() const override;
  ~Employee() override {}
};

#endif
