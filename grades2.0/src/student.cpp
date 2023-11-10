#include "student.h"

using std::cout; using std::cin;
using std::istream;

Student::Student(): midterm(0), final(0) {}
Student::Student(istream& is) { read(is); }

bool compare (const Student& stud1, const Student& stud2) {
    return stud1.name() < stud2.name();
}

istream& read_hw (istream& in, double_con& hw) {
    if(in) {
        hw.clear();
        double x;
        while (in >> x)
            hw.push_back(x);
        in.clear();
    }
    return in;
}

istream& Student::read (istream& in) {
    cout << "Student name: ";
    cin >> n;
    cout << "Midterm grade: ";
    cin >> midterm;
    cout << "Final grade: ";
    cin >> final;
    cout << "Homeworks: \n";
    read_hw (in, homework);
    return in;
}