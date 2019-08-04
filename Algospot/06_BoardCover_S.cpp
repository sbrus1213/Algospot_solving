// ALGOSPOT BoardCover ∞‘¿”∆« µ§±‚
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

int row[20], h, w, blank,
	fx[4] = { 1,1,1,1 }, fy[4] = { 0,1,0,0 }, sx[4] = { 0,0,1,1 }, sy[4] = { 1,1,1,-1 };
char board[20][20];

bool checkcolumn(int i, int c) {
	if (i == 3) return c - 1 >= 0;
	return c + 1 < w;
}

int BF() {
	if (!blank) return 1;

	int i, r, c, rv = 0;

	for (i = 0; i < h; ++i)
		if (row[i]) {
			r = i;
			break;
		}

	for (i = 0; i < w; ++i)
		if (board[r][i] == '.') {
			c = i;
			break;
		}

	board[r][c] = '#';
	for (i = 0; i < 4; ++i) {
		int nfx = r + fx[i], nfy = c + fy[i], nsx = r + sx[i], nsy = c + sy[i];

		if (r + 1 < h && checkcolumn(i, c) && board[nfx][nfy] == '.' && board[nsx][nsy] == '.') {

			row[r] -= 1; row[r + 1] -= 1;
			if (i < 2) --row[r];
			else --row[r + 1];
			blank -= 3;

			board[nfx][nfy] = board[nsx][nsy] = '#';
			rv += BF();
			board[nfx][nfy] = board[nsx][nsy] = '.';

			blank += 3;
			row[r] += 1; row[r + 1] += 1;
			if (i < 2) ++row[r];
			else ++row[r + 1];
		}
	}
	board[r][c] = '.';

	return rv;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	int t;

	cin >> t;

	while (t--) {

		int i, j;
		blank = 0;

		cin >> h >> w;
		fill(row, row + 20, 0);

		for (i = 0; i < h; ++i) {
			for (j = 0; j < w; ++j) {

				cin >> board[i][j];

				if (board[i][j] == '.') {
					++blank;
					++row[i];
				}
			}
		}

		if (blank % 3) {
			cout << "0\n";
			continue;
		}

		cout << BF() << '\n';
	}
}