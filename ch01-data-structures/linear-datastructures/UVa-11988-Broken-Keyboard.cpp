#include <iostream>
#include <list>

using namespace std;

int main() {
    string line;

    while (cin >> line) {
        list<char> l;
        list<char>::iterator cur = l.begin();
        for (size_t i = 0; i < line.size(); i++) {
            if (l.size() == 0 && (line[i] == '[' || line[i] == ']'))
                continue;
            if (line[i] == '[')
                cur = l.begin();
            else if (line[i] == ']')
                cur = l.end();
            else
                l.insert(cur, line[i]);
        }
        for (list<char>::iterator it = l.begin(); it != l.end(); it++) {
            cout << *it;
        }
        cout << endl;
    }

    return 0;
}
