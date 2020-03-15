// ALGOSPOT Wildcard 와일드카드
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

	int t;
	cin >> t;
	while (t--) {
		string base, tmp;
		int n, i, j, k, lenb, lent;

		cin >> base;
		cin >> n;
		lenb = base.size();

		for (i = 0; i < n; ++i) {
			bool flag = true;
			vector<string> vs;

			cin >> tmp;
			lent = tmp.size();

			j = k = 0;
			while (1) {
				if (j == lenb || k == lent) break;

				if (base[j] == '?') {

				}
				else if (base[j] == '*') {

				}
				else {
					if (base[j] == tmp[k]) {
						++j; ++k;
					}
					else {
						flag = false;
						break;
					}
				}
			}

			if (flag) {
				vs.push_back(tmp);
			}
		}
	}
}