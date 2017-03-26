/*
 * Articulation Points.
 * O (n) using single DFS.
 * SPOJ: SUBMERGE
 */
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int64 long long int
using namespace std;

const int N = 1e4 + 5;
vector <int> G[N];
int n, m, timer, ans, S[N], L[N], V[N], AP[N];

void dfs (int u, int p)
{
	int c = 0;
	S[u] = L[u] = ++timer;
	for (int x : G[u]) {
		if (x == p) continue;
		if (S[x]) L[u] = min (L[u], S[x]);
		else {
			dfs (x, u);
			L[u] = min (L[u], L[x]);
			if (L[x] >= S[u] && p > 0) AP[u] = true;
			c++;
		}
	}
	if (c > 1 && p == -1) AP[u] = true;
}
void solve ()
{
	timer = ans = 0;
	scanf ("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) {
		V[i] = AP[i] = false;
		G[i].clear ();
		L[i] = S[i] = 0;
	}
	if (n == m && n == 0) exit (0);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		G[x].pb (y);
		G[y].pb (x);
	}
	dfs (1, -1);
	int c = 0;
	for (int i = 0; i <= n; i++) if (AP[i]) c++;
	printf ("%d\n", c);
}
int main ()
{
	int t;
	while (true) solve ();
	return 0;
}
