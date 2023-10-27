#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>
#include <iomanip>

using std::cout;    using std::cin;
using std::vector;  using std::sort;

int main(){
    cout << "Type ur midterm and final grades: ";
    double midt, fin;
    cin >> midt >> fin;

    cout << "Type all your homework scores per line:\n";
    double x;
    vector<double> homework;
    while(cin >> x){
        homework.push_back(x);
    }
    
    typedef vector<double>::size_type vsize;
    vsize size = homework.size();
    if(size == 0){
        cout << "Error: must supply homework scores!";
        return 1;
    }
    
    sort(homework.begin(), homework.end());
    vsize mid = size/2;
    double median;
    median = size%2 == 0 ? (homework[mid] + homework[mid+1]) / 2 : homework[mid];

    std::streamsize orig = cout.precision();

    cout << "Your final grade is: " << std::setprecision(3)
            << (fin * 0.4) + (midt * 0.2) + (median * 0.4) 
            << std::setprecision(orig);

    return 0;
}