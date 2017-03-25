/* Treap Data Structure.
 * Operations are in O (log (n))
 * SPOJ: ORDERSET
 */
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int64 long long int
using namespace std;

struct _Node {
	int x;
	int p;
	int size;
	struct _Node *l, *r;
};

typedef struct _Node * Node;

int get (Node c)
{
	return c ? c->size : 0;
}
void upd (Node c)
{
	if (!c) return;
	c->size = get (c->l) + 1 + get (c->r);
}
void merge (Node &c, Node l, Node r)
{
	if (!l or !r) {
		c = l ? l : r;
		upd (c);
		return;
	}
	if (l->p > r->p) {
		merge (l->r, l->r, r);
		c = l;
	} else {
		merge (r->l, l, r->l);
		c = r;
	}
	upd (c);
}
void split (Node c, Node &l, Node &r, int k)
{
	if (!c) {
		l = r = NULL;
		return;
	}
	if (c->x <= k) {
		split (c->r, c->r, r, k);
		l = c;
	} else {
		split (c->l, l, c->l, k);
		r = c;
	}
	upd (c);
}
void insert (Node &c, Node nw)
{
	if (!c) c = nw;
	else if (nw->p <= c->p) {
		split (c, nw->l, nw->r, nw->x);
		c = nw;
	} else insert (c->x < nw->x ? c->r : c->l, nw);
	upd (c);
}
void erase (Node &c, int k)
{
	if (!c) return;
	if (k == c->x) merge (c, c->l, c->r);
	else erase (k > c->x ? c->r : c->l, k);
	upd (c);
}
Node newnode (int x)
{
	Node n = new _Node;
	n->l = n->r = NULL;
	n->size = 1;
	n->x = x;
	n->p = rand ();
	return n;
}
int getkth (Node c, int ix, int offset, int k, bool right)
{
	ix += right ? offset : -offset;
	if (right) ix -= get (c->r);
	else ix += get (c->l);
	if (k == ix) return c->x;
	if (k < ix) {
		return getkth (c->l, ix, get (c->l), k, 0);
	} else {
		return getkth (c->r, ix, get (c->r), k, 1);
	}
}
int getix (Node c, int ix, int offset, int k, bool right)
{
	ix += right ? offset : -offset;
	if (right) ix -= get (c->r);
	else ix += get (c->l);
	if (k == c->x) return ix;
	if (k < c->x) {
		if (!c->l) return ix;
		else return getix (c->l, ix, get (c->l), k, 0);
	} else {
		if (!c->r) return ix + 1;
		return getix (c->r, ix, get (c->r), k, 1);
	}
}
bool fnd (Node c, int x)
{
	if (!c) return false;
	if (c->x == x) return true;
	if (x > c->x) return fnd (c->r, x);
	return fnd (c->l, x);
}
void inorder (Node c)
{
	if (!c) return;
	inorder (c->l);
	printf ("%d ", c->x);
	inorder (c->r);
}
int main (void)
{
	int q;
	srand (time (NULL));
	Node root = NULL;
	scanf ("%d", &q);
	while (q--) {
		int x;
		char op[2];
		scanf ("%s", op);
		if (op[0] == 'I') {
			scanf ("%d", &x);
			Node n = newnode (x);
			if (!root) root = n;
			else if (!fnd (root, x)) insert (root, n);
		} else if (op[0] == 'D') {
			scanf ("%d", &x);
			erase (root, x);
			if (!get (root)) root = NULL;
		} else if (op[0] == 'K') {
			scanf ("%d", &x);
			if (x > get (root)) puts ("invalid");
			else printf ("%d\n", getkth (root, 0, get (root), x, 1));
		} else {
			scanf ("%d", &x);
			printf ("%d\n", root ? getix (root, 0, get (root), x, 1) - 1 : 0);
		}
	}
	return 0;
}
