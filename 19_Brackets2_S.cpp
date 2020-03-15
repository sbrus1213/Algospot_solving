// ALGOSPOT Brackets Â¦ÀÌ ¸ÂÁö ¾Ê´Â °ýÈ£
// Stack

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
		string str;
		int i, l;
		vector<char> vec;

		cin >> str;
		l = str.size();

		for (i = 0; i < l; ++i) {
			if (str[i] == '(' || str[i] == '{' || str[i] == '[')
				vec.push_back(str[i]);
			else if (str[i] == ')') {
				if (!vec.empty() && vec.back() == '(')
					vec.pop_back();
				else break;
			}
			else if (str[i] == '}') {
				if (!vec.empty() && vec.back() == '{')
					vec.pop_back();
				else break;
			}
			else if (str[i] == ']') {
				if (!vec.empty() && vec.back() == '[')
					vec.pop_back();
				else break;
			}
		}
		if (i != l || !vec.empty())
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}