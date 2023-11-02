#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stdexcept>

using std::cout;    using std::cin;
using std::vector;  using std::map;
using std::string;  using std::istream;
using std::find_if; using std::logic_error;
using std::domain_error;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collect;
typedef map<string, Rule_collect> Grammar;

bool space(char c){
    return isspace(c);
}

bool not_space(char c){
    return !isspace(c);
}

vector<string> split (const string& text){
    vector<string> ret;
    typedef string::const_iterator iter;
    iter i = text.begin();
    while (i != text.end()){
        i = find_if(i, text.end(), not_space);

        iter j = find_if(i, text.end(), space);
        if(i != text.end()){
            ret.push_back(string(i, j));
            i=j;
        }
    }
    return ret;
}
 
Grammar read_grammar(istream& in){
    Grammar ret;
    string text;
    while (getline(in, text)){
        vector<string> entry = split(text);
        if(!entry.empty())
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }
    return ret;
}

bool bracketed(const string& s){
    return s.size() > 1 && s[0] == '<' && s[s.size()-1] == '>';
}

int nrand(int n){
    if(n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range!");
    const int bucket_size = RAND_MAX / n;
    int r;

    do r = rand() / bucket_size;
    while (r >= n);

    return r;
}

void gen_aux (const Grammar& g, const string& word, vector<string>& ret){
    if (!bracketed(word)){
        ret.push_back(word);
    } else {
        Grammar::const_iterator iter = g.find(word);
        if(iter == g.end())
            throw logic_error("Empty rule!");
        
        const Rule_collect& c = iter->second;
        const Rule& r = c[nrand(c.size())];

        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, ret);
    }
}

vector<string> gen_sentence(const Grammar& g){
    vector<string> ret;
    gen_aux(g,"<sentence>", ret);
    return ret;
}

int main(){
    vector<string> sentence = gen_sentence(read_grammar(cin));

    vector<string>::const_iterator iter = sentence.begin();
    if (!sentence.empty()) {
        cout << *iter;
        ++iter;
    }

    while (iter != sentence.end()){
        cout << " " << *iter;
        ++iter;
    }

    cout << std::endl;
    return 0;
}