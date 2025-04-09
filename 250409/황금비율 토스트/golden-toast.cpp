#include <iostream>
#include <string>
#include <list>
#include <iterator>

using namespace std;

int n, m;
string s;

void printList(list<char> l) {

    for (list<char>::iterator it = l.begin(); it != l.end(); it++) {
        cout << *it;
    }
    cout<<endl;
}

int main() {
    cin >> n >> m;
    cin >> s;

    list<char>::iterator it;
    list<char> v(s.begin(), s.end());

    it = v.end();

    for (int i = 0; i < m; i++) {
        char command;
        cin >> command;

        if (command == 'L') {
            if (it != v.begin()) --it;
        }
        else if (command == 'R') {
            if (it != v.end()) ++it;
        }
        else if (command == 'D') {
            
            if (it != v.end()) {
                it = v.erase(it);           
            }
        }
        else if (command == 'P') {
            char c;
            cin >> c;
            v.insert(it, c);
        }
    }
    for (list<char>::iterator iter = v.begin(); iter != v.end(); ++iter) { cout << *iter; }

    return 0;
}
    