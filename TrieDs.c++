/* SPOJ: PHONELST
 * TRIE Data Structure.
 */

#include <bits/stdc++.h>

using namespace std;

struct node {
	int n;
	struct node * links[10];
};

struct node * create_node (void)
{
	struct node * tmp = (struct node *) malloc (sizeof (struct node));
	tmp-> n = 0;
	memset (tmp->links, 0, sizeof (tmp->links));

	return tmp;
}

bool insert (string str, struct node * root)
{
	bool ret = true;

	int idx = 0;
	struct node * current = root;

	while (idx < str.length ()) {
		if (current->n == -1)
			ret = false;

		if (current->links[str[idx] - '0']) {
			current = current->links[str[idx] - '0'];
			idx++;
		} else {
			current->links[str[idx] - '0'] = create_node ();
			current = current->links[str[idx] - '0'];
			idx++;
		}
	}

	if (current->n == -1)
		ret = false;
	else {
		current->n = -1;
		for (int i = 0; i <= 9; i++) {
			if (current->links[i])
				ret = false;
		}
	}

	return ret;
}

int main ()
{
	int t;
	scanf ("%d", &t);
	while (t--) {
		bool flag = true;
		struct node *root = create_node ();

		int N;
		scanf ("%d", &N);

		while (N--) {
			string input;
			cin >> input;

			bool ret = insert (input, root);
			if (!ret)
				flag = false;

		}

		if (flag)
			printf ("YES\n");
		else
			printf ("NO\n");
	}

	return 0;
}
