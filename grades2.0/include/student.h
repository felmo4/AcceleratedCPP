#ifndef GUARD_student_h
#define GUARD_student_h

#include <iostream>
#include <string>
#include <list>

// Switch your container by modifying:
// the include directive above
// the following 2 typedefs and 
// the 2 sorts in the main & median src files 
typedef std::list<double> double_con; 

struct Student {
    std::string name;
    double midterm, final;
    double_con homework;
};

typedef std::list<Student> student_con;

bool compare (const Student&, const Student&);
std::istream& read (std::istream&, Student&);
std::istream& read_hw (std::istream&, double_con&);

#endif 