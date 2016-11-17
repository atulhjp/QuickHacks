// with <3

/*
 * SUFFIX ARRAY O(nlog^2n)
 * LCP (Kasai's) O(n)
 *
 * Code Snippet.
 * Input C-string into S and invoke SUFFIXARRAY (strlen (S)) fron wherever you want.
 */

#include <bits/stdc++.h>
using namespace std;

const int M = 60000;

int STEP, N;
char S[M];
int SA[M], RANK[M], TMP[M], LCP[M];

bool cmp (int i, int j)
{
	if (RANK[i] != RANK[j])
		return RANK[i] < RANK[j];
	else {
		i += STEP;
		j += STEP;
		// If i has reached out of the bound first i.e i is shorter in len (hence Lexical smaller).
		return (i < N && j < N) ? RANK[i] < RANK[j] : i > j;
	}
}

void SUFFIXARRAY (int N)
{
	for (int i = 0; i < N; i++) {
		SA[i] = i;
		RANK[i] = S[i];
	}

	for (STEP = 1; ; STEP *= 2) {
		sort (SA, SA + N, cmp);

		for (int j = 0; j < N - 1; j++)
			TMP[j + 1] = TMP[j] + cmp (SA[j], SA[j + 1]);
		for (int j = 0; j < N; j++)
			RANK[SA[j]] = TMP[j];

		if (TMP[N - 1] == N - 1) break;
	}

	/* Kasai's Algo for LCP construction */
	for (int i = 0, k = 0; i < N; i++) {
		if (RANK[i] != N - 1) {
			for (int j = SA[RANK[i] + 1]; S[i + k] == S[j + k];) ++k;
			LCP[RANK[i]] = k;
			if (k)--k;
		}
	}
}

/* -----------------------------------------------------------------------------------*/
