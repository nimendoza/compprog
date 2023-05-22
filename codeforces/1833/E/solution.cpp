#include <bits/stdc++.h>

struct result {
    int minimum;
    int maximum;
};

result solve(int& n, std::vector<int>& a) {
    result answer{};
    std::vector<bool> visited(n, false);
    for (int i{}; i < n; ++i) {
        if ((a[i] - 1) > i && (a[a[i] - 1] - 1) == i) {
            answer.maximum++;
            answer.minimum = 1;
            visited[i] = visited[a[i] - 1] = true;
        }
    }

    for (int i{}; i < n; ++i) {
        if (!visited[i]) {
            int position{i};
            while (!visited[position]) {
                visited[position] = true;
                position = a[position] - 1;
            }

            if (position == i) {
                answer.maximum++;
                answer.minimum++;
            }
        }
    }

    return answer;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        std::vector<int> a(n);
        for (int& x : a) {
            std::cin >> x;
        }

        result answer{solve(n, a)};
        std::cout << answer.minimum << ' ' << answer.maximum << '\n';
    }
}