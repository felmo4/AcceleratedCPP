#include <iostream>
#include <iomanip>
#include <string>

using std::cout;     using std::setw;  
using std::setprecision;

int main() {
    double max = 10;
    int width = std::to_string(max*max).length();
    std::streamsize orig = cout.precision();
    cout << setprecision (10);
    for (double i = 0; i != max; i++){
        cout << i << setw(width) << i*i << std::endl;
    }
    cout.precision(orig);
    return 0;
}