#include <bits/stdc++.h>

const std::string codeforces{"codeforces"};

int solve(std::string kodeporsez) {
    assert(kodeporsez.size() == codeforces.size());

    int answer{};
    for (int i{}; i < int(kodeporsez.size()); ++i) {
        if (kodeporsez[i] != codeforces[i]) {
            answer++;
        }
    }

    return answer;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        std::string kodeporsez; std::cin >> kodeporsez;
        std::cout << solve(kodeporsez) << '\n';
    }
}