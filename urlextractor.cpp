#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;    using std::cin;     using std::getline;
using std::string;  using std::vector;  using std::find_if;
using std::find;    using std::search;

typedef string::const_iterator iter;

bool not_url_ch(char c){
    static const string url_ch= "~;/?:@=&$-_.+*'(),";
    return !(isalnum(c) || 
        find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

iter url_end (iter b, iter e){
    return find_if(b, e, not_url_ch);
}

iter url_beg(iter b, iter e){
    static const string sep = "://";
    iter i = b;
    while((i = search(i, e, sep.begin(), sep.end())) != e){
       
        if (i != b && i+sep.size() != e){
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                --beg;
            if (beg != i && !not_url_ch(i[sep.size()])){
                return beg;
            }
        }
        i += sep.size();
    }
    return e;
}

vector<string> get_url(const string& s) {
    vector<string> ret;
    iter b = s.begin(), e = s.end();
    while (b != e){
        b = url_beg(b, e);

        if(b != e){
            iter after = url_end(b,e);
            ret.push_back(string(b, after));
            b = after;
        }
    }
    return ret;
}

int main() {
    string text;
    cout << "Type something with URL: "; getline (cin, text);
    vector<string> urls = get_url(text);
    
    cout << "URLs extracted: ";
    for(vector<string>::const_iterator it = urls.begin(); it != urls.end(); ++it){
        cout << "\n" << *it;
    }

    return 0;
}