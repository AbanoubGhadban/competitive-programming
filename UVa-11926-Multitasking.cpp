#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int n, m, s, e, t;
    bitset<1000001> bs(0);

    while (cin >> n >> m, n + m)
    {
        bs.reset();
        bool conflict = false;
        for (size_t i = 0; i < n; i++)
        {
            cin >> s >> e;
            if (conflict) continue;
            for (size_t j = s; j < e; j++)
            {
                if (bs.test(j)) {
                    conflict = true;
                    break;
                }
                bs.set(j);
            }
        }
        
        for (size_t i = 0; i < m; i++)
        {
            cin >> s >> e >> t;
            if (conflict) continue;
            for (size_t j = s; j <= 1000000; j += t)
            {
                if (conflict) break;
                for (size_t k = 0; k < (e - s); k++)
                {
                    if ((j + k) > 1000000) break;
                    if (bs.test(j + k)) {
                        conflict = true;
                        break;
                    }
                    bs.set(j + k);
                }
            }
        }
        
        if (conflict)
            cout << "CONFLICT" << endl;
        else 
            cout << "NO CONFLICT" << endl;
    }
    
    return 0;
}
