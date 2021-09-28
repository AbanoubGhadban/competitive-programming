#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int w[1 << 15];
    int p[1 << 15];

    size_t n;
    while (cin >> n) {
        int l = 1 << n;
        for (size_t i = 0; i < l; i++)
            cin >> w[i];
        
        for (size_t i = 0; i < l; i++) {
            bitset<16> bs(i);
            p[i] = 0;
            for (size_t j = 0; j < n; j++) {
                bs.flip(j);
                unsigned long uu = bs.to_ulong();
                p[i] += w[bs.to_ulong()];
                bs.flip(j);
            }
        }
        
        int h[2] = {0, 1};
        for (size_t i = 0; i < l; i++) {
            bitset<16> bs(i);
            for (size_t j = 0; j < n; j++) {
                bs.flip(j);
                if ((p[i] + p[bs.to_ulong()]) > (p[h[0]] + p[h[1]])) {
                    h[0] = i;
                    h[1] = bs.to_ulong();
                }
                bs.flip(j);
            }
        }
        cout << (p[h[0]] + p[h[1]]) << endl;
    }

    return 0;
}
