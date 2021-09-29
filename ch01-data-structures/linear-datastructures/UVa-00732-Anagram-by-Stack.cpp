#include <iostream>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

void printPath(vector<char>& path) {
    vector<char>::iterator it = path.begin();
    cout << *it;
    ++it;
    for (; it != path.end(); ++it) {
        cout << " " << *it;
    }
    cout << "\n";
}

void traverse(stack<char> s, queue<char> remaining, queue<char> anagram, vector<char> path, char op) {
    if (op == 'i') { //push
        if (!remaining.size()) return;
        path.push_back('i');
        s.push(remaining.front());
        remaining.pop();
    } else {
        if (!s.size()) return;
        if (anagram.front() != s.top()) return;
        path.push_back('o');
        s.pop();
        anagram.pop();
    }
    if (!anagram.size()) {
        printPath(path);
    } else {
        traverse(s, remaining, anagram, path, 'i');
        traverse(s, remaining, anagram, path, 'o');
    }
}

int main() {
    string s1, s2;
    while (cin >> s1, cin >> s2) {
        cout << "[\n";
        if (s1.size() == s2.size()) {
            stack<char> s;
            queue<char> rem, anagram;
            for (size_t i = 0; i < s1.size(); i++) {
                rem.push(s1[i]);
                anagram.push(s2[i]);
            }
            
            traverse(s, rem, anagram, vector<char>(), 'i');
        }
        cout << "]\n";
    }
    
    return 0;
}
