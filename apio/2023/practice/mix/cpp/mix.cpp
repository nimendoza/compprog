#include "mix.h"
#include <assert.h>
#include <set>

std::vector<std::vector<bool>> propose(int X, int K, int M) {
	std::vector<std::vector<bool>> A(M, std::vector<bool>(X, false));
	if (X == 100 && K == 100 && M == 100) {
		for (int i{}; i < M; ++i) {
			A[i][i] = true;
		}
	} else if (X == int(1e4) && K == 1 && M == 500) {
		int k{100};
		for (int i{}; i < X; ++i) {
			A[i % k][i] = true;
			A[k + i / k][i] = true;
		}
	} else if (X == int(1e5) && K == 1 && M == 20) {
		int k{17};
		for (int i{}; i < X; ++i) {
			for (int b{}; b < k; ++b) {
				if ((i >> b) & 1) {
					A[b][i] = true;
				}
			}
		}
	} else if (
		(X == int(1e3) && K == 2 && M == 250)
		|| (X == int(1e3) && K == 2 && M == 60)
		|| (X == int(1e3) && K == 2 && M == 48)
	) {
		int k{10};
		std::set<std::pair<int, int>> comb{};
		for (int i{}; i < k; ++i) {
			for (int j{i + 1}; j < k; ++j) {
				comb.insert({i, j});
			}
		}

		assert(int(comb.size()) == 45);

		for (int i{}; i < X; ++i) {
			int j{};
			for (auto [x, y] : comb) {
				if (((i >> x) & 1) ^ ((i >> y) & 1)) {
					A[j][i] = true;
				}

				++j;
			}
		}
	} else if (X == int(28e3) && K == 4 && M == 170) {
	} else {
		assert(false);
	}

	return A;
}

std::vector<int> detect(int X, int K, int M, const std::vector<std::vector<bool>>& A, const std::vector<bool>& R) {
	std::vector<int> B{};
	if (X == 100 && K == 100 && M == 100) {
	} else if (X == int(1e4) && K == 1 && M == 500) {
	} else if (X == int(1e5) && K == 1 && M == 20) {
	} else if (X == int(1e3) && K == 2 && M == 250) {
	} else if (X == int(1e3) && K == 2 && M == 60) {
	} else if (X == int(1e3) && K == 2 && M == 48) {
	} else if (X == int(28e3) && K == 4 && M == 170) {
	} else {
		assert(false);
	}

	return B;
}