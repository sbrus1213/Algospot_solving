// ALGOSPOT Running Median 변화하는 중간 값
// Heap

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
#define mod 20090711

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	int tc;

	cin >> tc;

	while (tc--) {
		int n;
		ll a, b, seq = 1983, mid, res = 0;
		priority_queue<int> less_max;
		priority_queue<int, vector<int>, greater<int> > greater_min;

		cin >> n >> a >> b;

		for (int i = 0; i < n; ++i) {
			if (less_max.size() == greater_min.size())
				less_max.push(seq);
			else
				greater_min.push(seq);

			if (!less_max.empty() && !greater_min.empty() && less_max.top() > greater_min.top()) {
				int l = less_max.top(), g = greater_min.top();
				less_max.pop(), greater_min.pop();
				less_max.push(g), greater_min.push(l);
			}

			res = (res + less_max.top()) % mod;
			seq = ((seq * a) + b) % mod;
		}

		/*
		res = mid = seq;
		for (int i = 1; i < n; ++i) {
			seq = ((seq * a) + b) % mod;

			if (i % 2) {
				if (seq >= mid) {
					greater_min.push(seq);
				}
				else if (seq<mid && seq>less_max.top()) {
					greater_min.push(mid);
					mid = seq;
				}
				else {
					greater_min.push(mid);
					mid = less_max.top();
					less_max.pop();
					less_max.push(seq);
				}
			}
			else {
				if (seq <= mid) {
					less_max.push(seq);
				}
				else if (seq > mid && seq < greater_min.top()) {
					less_max.push(mid);
					mid = seq;
				}
				else {
					less_max.push(mid);
					mid = greater_min.top();
					greater_min.pop();
					greater_min.push(seq);
				}
			}

			res = (res + mid) % mod;
		}
		*/
		cout << res << '\n';
	}
}