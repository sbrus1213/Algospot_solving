// ALGOSPOT Picnic ¼ÒÇ³
// Brute Force

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

int ans;
bool checked[10] = { false }, fr[10][10] = { false };

void BF(int n, int cnt, int idx) {

	if (n == cnt) {
		++ans;
		return;
	}

	int i, j;

	for (i = idx; i < n; ++i) {

		if (checked[i]) continue;

		for (j = i + 1; j < n; ++j) {

			if (checked[j]) continue;
			if (!fr[i][j]) continue;

			checked[i] = checked[j] = true;

			if (j == i + 1) 
				BF(n, cnt + 2, i + 2);
			else 
				BF(n, cnt + 2, i + 1);

			checked[i] = checked[j] = false;

		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;

	cin >> t;

	while (t--) {

		int n, m, i;

		cin >> n >> m;
		ans = 0;
		memset(fr, false, sizeof(fr));
		memset(checked, false, sizeof(checked));

		for (i = 0; i < m; ++i) {

			int x, y;

			cin >> x >> y;

			fr[x][y] = true;
			fr[y][x] = true;

		}

		BF(n, 0, 0);

		cout << ans << '\n';

	}
}