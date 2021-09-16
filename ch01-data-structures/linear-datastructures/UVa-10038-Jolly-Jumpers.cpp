#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int n;
    bitset<3005> is_taken;

    while (cin >> n) {
        int prev, cur;
        cin >> prev;

        for (size_t i = 0; i < n; i++)
            is_taken[i] = 0;
        

        for (size_t i = 1; i < n; ++i) {
            cin >> cur;
            if (abs(prev - cur) < n)
                is_taken[abs(prev - cur)] = 1;
            prev = cur;
        }
        
        bool is_jolly = true;
        for (size_t i = 1; i < n; i++)
            if (!is_taken[i]) {
                is_jolly = false;
                break;
            }
        
        if (is_jolly)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }
    return 0;
}
