#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;


class Student;

class Assignment {
private:
    string name;
    int totalPoints;

public:
    Assignment(const string& assignmentName, int points) : name(assignmentName), totalPoints(points) 
    {
        //no code needed
    }

    friend class Gradebook;
};

class Student {
private:
    string firstName;
    string lastName;
    string studentID;
    vector<int> grades;

public:
    Student(const string& first, const string& last, const string& id)
        : firstName(first), lastName(last), studentID(id)
        {
            //no code needed
        }

    void addGrade(int grade) {
        grades.push_back(grade);
    }

    friend class Gradebook;
};

class Gradebook {
    private:
        vector<Student> students;
        vector<Assignment> assignments;

    public:
        void addStudent(const string& firstName, const string& lastName, const string& studentID) {

            students.emplace_back(firstName, lastName, studentID);
        }

        void addAssignment(const string& assignmentName, int totalPoints) {

            assignments.emplace_back(assignmentName, totalPoints);
        }

        void giveGrade(const string& studentID, const string& assignmentName, int grade) {

            for (auto& student : students) {

                if (student.studentID == studentID) {

                    for (size_t i = 0; i < assignments.size(); ++i) {

                        if (assignments[i].name == assignmentName) {

                            student.addGrade(grade);

                            break;
                        }
                    }
                    break;
                }
            }
        }

        void report() const {
            cout << "Grade Report:\n";

            cout << setw(20) << left << "Student Name" << setw(10) << right << "Student ID";

            for (const auto& assignment : assignments) {

                cout << setw(15) << right << assignment.name;
            }
            cout << "\n";

            for (const auto& student : students) {
                cout << setw(20) << left << (student.firstName + " " + student.lastName) << setw(10) << right << student.studentID;

                for (size_t i = 0; i < assignments.size(); ++i) {

                    if (i < student.grades.size()) {

                        cout << setw(15) << right << student.grades[i];

                    } else {

                        cout << setw(15) << right << "-";

                    }
                }
                cout << "\n";
            }
        }
};

//driver
int main() {

    Gradebook gradebook;

    
    gradebook.addStudent("John", "Donut", "HUG001");
    gradebook.addStudent("Jane", "Smitherson", "HUG002");
    gradebook.addStudent("Josh", "Hutcherson", "HUG003");

    
    gradebook.addAssignment("Assignment 1", 50);
    gradebook.addAssignment("Assignment 2", 100);
    gradebook.addAssignment("Lab 3", 150);

    
    gradebook.giveGrade("HUG001", "Assignment 1", 45);
    gradebook.giveGrade("HUG002", "Assignment 2", 90);
    gradebook.giveGrade("HUG001", "Assignment 1", 48);
    gradebook.giveGrade("HUG002", "Assignment 2", 95);
    gradebook.giveGrade("HUG003", "Assignment 1", 88);
    gradebook.giveGrade("HUG003", "Assignment 2", 75);
    gradebook.giveGrade("HUG003", "Lab 3", 144);
    

    
    gradebook.report();

    return 0;
}