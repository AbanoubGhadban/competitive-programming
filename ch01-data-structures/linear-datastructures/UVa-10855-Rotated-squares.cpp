#include <iostream>

using namespace std;

bool isMatch(char S[1000][1000], char s[1000][1000], int n, int i, int j) {
    for (size_t ii = 0; ii < n; ii++)
    {
        for (size_t jj = 0; jj < n; jj++)
        {
            if (S[i + ii][j + jj] != s[ii][jj])
                return false;
        }
        
    }
    return true;
}

int getNumMatches(char S[1000][1000], char s[1000][1000], int N, int n) {
    int no = 0;
    for (size_t i = 0; i <= (N - n); i++)
    {
        for (size_t j = 0; j <= (N - n); j++)
        {
            
            if (isMatch(S, s, n, i, j))
                ++no;
        }
        
    }
    return no;
}

int main() {
    int N, n;
    char c;
    char S[1000][1000];
    char s[1000][1000];
    char s90[1000][1000];
    char s180[1000][1000];
    char s270[1000][1000];

    while (cin >> N >> n, n) {
        cin.ignore();
        for (size_t i = 0; i < N; i++)
            fgets(S[i], 1000, stdin);
        
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                cin >> c;
                s[i][j] = c;
                s90[j][n - i - 1] = c;
                s180[n - i - 1][n - j - 1] = c;
                s270[n - j - 1][i] = c;
            }
            cin.ignore();
        }
        
        cout << getNumMatches(S, s, N, n) << " " << getNumMatches(S, s90, N, n) << " "
             << getNumMatches(S, s180, N, n) << " " << getNumMatches(S, s270, N, n) << endl;
    }

    return 0;
}
