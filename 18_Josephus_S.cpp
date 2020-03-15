// ALGOSPOT Josephus 조세푸스 문제
// Linear data structure

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

struct node
{
	int x;
	node* l, * r;

	node() {
		l = r = NULL;
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		int n, k, i;
		node* lt = NULL;

		cin >> n >> k;

		for (i = 0; i < n; ++i) {
			node* tmp = new node;
			tmp->x = i + 1;

			if (lt) {
				tmp->r = lt->r;
				tmp->l = lt;
				lt->r->l = tmp;
				lt->r = tmp;
			}
			else {
				lt = tmp;
				lt->l = lt->r = lt;
			}

			lt = lt->r;
		}
		lt = lt->r;

		while (n > 2) {
			node* tmp = lt;

			lt->r->l = lt->l;
			lt->l->r = lt->r;
			lt = lt->r;
			delete(tmp);
			--n;

			for (i = 1; i < k; ++i) {
				lt = lt->r;
			}
		}

		int x = lt->x, y;
		lt = lt->r;
		y = lt->x;;

		cout << min(x, y) << ' ' << max(x, y) << '\n';
	}
}