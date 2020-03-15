// ALGOSPOT Quad Tree 쿼드 트리 뒤집기 
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

string flipover(string& ori, int& i) {
	string tmp1, tmp2, rv;

	if (ori[i] == 'w' || ori[i] == 'b') {
		rv.push_back(ori[i++]);
		return rv;
	}
	else {
		rv.push_back(ori[i++]);

		for (int k = 0; k < 4; ++k) {
			if (k < 2) tmp1.append(flipover(ori, i));
			else tmp2.append(flipover(ori, i));
		}

		rv.append(tmp2);
		rv.append(tmp1);

		return rv;
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
		int idx = 0;
		string str, res;

		cin >> str;

		res.append(flipover(str, idx));

		cout << res << '\n';
	}
}