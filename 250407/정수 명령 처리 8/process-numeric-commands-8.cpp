#include <iostream>
#include <string>
#include <list>

using namespace std;

int N;
string command[10000];
int A[10000];

int main() {
    cin >> N;

    list<int> s;

    for (int i = 0; i < N; i++) {
        cin >> command[i];
        if (command[i] == "push_front" || command[i] == "push_back") {
            cin >> A[i];
            if (command[i] == "push_front") {
                s.push_front(A[i]);
            }
            else {
                s.push_back(A[i]);
            }
        }
        else if (command[i] == "pop_front" || command[i] == "pop_back") {
            if (command[i] == "pop_front") {
                cout << s.front() << endl;
                s.pop_front();
            }
            else {
                cout << s.back() << endl;
                s.pop_back();
            }
        }
        else if (command[i] == "size") {
            cout << s.size() << endl;
        }

        else if (command[i] == "empty") {
            if (s.empty() == true) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }

        else if (command[i] == "front" || command[i] == "back") {
            if (command[i] == "front") cout << s.front()<<endl;
            else cout << s.back() << endl;
        }

    }

    return 0;
}