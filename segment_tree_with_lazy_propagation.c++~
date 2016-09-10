/* (c) ps */
/* SPOJ: HORRIBLE */
/* Segment tree Using lazy propagation */

#include <bits/stdc++.h>
#define LL unsigned long long
#define L long long
#define MAX 4000005
using namespace std;

LL tree[MAX];
L lazy[MAX];

LL query (L low, L high, L l, L r, L index)
{
	if (lazy[index] != 0) {
		tree[index] += (high-low + 1)*lazy[index];

		if (low != high) {
			lazy[2*index] += lazy[index];
			lazy[2*index + 1] += lazy[index];
		}
		
		lazy[index] = 0;
	}

	if (r<low || l > r || l>high)
		return 0;

	if (l <= low && r >= high)
		return tree[index];

	L mid = (low+high)/2;

	return (query (low, mid, l, r, 2*index) + query (mid+1, high, l, r, 2*index + 1));
}

void update (L low, L high, L l, L r, L val, L index)
{
	if (lazy[index] != 0) {
		tree[index] += (high - low + 1)*lazy[index];

		if (high != low) {
			lazy[2*index] += lazy[index];
			lazy[2*index + 1] += lazy[index];
		}

		lazy[index] = 0;
	}

	if (r<low || l > r || l>high)
		return;

	L mid = (low+high)/2;

	if(l <= low && r >= high) {
		tree[index] += (high-low+1)*(val);
		if(high != low) {
			lazy[index*2] += val;
			lazy[index*2 + 1] += val;
		}
		return;
	}

	update (low, mid, l, r, val, 2*index);
	update (mid+1, high, l, r, val, 2*index + 1);

	tree[index] = tree[2*index] + tree[2*index + 1];
}

int main ()
{
	int t;

	cin >> t;
	while (t--) {
		L len, comm;

		memset (tree, 0, sizeof (tree));
		memset (lazy, 0, sizeof (lazy));

		scanf ("%lld %lld", &len, &comm);
		while (comm--) {
			int first;

			scanf ("%d", &first);

			if (first == 0) {
				L low, high, val;
				scanf ("%lld %lld %lld", &low, &high, &val);

				update (1, len, low, high, val, 1);

			} else if (first == 1) {
				L low, high;
				scanf ("%lld %lld",&low, &high);

				cout << query (1, len, low, high, 1) << endl;
			}
		}
	}

	return 0;
}
