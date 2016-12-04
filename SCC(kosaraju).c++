// with <3

/*
 * SCC (Strongly Connected Components).
 * Kosaraju Algo.
 * SCCs are stored in the array of vectors (Each array index points to one SCC).
 */

#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5 + 5;
int CNT = 0; // SCC index.
bool VISITED[N];
stack<int> STACK;
vector<int> GRAPH_1[N], GRAPH_2[N], SCC[N];

void REVERSE (int n)
{
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < GRAPH_1[i].size (); j++)
			GRAPH_2[GRAPH_1[i][j]].pb (i);
}

void DFS_1 (int i)
{
	if (VISITED[i]) return;
	VISITED[i] = true;
	for (int j = 0; j < GRAPH_1[i].size (); j++) DFS_1 (GRAPH_1[i][j]);
	STACK.push (i);
}

void DFS_2 (int i)
{
	if (VISITED[i]) return;
	VISITED[i] = true;
	SCC[CNT].pb (i);
	for (int j = 0; j < GRAPH_2[i].size (); j++) DFS_2 (GRAPH_2[i][j]);
}

void PASS_1 (int n)
{
	for (int i = 1; i <= n; i++)
		if (!VISITED[i]) DFS_1 (i);
}

void PASS_2 (int n)
{
	REVERSE (n);
	memset (VISITED, false, sizeof VISITED);

	while (!STACK.empty ()) {
		int top = STACK.top ();
		STACK.pop ();

		if (VISITED[top]) continue;

		DFS_2 (top);
		CNT = CNT + 1;
	}
}
