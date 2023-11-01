
#include "student.h"
#include "median.h"
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <iostream>
#include <string>

using std::domain_error;    using std::transform;
using std::accumulate;      using std::back_inserter;
using std::remove_copy;     using std::ostream;
using std::string;          using std::stable_partition;

double grade (double midterm, double final, double homework) {
    return (midterm * 0.2) + (final * 0.4) + (homework * 0.4);
}

double grade (double midterm, double final, const double_con& hw) {
    if (hw.size() == 0)
        throw domain_error("Your dumbshit homeworks is empty!");
    return grade (midterm, final, median(hw));
}

double grade (const Student& s) {
    return grade (s.midterm, s.final, s.homework);
}

double grade_aux(const Student& s){
    try{
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

double average(const double_con& con){
    return accumulate(con.begin(), con.end(), 0.0) / con.size();
}

double avg_grade(const Student& s){
    return grade (s.midterm, s.final, average(s.homework));
}

double opt_median(const Student& s){
    double_con nonzero;
    remove_copy (s.homework.begin(), s.homework.end(), 
        back_inserter(nonzero), 0);
    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}

double analysis (const student_con& classlist, double grade_func(const Student&)){
    double_con grades;
    transform (classlist.begin(), classlist.end(), 
        back_inserter(grades), grade_func);
    return median(grades);
}

void write_analysis(ostream& out, const string& name, 
    double grade_func(const Student&),
    const student_con& did, const student_con& didnt){
    out << name << ": median(did)" << analysis(did, grade_func) 
                << ": median(didnt)" << analysis(didnt, grade_func)
                << std::endl;
}

bool fgrade(const Student& s){
    return grade(s) < 60;
}

bool pgrade(const Student& s){
    return !fgrade(s);
}

student_con extract_fails (student_con& classlist){
    student_con::iterator iter = 
        stable_partition(classlist.begin(), classlist.end(), pgrade);
    student_con fails(iter, classlist.end());
    classlist.erase(iter, classlist.end());
    return fails;
}