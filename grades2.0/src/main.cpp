#include <iostream>
#include <string>
#include <algorithm>
#include "grade.h"
#include "median.h"
#include "student.h"

using std::cout;    using std::cin;
using std::string;  using std::sort;
using std::max;       

int main() {

    Student student;
    student_con did, didnt;
    string::size_type maxlen = 0;

    while (read(cin, student)) {
        maxlen = max(maxlen, student.name.size());

        if (did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }

    if(did.empty()){
        cout << "No student did all the homework!";
        return 1;
    }
    if(didnt.empty()){
        cout << "All student did all their homework!";
        return 1;
    }
    extract_fails(did); extract_fails(didnt);

    // change this!
    sort(did.begin(), did.end(), compare);
    sort(didnt.begin(), didnt.end(), compare);
    
    write_analysis(cout, "Median", grade_aux, did, didnt);
    write_analysis(cout, "Average", avg_grade, did, didnt);
    write_analysis(cout, "Median of homework turned in", opt_median, did, didnt);
    
    return 0;
}