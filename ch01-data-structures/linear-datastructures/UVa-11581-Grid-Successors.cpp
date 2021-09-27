#include <iostream>

using namespace std;

int main() {
    int t;
    int g[3][3], g2[3][3];
    char c;
    cin >> t;
    cin.ignore();
    while (t--) {
        cin.ignore();
        for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
                cin >> c;
                g[i][j] = c - '0';
            }
            cin.ignore();
        }
    
        int i = -1;
        while (true) {
            bool changed = false;
            for (size_t i = 0; i < 3; i++) {
                for (size_t j = 0; j < 3; j++) {
                    g2[i][j] = i > 0? g[i-1][j] : 0;
                    g2[i][j] += j > 0? g[i][j-1] : 0;
                    g2[i][j] += i < 2? g[i+1][j] : 0;
                    g2[i][j] = (g2[i][j] + (j < 2? g[i][j+1] : 0))%2;
                    if (g[i][j] != g2[i][j])
                        changed = true;
                }
            }
            if (changed)
                ++i;
            else
                break;

            for (size_t i = 0; i < 3; i++)
                for (size_t j = 0; j < 3; j++)
                    g[i][j] = g2[i][j];
        }
        cout << i << endl;
    }
}
