#include "trip.h"
#include <vector>
#include <cmath>
using lli = long long int;

int solve(int S, int Q, std::vector<int> A, std::vector<int> B) {
    lli alice{}, bob{};
    for (int i{}; i < Q; ++i) {
        alice += A[i];
        bob += B[i];
        if (S < std::abs(alice - bob)) {
            return 0;
        }
    }
    return 1;
}
