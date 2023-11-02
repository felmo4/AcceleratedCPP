#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <map>
#include <vector>

using std::cout;    using std::cin;
using std::string;  using std::getline;
using std::list;    using std::find_if; 
using std::map;     using std::vector;
using std::istream;

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

map<string, vector<int> > xref 
    (istream& in, list<string> find_words(const string&) = split){
        string line;
        int line_number = 0;
        map<string, vector<int> > ret;

        while(getline(in, line)){
            ++line_number;
            list<string> words = find_words(line);

            for(list<string>::const_iterator iter = words.begin();
                iter != words.end(); ++iter)
                    ret[*iter].push_back(line_number);
        }
        return ret;
}

int main() {
    cout << "Type anything multi-lined: ";
    map<string, vector<int> > xref_table = xref(cin);

    for(map<string, vector<int> >::const_iterator iter = xref_table.begin();
        iter != xref_table.end(); ++iter){
            cout << iter->first << " occurs on line(s): ";
            vector<int>::const_iterator line_num = iter->second.begin();
            cout << *line_num;

            ++line_num;
            while(line_num != iter->second.end()){
                cout << ", " << *line_num;
                ++line_num;
            }
            cout << std::endl;
        }
    return 0;
}