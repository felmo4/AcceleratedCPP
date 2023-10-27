#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <iomanip>
#include "grade.h"
#include "median.h"
#include "student.h"

using std::cout;    using std::cin;
using std::string;  using std::sort;
using std::istream; 
using std::domain_error;    
using std::streamsize;
using std::setprecision;
using std::max;

int main() {

    Student student;
    student_con classlist;
    string::size_type maxlen = 0;

    while (read(cin, student)) {
        maxlen = max(maxlen, student.name.size());
        classlist.push_back(student);
    }

    // change this!
    classlist.sort(compare);
    
    for (student_con::const_iterator iter = classlist.begin(); 
        iter != classlist.end(); iter++) {
        cout << iter->name 
            << string(maxlen + 1 - iter->name.size(), ' ');
        try {
            double finalgrade = grade(*iter);
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