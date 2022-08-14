#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;

const int MAX_STUDENTS = 3;

class StudentMaster
{
public:
    virtual void showStudentName() = 0;
    virtual ~StudentMaster() {}
};

class Student : public StudentMaster
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

class NullStudent : public StudentMaster
{
public:
    void showStudentName()
    {
        cout << "Invalid student\n";
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

    StudentMaster *getStudent(string name)
    {
        StudentMaster *ob;
        for (auto student : student_name)
        {
            if (!name.compare(student))
            {
                ob = new Student(name);
                return ob;
            }
        }
        ob = new NullStudent();
        return ob;
    }
};

int main(void)
{
    StudentDb sdb;
    StudentMaster *std1 = sdb.getStudent("Mark");
    StudentMaster *std2 = sdb.getStudent("Jen");
    StudentMaster *std3 = sdb.getStudent("Angie");
    StudentMaster *std4 = sdb.getStudent("Julie");

    std1->showStudentName();
    std2->showStudentName();
    std3->showStudentName();
    std4->showStudentName();

    delete std1;
    delete std2;
    delete std3;
    delete std4;
}