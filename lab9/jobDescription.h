#ifndef JOBDESCRIPTION_H
#define JOBDESCRIPTION_H
#include <string>
using namespace std;

// JobDescription класс нь ажил үүргийн тодорхойлолтыг хадгална
class JobDescription {
private:
    string description; // ажил үүргийн тодорхойлолт
public:
    JobDescription();
    JobDescription(string description);

    void setJobTitle(string title);
    void setResponsibilities(string resp);

    void setDescription(string description); // setter
    string getDescription() const;           // getter

    void printInfo() const; // Мэдээлэл хэвлэх
};

#endif
