#include <iostream>
#include <string.h>

using namespace std;


int main() {
    int n;
    char line[10005];
    cin >> n;
    while (n--) {
        double char_prices[270];
        memset(char_prices, 0, sizeof(char_prices));
    
        int k;
        cin >> k;
        char c;
        double price;
        while (k--) {
            cin >> c >> price;
            char_prices[c + 128] = price; // added 128 to prevent avoid indices
        }

        int num_lines;
        cin >> num_lines;
        double total = 0;
        cin.ignore();
        while (num_lines--) {
            fgets(line, 10005, stdin);
            for (char *c = line; *c; ++c) {
                total += char_prices[(*c) + 128];
            }
        }

        printf("%.2lf$\n", total/100.0);
    }
    return 0;
}
