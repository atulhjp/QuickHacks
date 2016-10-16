/* SPOJ: CSTREET
 * Kruskal's Algo with
 * union-find disjoint DS.
 */
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int> > edge;

vector<int> rt;
vector<int> sz;

int root (int i)
{
	while (rt[i] != i)
		i = rt[rt[i]];

	return i;
}

void unite (int i, int j)
{
	int ri = root (i);
	int rj = root (j);
	int szi = sz[ri];
	int szj = sz[rj];

	if (ri == rj)
		return;

	if (szi < szj) {
		rt[ri] = rj;
		sz[ri] = szi + szj + 1;
	} else {
		rt[rj] = ri;
		sz[rj] = szi + szj + 1;
	}
}

int main ()
{
	int t;
	cin >> t;
	while (t--) {
		priority_queue<edge, vector<edge>, greater<edge> > pq;
		int price, N, E;
		cin >> price >> N >> E;

		rt.resize (N+1);
		sz.resize (N+1);

		for (int i = 0; i <= N; i++) {
			rt[i] = i;
			sz[i] = 0;
		}

		for (int i = 0; i < E; i++) {
			int x, y, cost;
			scanf ("%d %d %d", &x, &y, &cost);
			pq.push (make_pair (cost, make_pair (x, y)));
		}

		int added = 0;
		int mst = 0;

		/* Kruskal's Algo */
		while (!pq.empty () && added <= N-1) {
			edge cur = pq.top ();
			pq.pop ();

			int cost = cur.first;
			int u = cur.second.first;
			int v = cur.second.second;

			int rtu = root (u);
			int rtv = root (v);

			if (rtu == rtv)
				continue;

			added += sz[rtu] + sz[rtv] + 1;
			unite (u, v);

			mst += cost;
		}

		cout << price*mst << endl;
	}

	return 0;
}
