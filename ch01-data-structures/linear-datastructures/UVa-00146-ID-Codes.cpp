#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    while (true) {
        string s;
        cin >> s;
        if (s == "#") break;

        bool f = false;
        for (int i = s.size() - 2; i >= 0; --i) {
            if (s[i] < s[i+1]) {
                int minindex = i+1;
                for (int j = s.size() - 1; j > i; --j)
                {
                    if (s[j] < s[minindex] && s[j] > s[i]) {
                        minindex = j;
                    }
                }
                
                char tmpc = s[i];
                s[i] = s[minindex];
                s[minindex] = tmpc;
                sort(s.begin() + i + 1, s.end());
                f = true;
                break;
            }
        }
        if (f) {
            cout << s << endl;
        } else {
            cout << "No Successor" << endl;
        }
    }

    return 0;
}
