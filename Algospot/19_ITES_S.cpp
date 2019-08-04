// ALGOSPOT Ites 외계 신호 분석
// Two pointer & Queue

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
#define div 1<<32

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	int t, i;

	cin >> t;

	for (i = 0; i < t; ++i) {
		int j;
		ll k, n, tmp = 0, temp = 1983, sum = 0, res = 0;
		cin >> k >> n;

		for (j = 0; j < n; ++j) {
			if (!tmp) tmp = 1983;
			else tmp = ((tmp * 214013) + 2531011) % ((ll)div);
			sum += (tmp % 10000) + 1;

			while (sum > k) {
				sum -= (temp % 10000) + 1;
				temp = ((temp * 214013) + 2531011) % ((ll)div);
			}
			if (sum == k)
				++res;
		}

		cout << res << '\n';
	}
}