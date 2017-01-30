/*
 * with <3
 * Edmonds-Karp Algorithm O(VE^2)
 * For computing the max-flow
 * in a network.
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int source, sink, RG[N][N], P[N], V[N], MIN[N];

int max_flow (void)
{
	int sum = 0;
	while (true) {
		int cap = 0;
		memset (P, 0, sizeof P);
		memset (V, 0, sizeof V);
		memset (MIN, 0, sizeof MIN);
		queue <int> Queue;
		Queue.push (1);
		V[1] = true; MIN[1] = 1 << 28;

		while (!Queue.empty ()) {
			int cur = Queue.front ();
			Queue.pop ();

			if (cur == sink) {
				int u = P[sink];
				int v = sink;
				cap = MIN[sink];
				while (u) {
					RG[u][v] -= cap;
					RG[v][u] += cap;
					v = u; u = P[u];
				}
				sum += cap;
				break;
			}
					
			for (int i = 0; i < N; i++) {
				if (V[i] or !RG[cur][i]) continue;
				V[i] = true;
				MIN[i] = min (MIN[cur], RG[cur][i]);
				P[i] = cur;
				Queue.push (i);
			}
		}
		if (cap == 0) break;
	}
	return sum;
}
int main (void)
{
	int vertices, edges;
	scanf ("%d %d", &vertices, &edges);
	for (int i = 0; i < edges; i++) {
		int u, v, w;
		scanf ("%d %d %d", &u, &v, &w);
		RG[u][v] = w;
	}
	source = 1, sink = vertices;
	printf ("%d\n", max_flow ());
	return 0;
}
