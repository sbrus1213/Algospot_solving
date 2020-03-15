// ALGOSPOT Jump Game ¿Ü¹ß ¶Ù±â
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

	int t, board[100][100];
	bool check[100][100];
	cin >> t;
	while (t--) {

		int n, i, j;
		memset(check, false, sizeof(check));

		cin >> n;

		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				cin >> board[i][j];

		check[0][0] = true;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				if (!check[i][j]) continue;

				if (j + board[i][j] < n) check[i][j + board[i][j]] = true;
				if (i + board[i][j] < n) check[i + board[i][j]][j] = true;
			}
		}

		if (check[n - 1][n - 1]) cout << "YES\n";
		else cout << "NO\n";
	}
}