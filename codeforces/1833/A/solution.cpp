#include <bits/stdc++.h>

int solve(int& n, std::string& s) {
    std::set<std::pair<char, char>> notes{{s[0], s[1]}};
    for (int i{1}; i < n - 1; ++i) {
        notes.insert({s[i], s[i + 1]});
    }

    return notes.size();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        std::string s; std::cin >> s;
        
        std::cout << solve(n, s) << '\n';
    }
}