/* Fenwick tree: Range update and
 * point queries.
 * SPOJ: UPDATEIT
 */


#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL tree[10005];

//PS

void update (int idx, int val, int N)
{
	int index = idx;

	while (index <= N) {
		tree[index] += val;

		index += index & (-index);
	}
		
}

void update_range (int low, int high, int val, int N)
{
	update (low, val, N);
	update (high+1, -val, N);
}

LL query (int idx)
{
	LL sum = 0;

	for (int index = idx; index > 0; index -= index & (-index)) sum += tree[index];

	return sum;
}

int main ()
{
	int t;

	scanf ("%d", &t);
	while (t--) {
		int N;
		LL u;

		memset (tree, 0, 10005*(sizeof (LL)));

		scanf ("%d %lld", &N, &u);
		while (u--) {
			int l, r, val;
			scanf ("%d %d %d", &l, &r, &val);
			update_range (l+1, r+1, val, N);
		}

		int q;
		scanf ("%d", &q);
		while (q--) {
			int idx;
			scanf ("%d", &idx);
			printf ("%lld\n", query (idx+1));
		}
	}

	return 0;
}
