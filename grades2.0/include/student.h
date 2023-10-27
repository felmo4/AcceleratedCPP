#ifndef GUARD_student_h
#define GUARD_student_h

#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare (const Student&, const Student&);
std::istream& read (std::istream&, Student&);
std::istream& read_hw (std::istream&, std::vector<double>&);

#endif 