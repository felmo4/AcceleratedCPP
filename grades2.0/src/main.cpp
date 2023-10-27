#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <iomanip>
#include "grade.h"
#include "median.h"
#include "student.h"

using std::cout;    using std::cin;
using std::string;  using std::vector;
using std::istream; using std::sort;
using std::domain_error;    
using std::streamsize;
using std::setprecision;
using std::max;

int main() {

    Student student;
    vector<Student> classlist;
    string::size_type maxlen = 0;

    while (read(cin, student)) {
        maxlen = max(maxlen, student.name.size());
        classlist.push_back(student);
    }

    sort (classlist.begin(), classlist.end(), compare);
    
    for (vector<Student>::size_type c = 0; c != classlist.size(); c++) {
        cout << classlist[c].name 
            << string(maxlen + 1 - classlist[c].name.size(), ' ');
        try {
            double finalgrade = grade(classlist[c]);
            streamsize orig = cout.precision();
            cout << setprecision(3)
                << finalgrade << setprecision(orig);
        } 
        catch (domain_error e) {
            cout << e.what();
        }
        cout << std::endl;    
    }
    cin.get();
    return 0;
}