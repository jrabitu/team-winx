#include <iostream>
#include "division.h"
#include "jobdescription.h"
#include "spouse.h"
#include "child.h"
#include "employee.h"

using namespace std;

int main() {
    // Divisions
    Division it("IT Department");
    Division hr("HR Department");

    // Job Descriptions
    JobDescription dev("Code bichih bolon zaswarlah.");
    JobDescription mgr("Bag udirdah hynah, ajild chiglel uguh.");
    JobDescription hrRep("Ajilchdiin hariltsaag zohitsuulah.");

    // Spouses
    Spouse s1("Saraa", "SS123456", 29, "2018-05-12");
    Spouse s2("Naraa", "SS654321", 31, "2020-10-30");

    // Children
    Child c1("Nami", "CH111111", 5, "Doll");
    Child c2("Ruby", "CH222222", 7, "Lego");
    Child c3("Shiki", "CH333333", 4, "Crayons");

    // Employees
    Employee e1("Bat", "EE1001", 35, "C001", "Developer", "2020-01-01", &it, &dev);
    e1.setSpouse(&s1);
    e1.addChild(c1);
    e1.addChild(c2);
    e1.addJob(&mgr);

    Employee e2("Saruul", "EE1002", 28, "C002", "HR", "2021-03-15", &hr, &hrRep);
    e2.setSpouse(&s2);
    e2.addChild(c3);

    Employee e3("Bold", "EE1003", 40, "C003", "Manager", "2018-07-20", &it, &mgr);

    // Print all
    cout << "\n--- Ajiltnii medeelel ---\n" << endl;
    e1.printInfo();
    cout << endl;
    e2.printInfo();
    cout << endl;
    e3.printInfo();
    cout << endl;

    return 0;
}