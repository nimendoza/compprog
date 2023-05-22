#include <bits/stdc++.h>
using lli = long long int;
using vpii = std::vector<std::pair<int, int>>;

const lli INF(1e10);

std::vector<lli> dijkstra(int& n, int& m, std::vector<vpii>& adjacency_list, int root) {
    std::set<int> unvisited{};
    for (int i{}; i < n; ++i) {
        unvisited.insert(i);
    }

    std::vector<lli> distances(n, INF);
    distances[root] = 0;

    while (unvisited.size()) {
        vpii current_distances{};
        for (int i : unvisited) {
            current_distances.push_back({distances[i], i});
        }

        std::sort(begin(current_distances), end(current_distances));
        
        auto [distance, index] = current_distances[0];
        unvisited.erase(index);
        for (auto [node, dist] : adjacency_list[index]) {
            lli d(lli(distance) + dist);
            if (d < distances[node]) {
                distances[node] = d;
            }
        }
    }

    return distances;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; std::cin >> n;
    int m; std::cin >> m;
    std::vector<vpii> adjacency_list(n, vpii{});
    for (int i{}; i < m; ++i) {
        int a; std::cin >> a;
        int b; std::cin >> b;
        int c; std::cin >> c;
        adjacency_list[--a].push_back({--b, c});
        adjacency_list[b].push_back({a, c});
    }

    for (auto i : dijkstra(n, m, adjacency_list, 0)) {
        std::cout << i << ' ';
    }

    std::cout << '\n';
}