#include "student.h"
#include "median.h"
#include <algorithm>
#include <stdexcept>

using std::domain_error;
using std::sort;    

double median (double_con con) {
    typedef double_con::size_type con_sz;
    con_sz size = con.size();
    if (size == 0){
        throw domain_error ("Container is empty!");
    }
    // change this!
    sort(con.begin(), con.end());

    // chatgpt saved me here
    con_sz mid = size / 2;
    auto it = con.begin();
    std::advance(it, mid);
    return size % 2 != 0 ? *it : (*it + *std::next(it)) / 2;
}
