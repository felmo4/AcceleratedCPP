#include <iostream>
#include <vector>

using std::vector;

template <class Ran, class X> 
bool binary_search(Ran begin, Ran end, const X& key){
    while (begin < end){
        Ran mid = begin + (end - begin) / 2;
    if (key < *mid)
        end = mid;
    else if (*mid < key)
        begin = mid + 1;
    else
        return true;
    }
    return false;
}

int main() {
    vector<int> nums = {1,4,6,8,12,56,109};
    std::cout << binary_search(nums.begin(), nums.end(), 9);
    return 0;
}