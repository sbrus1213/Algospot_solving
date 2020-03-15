// ALGOSPOT Fence 울타리 잡아내기
// Divide & Conquer

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

int maximum(vector<int>& h, int s, int e) {
	if (s == e)
		return h[s];

	int res, mid = (s + e) / 2, mmid = mid + 1, th;

	res = maximum(h, s, mid);
	res = max(res, maximum(h, mid + 1, e));

	th = min(h[mid], h[mmid]);
	res = max(res, 2 * th);

	while (mid > s || mmid < e) {

	}


}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	int t;

	cin >> t;

	while (t--) {
		int n, i;
		vector<int> height;

		cin >> n;

		for (i = 0; i < n; ++i) cin >> height[i];





	}
}