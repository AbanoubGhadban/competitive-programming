#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<int> first, second;
    long long n, median;

    while (cin >> n) {
        if (second.size() == 0) {
            if (first.size() == 0)
                median = n;
            first.insert(n);
        } else {
            if (n > median)
                second.insert(n);
            else
                first.insert(n);
        }

        if (first.size() - second.size() == 2) {
            long long tmp = *std::prev(first.end());
            first.erase(std::prev(first.end()));
            second.insert(tmp);
        } if (second.size() - first.size() == 2) {
            long long tmp = *second.begin();
            second.erase(second.begin());
            first.insert(tmp);
        }
        
        if (first.size() == second.size())
            median = (*std::prev(first.end()) + *second.begin())/2;
        else if (first.size() - second.size() == 1)
            median = *std::prev(first.end());
        else if (second.size() - first.size() == 1)
            median = *second.begin();
        cout << median << endl;
    }
    
    return 0;
}
