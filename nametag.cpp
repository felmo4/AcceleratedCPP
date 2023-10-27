#include <iostream>
#include <string>

using std::cout;    using std::cin;
using std::endl;    using std::string;

int main() {
    string name;
    cout << "What is ur name? ";
    cin >> name;
    const string message = "Hello " + name + "!";

    int pad;
    cout << "Padding: ";
    cin >> pad;

    const int side = 1;
    const int rows = pad * 2 + 3;
    const string::size_type col = message.size() + ((pad + side) * 2) + 2;
    
    cout << endl;
    for(int r = 0; r !=rows; r++){

        string::size_type c = 0;
        while (c != col){
            if(r == pad + 1 && c == (pad + side) + 1){
                cout << message;
                c += message.size();               
            }
            else {
                if (r == 0 || r == rows - 1 || c == 0 || c == col - 1){
                    cout << "*";
                    c++;
                }
                else {
                    if (r == pad + 1){
                        cout << " ";
                        c++;
                    }
                    else {
                        cout << string(col - 2, ' ');
                        c += col - 2;
                    }
                }
                             
            }
        }
        cout << endl;
    }
    return 0;
}