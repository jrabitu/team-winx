#include "employee.h"
#include <iostream>
using namespace std;

// Анхдагч байгуулагч
Employee::Employee() : Person() {
    companyID = "0000";
    title = "Unknown";
    startDate = "0000-00-00";
    division = nullptr;
    spouse = nullptr;
}

// Параметртэй байгуулагч
Employee::Employee(string name, string SSNum, int age,
                   string companyID, string title, string startDate,
                   Division* division, JobDescription* job)
    : Person(name, SSNum, age) {
    this->companyID = companyID;
    this->title = title;
    this->startDate = startDate;
    this->division = division;
    this->spouse = nullptr;
    jobs.push_back(job);
}

// set spouse
void Employee::setSpouse(Spouse* s) {
    spouse = s;
}

// Хүүхэд нэмэх
void Employee::addChild(Child c) {
    children.push_back(c);
}

// Ажил үүрэг нэмэх
void Employee::addJob(JobDescription* job) {
    jobs.push_back(job);
}

// Мэдээлэл хэвлэх
void Employee::printInfo() const {
    cout << "\n------ Ajiltnii medeelel ------" << endl;
    Person::printInfo();
    cout << "Company ID: " << companyID << endl;
    cout << "Job title: " << title << endl;
    cout << "Start date: " << startDate << endl;

    if (division != nullptr) {
        division->printInfo();
    }

    if (spouse != nullptr) {
        cout << "--- Spouse ---" << endl;
        spouse->printInfo();
    } else {
        cout << "Spouse unknown" << endl;
    }

    if (!children.empty()) {
        cout << "--- Children ---" << endl;
        for (const Child& c : children) {
            c.printInfo();
        }
    } else {
        cout << "Child unknown" << endl;
    }

    cout << "--- Job description ---" << endl;
    for (JobDescription* job : jobs) {
        if (job != nullptr) {
            job->printInfo();
        }
    }
}
