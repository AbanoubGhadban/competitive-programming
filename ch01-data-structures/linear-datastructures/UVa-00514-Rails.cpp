#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool push(stack<int>& s, int needed, int& cur, int n) {
    while ((s.empty() || needed > s.top()) && needed >= cur) {
        s.push(cur++);
    }
    if (s.top() == needed) {
        s.pop();
        return true;
    }
    return false;
}

int main() {
    int n, v;
    while (cin >> n, n) {
        while (true) {
            queue<int> q;
            stack<int> s;
            for (size_t i = 0; i < n; i++) {
                cin >> v;
                if (v == 0) break;
                q.push(v);
            }
            if (q.empty()) break;
            
            for (size_t i = 1; i <= n; i++) {
                s.push(i);
                if (q.front() == i) {
                    while (!q.empty() && !s.empty() && q.front() == s.top()) {
                        q.pop();
                        s.pop();
                    }
                }
            }
            if (q.empty())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        cout << "\n";
    }
}
