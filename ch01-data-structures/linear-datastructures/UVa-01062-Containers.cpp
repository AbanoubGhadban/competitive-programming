#include <iostream>
#include <set>

using namespace std;

int main() {
    string s;
    int c;
    int t = 0;
    while (cin >> s && s != "end" && ++t) {
        int num = 0;
        // Set is used because it automatically sort the elements in it
        // So, we can get the nearest stack for the container
        multiset<int> stacks; 

        for (size_t i = 0; i < s.size(); i++) {
            bool found = false;
            c = s[i] - 'A';
            for (set<int>::iterator it = stacks.begin(); it != stacks.end(); ++it) {
                if (*it >= c) {
                    if (*it != c) {
                        stacks.erase(it);
                        stacks.insert(c);
                    }
                    found = true;
                    break;
                }
            }
            if (!found) {
                stacks.insert(c);
            }
        }

        cout << "Case " << t << ": " << stacks.size() << endl;
    }
}
