// ALGOSPOT Traversal 트리 순회 순서 변경
// Tree

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
#define Pll pair<ll, ll>
#define Psi pair<string, int>
#define Tii tuple<int, int, int>

int n;
vector<int> pre, in, post;

void postorder(int pre_idx, int l, int r) {
	if (pre_idx == n || l > r) return;
	if (l == r) {
		post.push_back(pre[pre_idx]);
		return;
	}

	int i, j;

	for (i = pre_idx, j = l; j < n && pre[i] != in[j];) {
		++j;
	}

	if (l <= j - 1) postorder(i + 1, l, j - 1);
	if (j + 1 <= r)postorder(i + j - l + 1, j + 1, r);

	post.push_back(pre[i]);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	int tc;

	cin >> tc;

	while (tc--) {
		post.clear();

		cin >> n;
		pre.resize(n);
		in.resize(n);

		for (int i = 0; i < n; ++i) cin >> pre[i];
		for (int i = 0; i < n; ++i) cin >> in[i];

		postorder(0, 0, n - 1);

		for (int i = 0; i < n; ++i) cout << post[i] << ' ';
		cout << '\n';
	}
}