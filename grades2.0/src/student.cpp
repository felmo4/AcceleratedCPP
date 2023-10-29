#include "student.h"
#include <algorithm>

using std::cout; using std::cin;
using std::istream; using std::find;

bool compare (const Student& stud1, const Student& stud2) {
    return stud1.name < stud2.name;
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

istream& read (istream& in, Student& stud) {
    cout << "Student name: ";
    cin >> stud.name;
    cout << "Midterm grade: ";
    cin >> stud.midterm;
    cout << "Final grade: ";
    cin >> stud.final;
    cout << "Homeworks: \n";
    read_hw (in, stud.homework);
    return in;
}

bool did_all_hw(const Student& s){
    return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}