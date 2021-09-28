#include <iostream>
#include <bitset>

using namespace std;

#define ll long long
int main() {
    ll n;
    while (cin >> n, n) {
        bitset<32> bs(n), a, b;
        int j = 0;
        for (int i = bs._Find_first(); i < bs.size(); i = bs._Find_next(i)) {
            if (j%2)
                b.set(i);
            else
                a.set(i);
            ++j;
        }
        cout << a.to_ulong() << " " << b.to_ulong() << endl;
    }


    return 0;
}
