#include <iostream>
#include <vector>
#include <cstring>

using std::cout;    using std::cin;
using std::vector;  

class Str{
    friend std::istream& operator>>(std::istream&, Str&);
    public:
        typedef vector<char>::size_type size_type; 
        
        Str() {}
        Str(size_type n, char c): data(n, c) {}
        Str(const char* cp){
            std::copy(cp, cp + strlen(cp), std::back_inserter(data));
        }
        template <class In> Str (In b, In e){
            std::copy(b, e, std::back_inserter(data));
        }

        size_type size() const{ return data.size(); }
        char& operator[](size_type i) { return data[i]; }
        const char& operator[](size_type i) const { return data[i]; }

        Str& operator+=(const Str& s){
            std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
            return *this;
        }

    private:
        vector<char> data;
};

std::ostream& operator<<(std::ostream& os, const Str& s){
    for(Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}

std::istream& operator>>(std::istream& is, Str& s){
    s.data.clear();
    char c;
    while(is.get(c) && isspace(c));

    if (is){
        do s.data.push_back(c);
        while(is.get(c) && !isspace(c));

        if(is)
            is.unget();
    }
    return is;
}

Str operator+ (const Str& s, const Str& t){
    Str ret = s;
    ret += t;
    return ret;    
}

int main(){

    Str hello;
    cin >> hello;
    cout << hello + hello;

    return 0;
}

// EXERCISE: recreate how the string library makes a 
// character array copy of a string (c_str(), data(), copy(p,n))