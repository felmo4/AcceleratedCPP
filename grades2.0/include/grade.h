#ifndef GUARD_grade_h
#define GUARD_grade_h

#include "student.h"

double grade (double, double, double);
double grade (double, double, const double_con&);
double grade (const Student&);
double grade_aux(const Student&);
double median_analysis(const student_con&);
double average(const double_con&);
double avg_grade(const Student&);
double avg_analysis(const student_con&);
double opt_median(const Student&);
double opt_median_analysis (const student_con&);
void write_analysis(std::ostream&, const std::string&, 
    double (const student_con&),
    const student_con&, const student_con&);
bool fgrade(const Student&);
bool pgrade(const Student&);
student_con extract_fails (student_con&);

#endif