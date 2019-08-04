// ALGOSPOT JLIS гудё LIS
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

int num[2][101], lis[2][101];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	int t;

	cin >> t;
	while (t--) {
		int n, m, i, j, _M = 0;

		memset(lis, 0, sizeof(lis));
		cin >> n >> m;

		for (i = 0; i < n; ++i) cin >> num[0][i];
		for (i = 0; i < m; ++i) cin >> num[1][i];

		i = 0; j = 0;
		while (1) {

		}


		for (i = 0; i < n; ++i) _M = max(_M, lis[0][i]);
		for (i = 0; i < m; ++i) _M = max(_M, lis[1][i]);

		cout << _M << '\n';
	}
}