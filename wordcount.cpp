#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <map>

using std::cout;    using std::cin;
using std::string;  using std::istream;
using std::vector;  using std::map;
using std::iterator;

// using two vectors
istream& count_vector (istream& in, vector<string>& text, vector<int>& count) {
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

    for (vector<string>::size_type i = 0; i != text.size(); i++) {
        cout << text[i] << std::setw(20 - text[i].size())
        << count[i] << std::endl;
    }
    return in;
}

// using a map
void count_map (istream& in, map<string, int>& wordcount){
    string text;
    while(cin >> text){
        ++wordcount[text];
    }
    for (map<string, int>::const_iterator iter = wordcount.begin();
        iter != wordcount.end(); ++iter){
            cout << iter->first << "\t" << iter->second << "\n";
        }
}

int main() {
    cout << "Type anything: ";
    map<string, int> wordcount;
    count_map (cin, wordcount);
    return 0;
}