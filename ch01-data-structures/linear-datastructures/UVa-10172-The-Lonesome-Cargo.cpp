#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int t, v, qi;
    cin >> t;
    while (t--) {
        int minutes = 0;
        stack<int> s;
        int N, S, Q;
        cin >> N >> S >> Q;
        vector<queue<int>> qs(N);

        for (size_t i = 0; i < N; i++) {
            cin >> qi;
            for (size_t j = 0; j < qi; j++) {
                cin >> v;
                qs[i].push(v);
            }
        }
        
        bool flag = true;
        while (flag) {
            for (size_t i = 0; i < N; i++) {
                while (s.size() && (s.top() == (i+1) || qs[i].size() < Q)) {
                    if (s.top() != (i+1)) {
                        qs[i].push(s.top());
                    }
                    s.pop();
                    ++minutes;
                }

                while (qs[i].size() && s.size() < S) {
                    s.push(qs[i].front());
                    qs[i].pop();
                    ++minutes;
                }

                flag = !s.empty();
                for (size_t i = 0; i < N; i++)
                    flag |= !qs[i].empty();
                if (flag)
                    minutes += 2;
                else
                    break;
            }
        }

        cout << minutes << endl;
    }


    return 0;
}
