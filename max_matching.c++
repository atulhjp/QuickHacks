/*
 * Max Matching in Bipartite Graph using
 * kuhn's algorithm. (M Augmenting Path)
 * TC: O(EV)
 */

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int64 long long int
#define uint64 unsigned long long int
using namespace std;

const int N = 1024;
vector <int> G[N];
int n, m, tot, match[N], curr[N];

bool findmatch (int x)
{
	for (int y : G[x]) {
		/* We don't visit same node either on L or R side
		 * when finding an augmenting Path.
		 */
		if (curr[y] == tot) continue;
		curr[y] = tot;
		if (!match[y] or findmatch (match[y])) {
			match[y] = x;
			return true;
		}
	}
	return false;
}
int main (void)
{
	scanf ("%d %d", &n, &m);
	while (m--) {
		int x, y;
		scanf ("%d %d", &x, &y);
		G[x].pb (y);
	}
	int maxmatches = 0;
	for (int i = 1; i <= n; i++) {
		++tot;
		if (findmatch (i)) maxmatches++;
	}
	printf ("%d\n", maxmatches);
	return 0;
}
