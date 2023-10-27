
#include "student.h"
#include "median.h"
#include <stdexcept>

using std::domain_error;

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