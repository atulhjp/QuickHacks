/*
 * Suffix Automation.
 * Longest Common Substring.
 * TC: O (N)
 * CODECHEF: SSTORY
 */
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int64 long long int
#define uint64 unsigned long long int
using namespace std;

const int N = 5e5 + 123;
string S1, S2;
int ptr = 1, last;

struct Node {
	int link = -1;
	int len = 0;
	map <char, int> to;
} A[N];

void extend (char x)
{
	int cur = ptr++;
	int parent = last;
	A[cur].len = A[last].len + 1;
	last = cur;

	for ( ; parent != -1 && !A[parent].to[x]; parent = A[parent].link)
		A[parent].to[x] = cur;
	if (parent == -1) {
		A[cur].link = 0;
		return;
	}
	int next = A[parent].to[x];
	if (A[next].len == A[parent].len + 1) {
		A[cur].link = next;
		return;
	}
	int copy = ptr++;
	A[copy] = A[next];
	A[cur].link = A[next].link = copy;
	A[copy].len = A[parent].len + 1;
	for ( ; parent != -1 && A[parent].to[x] == next; parent = A[parent].link)
		A[parent].to[x] = copy;
}
int main ()
{
	ios_base::sync_with_stdio (NULL);
	cin >> S1 >> S2;
	for (int i = 0; i < S1.size (); i++) extend (S1[i]);
	int cur = 0, mx = 0, len = 0, pos = 0;
	for (int i = 0; i < S2.size (); i++) {
		while (cur && !A[cur].to[S2[i]]) {
			cur = A[cur].link;
			len = A[cur].len;
		}
		if (A[cur].to[S2[i]]) {
			cur = A[cur].to[S2[i]];
			len++;
		}
		if (len > mx) mx = len, pos = i;
	}
	if (!mx) {
		puts ("0");
		return 0;
	}
	cout << S2.substr (pos - mx + 1, mx) << endl;
	cout << mx << endl;
	return 0;
}
