#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using std::cout;    using std::cin;
using std::string;  using std::getline;
using std::list;    using std::find_if; 


bool space(char c){
    return isspace(c);
}

bool not_space(char c){
    return !isspace(c);
}

list<string> split(const string& s){

    typedef string::const_iterator iter;
    list<string> words;

    iter i = s.begin();
    while (i != s.end()){

        i = find_if(i, s.end(), not_space);

        iter j = find_if(i, s.end(), space);

        if (i != s.end()){
            words.push_back(string(i,j));
            i = j;
        }
    }
    return words;

}


int main() {
    string text;
    cout << "Type anything: "; getline(cin,text);
    list<string> textsplit = split(text);
    cout << "No. of words: " << textsplit.size();
    return 0;
}