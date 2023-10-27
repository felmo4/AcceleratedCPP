#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using std::cout;    using std::cin;
using std::string;  using std::istream;
using std::vector;  

istream& read_count (istream& in, vector<string>& text, vector<int>& count) {
    string word;
    while (in >> word){

        if(text.size() == 0){
            text.push_back(word);
            count.push_back(1);
        }
        else{
            bool found = false;
            for (vector<string>::size_type t = 0; t != text.size(); t++) {
                if (text[t] == word){
                    count[t]++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                text.push_back(word);
                count.push_back(1);
            }
        }
    }
    return in;
}

int main() {
    cout << "Type anything: ";
    vector<string> text;
    vector<int> count;
    read_count (cin, text, count);
    for (vector<string>::size_type i = 0; i != text.size(); i++) {
        cout << text[i] << std::setw(20 - text[i].size())
        << count[i] << std::endl;
    }
    return 0;
}