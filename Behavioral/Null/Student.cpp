#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;

const int MAX_STUDENTS = 3;

class Student
{
private:
    string name;

public:
    Student(string name)
    {
        this->name = name;
    }

    void showStudentName()
    {
        cout << "Student name associated to this object is " << this->name << "\n";
    }
};

class StudentDb
{
private:
    std::vector<string> student_name{MAX_STUDENTS};

public:
    StudentDb()
    {
        student_name[0] = "Mark";
        student_name[1] = "Jen";
        student_name[2] = "Angie";
    }

    Student *getStudent(string name)
    {
        for (auto student : student_name)
        {
            if (!name.compare(student))
            {
                return new Student(name);
            }
        }

        return nullptr;
    }
};

int main(void)
{
    StudentDb sdb;
    Student *std1 = sdb.getStudent("Mark");
    Student *std2 = sdb.getStudent("Jen");
    Student *std3 = sdb.getStudent("Angie");
    Student *std4 = sdb.getStudent("Julie");

    if (std1 != nullptr)
    {
        std1->showStudentName();
    }

    if (std2 != nullptr)
    {
        std2->showStudentName();
    }

    if (std3 != nullptr)
    {
        std3->showStudentName();
    }

    if (std4 != nullptr)
    {
        std4->showStudentName();
    }
    else
    {
        cout << "Invalid student\n";
    }
}