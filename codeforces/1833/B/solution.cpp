#include <bits/stdc++.h>

std::vector<int> solve(int& n, int& k, std::vector<int>& a, std::vector<int>& b) {
    std::sort(begin(b), end(b));

    std::vector<std::pair<int, int>> ai(n);
    for (int i{}; i < n; ++i) {
        ai[i] = {a[i], i};
    }

    std::sort(begin(ai), end(ai));

    std::vector<int> result(n);
    for (int i{}; i < n; ++i) {
        result[ai[i].second] = b[i];
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        int k; std::cin >> k;
        std::vector<int> a(n);
        for (auto& x : a) {
            std::cin >> x;
        }

        std::vector<int> b(n);
        for (auto& x : b) {
            std::cin >> x;
        }

        for (auto x : solve(n, k, a, b)) {
            std::cout << x << ' ';
        }

        std::cout << '\n';
    }
}