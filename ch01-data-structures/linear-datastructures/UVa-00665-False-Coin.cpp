#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;


int main() {
    char line[1000];
    int m;
    cin >> m;

    while (m--) {
        int n, k;
        cin >> n >> k;

        unordered_set<int> *suspected = new unordered_set<int>;
        for (size_t i = 0; i < n; i++)
            suspected->insert(i + 1);
        

        while (k--) {
            int p;
            cin >> p;
            cin.ignore();
            fgets(line, 1000, stdin);
            stringstream ss(line);
            string result;
            cin >> result;

            if (result == "=") {
                int c;
                while (ss >> c)
                    suspected->erase(c);
            } else {
                int c;
                unordered_set<int> unbalanced;
                while (ss >> c)
                    unbalanced.insert(c);
                
                unordered_set<int> *tmp = new unordered_set<int>;
                for (unordered_set<int>::iterator it = suspected->begin(); it != suspected->end(); it++)
                {
                    if (unbalanced.find(*it) != unbalanced.end())
                        tmp->insert(*it);
                }
                delete suspected;
                suspected = tmp;
            }
        }

        if (suspected->size() > 1) {
            cout << "0\n";
        } else {
            cout << *suspected->begin() << "\n";
        }

        if (m >= 1)
            cout << "\n";
    }

    return 0;
}
