// ALGOSPOT Tirangle Path 삼각형 위의 최대 경로
// Dynamic programming

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <set>
#include <tuple>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;
#define ll	long long
#define BtoE(vec) vec.begin(), vec.end()
#define Pii pair<int, int>
#define Psi pair<string, int>
#define Tii tuple<int, int, int>

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	int t;
	vector<vector<int> > vec(100), dp(100);
	for (int i = 0; i < 100; ++i) {
		vec[i].resize(i + 1);
		dp[i].resize(i + 1);
	}

	cin >> t;
	while (t--) {
		int n, i, j, M = 0;

		cin >> n;

		for (i = 1; i <= n; ++i)
			for (j = 0; j < i; ++j)
				cin >> vec[i - 1][j];

		dp[0][0] = vec[0][0];
		for (i = 1; i < n; ++i) {
			for (j = 0; j <= i; ++j) {
				if (!j)
					dp[i][j] = dp[i - 1][j] + vec[i][j];
				else if (j == i)
					dp[i][j] = dp[i - 1][j - 1] + vec[i][j];
				else
					dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + vec[i][j];
			}
		}

		for (i = 0; i < n; ++i)
			M = max(M, dp[n - 1][i]);

		cout << M << '\n';
	}
}