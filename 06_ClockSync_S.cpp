// ALGOSPOT Clock Sync 시계 맞추기
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

int __clock[16];
vector<vector<int> > button;
int min__, tmp;

void init() {
	button.push_back({ 0,1,2 });
	button.push_back({ 3,7,9,11 });
	button.push_back({ 4,10,14,15 });
	button.push_back({ 0,4,5,6,7 });
	button.push_back({ 6,7,8,10,12 });
	button.push_back({ 0,2,14,15 });
	button.push_back({ 3,14,15 });
	button.push_back({ 4,5,7,14,15 });
	button.push_back({ 1,2,3,4,5 });
	button.push_back({ 3,4,5,9,13 });
}

void click(int cnt) {
	int l, i, j;

	if (cnt == 10) {
		for (i = 0; i < 16; ++i) {
			if (__clock[i])
				break;
		}

		if (i == 16)
			min__ = min(min__, tmp);
		return;
	}

	l = button[cnt].size();
	for (i = 0; i < 4; ++i) {
		if (i) ++tmp;

		click(cnt + 1);

		for (j = 0; j < l; ++j) {
			++__clock[button[cnt][j]];
			__clock[button[cnt][j]] %= 4;
		}
	}
	tmp -= 3;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	int t;

	init();
	cin >> t;

	while (t--) {
		int i;
		min__ = 1e9;
		tmp = 0;

		for (i = 0; i < 16; ++i) {
			cin >> __clock[i];
			__clock[i] = (12 - __clock[i]) % 12;
		}

		click(0);

		if (min__ == 1e9)
			cout << "-1\n";
		else
			cout << min__ << '\n';
	}
}