#include <bits/stdc++.h>
using namespace std;


// Recursive function with memoization
int countValidPasswords(int n, int k, char prevChar, int remaining, unordered_map<string, int>& memo) {
    if (remaining == 0) {
        return 1;
    }

    string memoKey = to_string(remaining) + "-" + prevChar;
    if (memo.find(memoKey) != memo.end()) {
        return memo[memoKey];
    }

    int count = 0;

    for (char c = 'a'; c <= 'z'; ++c) {
        if (c != prevChar) {
            count += countValidPasswords(n, k, c, remaining - 1, memo);
        }
    }
    memo[memoKey] = count;

    return count;
}

int main() {
    int n = 2; // Password length
    int k = 2; // Maximum consecutive equal characters

    unordered_map<string, int> memo; // Memoization table

    int result = countValidPasswords(n, k, '\0', n, memo);

    std::cout << "Number of distinct valid passwords: " << result << endl;

    return 0;
}
