/*
 * Merge Sort Tree.
 * Build O (nlog (n))
 * O (log (n)) per Query
 * SPOJ: KQUERYO
 */

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int64 long long int
#define unit64 unsigned long long int
using namespace std;

const int N = 30010;
int n, q, A[N];
vector <int> T[4 * N];

void build (int c, int L, int R)
{
	if (L > R) return;
	if (L == R) {
		T[c].pb (A[L]);
		return;
	}
	int m = L + R >> 1;
	build (2 * c, L, m);
	build (2 * c + 1, m + 1, R);
	merge (T[2 * c].begin (), T[2 * c].end (), T[2 * c + 1].begin (), T[2 * c + 1].end (), back_inserter (T[c]));
}

int query (int c, int L, int R, int l, int r, int K)
{
	if (l > R or r < L or L > R) return 0;
	if (l <= L && r >= R)
		return T[c].end () - upper_bound (T[c].begin (), T[c].end (), K);
	int m = L + R >> 1;
	return query (2 * c, L, m, l, r, K) + query (2 * c + 1, m + 1, R, l, r, K);
}

int main ()
{
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) scanf ("%d", A + i);
	build (1, 1, n);
	int ans = 0;
	scanf ("%d", &q);
	while (q--) {
		int i, j, k;
		scanf ("%d %d %d", &i, &j, &k);
		i ^= ans, j ^= ans, k ^= ans;
		ans = query (1, 1, n, i, j, k);
		printf ("%d\n", ans);
	}
	return 0;
}
