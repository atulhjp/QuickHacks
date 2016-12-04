// with <3

/*
 * Disjoint Set DS.
 * Union-Find.
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int A[N], SIZE[N];

int ROOT (int i)
{
	while (A[i] != i)
		i = A[A[i]];
	return i;
}

int FIND (int i, int j)
{
	if (ROOT (i) == ROOT (j)) return true;
	return false;
}

void MERGE (int i, int j)
{
	int r = ROOT (i);
	int rr = ROOT (j);

	if (r == rr) return;

	if (SIZE[r] < SIZE[rr]) {
		A[r] = rr;
		SIZE[rr] += SIZE[r];
	} else {
		A[rr] = r;
		SIZE[r] += SIZE[rr];
	}
}

void INIT (void)
{
	for (int i = 0; i < N; i++) {
		A[i] = i;
		SZ[i] = 1;
	}
}
