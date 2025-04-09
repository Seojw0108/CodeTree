#include <iostream>
#include <string>
#include <list>
#include <iterator>

using namespace std;

int n, m;
string s;

int main() {
    cin >> n >> m;
    cin >> s;

    list<char>::iterator it;
    list<char> v;

    for (int i = 0; i < s.length(); i++) {
        v.push_back(' ');
        v.push_back(s[i]);
    }

    it = v.end();

    for (int i = 0; i < m; i++) {
        char command;
        cin >> command;
        if (command == 'P') {
            char c;
            cin >> c;

            it = v.insert(it, c);   // 문자 c 추가
            it = v.insert(it, ' '); // 공백 추가
            
            ++it;
        }
        else if (command == 'L') {
            if (it != v.begin()) {
                --it;
                --it;
            }
        }
        else if (command == 'R') {
            if (it != v.end()) {
                ++it;
                ++it;
            }
        }
        else if (command == 'D') {
            if (it != v.end()) {
                ++it;
                it = v.erase(it);     // 첫 번째 문자 삭제 후 it는 다음 위치로 이동됨
                if (it != v.end()) {
                    it = v.erase(it); // 그 다음 공백 문자 삭제
                }
            }
        }
    }
    for (list<char>::iterator iter = v.begin(); iter != v.end(); ++iter) {

        if (*iter != ' ') {
            cout << *iter;
        }
    }

    return 0;
}
