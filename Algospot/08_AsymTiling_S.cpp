// ALGOSPOT Asym Tiling 비대칭 타일링
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
#define div 1e9+7

int dp1[101], dp2[101];

int dynamic1(int x) {
	if (x == 1) return dp1[x] = 1;
	if (x == 2) return dp1[x] = 2;
	int res = 0;

	if (dp1[x - 1]) res += dp1[x - 1];
	else res += dynamic1(x - 1);
	res %= (int)div;

	if (dp1[x - 2]) res += dp1[x - 2];
	else res += dynamic1(x - 2);
	res %= (int)div;

	return dp1[x] = res;
}

int dynamic2(int x) {
	if (x == 1) return dp2[x] = 1;
	if (x == 2) return dp2[x] = 2;
	if (x == 3) return dp2[x] = 1;
	if (x == 4) return dp2[x] = 3;

	int res = 0;

	if (dp2[x - 2]) res += dp2[x - 2];
	else res += dynamic2(x - 2);
	res %= (int)div;

	if (dp2[x - 4]) res += dp2[x - 4];
	else res += dynamic2(x - 4);
	res %= (int)div;

	return dp2[x] = res;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	int t;

	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));

		int r1 = dynamic1(n), r2 = dynamic2(n);

		if (r1 < r2) r1 += div;
		cout << r1 - r2 << '\n';
	}
}