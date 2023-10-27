#include "student.h"
#include "median.h"
#include <algorithm>
#include <stdexcept>

using std::domain_error;
using std::sort;    

double median (double_con vec) {
    typedef double_con::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0){
        throw domain_error ("Container is empty!");
    }
    // change this!
    vec.sort();

    // chatgpt saved me here
    vec_sz mid = size / 2;
    auto it = vec.begin();
    std::advance(it, mid);
    return size % 2 != 0 ? *it : (*it + *std::next(it)) / 2;
}
