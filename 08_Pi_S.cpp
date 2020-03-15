// ALGOSPOT Pi 원주율 외우기
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

string str;
int dp[10001], l;

int level(int idx, int cnt) {
	bool of = true, muf = true, mdf = true, ff = true, cf = true;
	int diff = str[idx + 1] - str[idx];
	char t = str[idx], tt = str[idx + 1];

	for (int i = 1; i < cnt; ++i) {
		if (str[i + idx - 1] != str[i + idx])
			of = false;

		if (str[i + idx - 1] != str[i + idx] - 1)
			muf = false;
		if (str[i + idx - 1] != str[i + idx] + 1)
			mdf = false;

		if (tt != str[i + idx])
			ff = false;
		swap(t, tt);

		if (str[i + idx] - str[i + idx - 1] != diff)
			cf = false;
	}

	if (of) return 1;
	if (muf || mdf) return 2;
	if (ff) return 4;
	if (cf) return 5;
	return 10;
}

int dynamic(int i) {
	if (l - i <= 5) return dp[i] = level(i, l - i);

	int res = 1e9;

	if (l - i >= 8) {
		if (!dp[i + 5]) res = min(res, dynamic(i + 5) + level(i, 5));
		else res = min(res, dp[i + 5] + level(i, 5));
	}
	if (l - i >= 7) {
		if (!dp[i + 4]) res = min(res, dynamic(i + 4) + level(i, 4));
		else res = min(res, dp[i + 4] + level(i, 4));
	}
	if (l - i >= 6) {
		if (!dp[i + 3]) res = min(res, dynamic(i + 3) + level(i, 3));
		else res = min(res, dp[i + 3] + level(i, 3));
	}
	return dp[i] = res;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	int t;

	cin >> t;
	while (t--) {
		cin >> str;
		l = str.size();
		str.resize(l + 2);

		memset(dp, 0, sizeof(dp));

		cout << dynamic(0) << '\n';
	}
}