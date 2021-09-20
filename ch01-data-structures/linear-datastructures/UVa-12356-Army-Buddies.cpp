#include <iostream>
#include <set>

using namespace std;


int main() {
    set<int> soldiers;
    int s, b, r, l;
    set<int>::iterator ri, li;

    while (cin >> s >> b && s != 0) {
        for (size_t i = 0; i < s; i++)
        {
            soldiers.insert(i + 1);
        }
        
        for (size_t i = 0; i < b; i++)
        {
            cin >> l >> r;
            li = soldiers.find(l);
            ri = soldiers.find(r);
            
            if (li == soldiers.begin())
                cout << "* ";
            else
                cout << *std::prev(li) << " ";
            if (std::prev(soldiers.end()) == ri)
                cout << "*\n";
            else
                cout << *std::next(ri) << "\n";
            soldiers.erase(li, std::next(ri));
        }
        cout << "-" << endl;
    }

    return 0;
}
