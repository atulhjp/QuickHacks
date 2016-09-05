#include <bits/stdc++.h>
#define ULL unsigned long long
using namespace std;

//PS

/* Sum of elements in a array range
 * using segment tree: O(log(N)).
 */


/*
int get_n (int num)
{
	int n = 1;

	while (num/n*n > 1)
		n++;
}
*/

ULL get_sum (int arr[], ULL low, ULL high)
{
	ULL sum = 0;

	for (ULL i = low; i <= high; i++)
		sum += arr[i];

	return sum;
}

/* construct a segment tree */
void construct_tree (int *arr, int *result, ULL low, ULL high, ULL index)
{
	ULL mid = low + (high - low)/2;

//	cout << "Inside" << endl;

	if (low == high) {
		result[index] = arr[low];
		return;
	}

	if (low > high)
		return;

//	cout << low << high << endl;

	ULL sum = get_sum (arr, low, high);

	result[index] = sum;

	construct_tree (arr, result, low, mid, 2*index);
	construct_tree (arr, result, mid+1, high, 2*index+1);
}

int query_sum (int *arr, ULL low, ULL high, ULL l, ULL r, ULL index)
{
	ULL mid = (l+r)/2;

	if (low > high || l > r)
		return 0;

	if (low == l && high == r)
		return arr[index];

	if (l == r)
		return arr[index];

	if (low >= l && high <= mid)
		return query_sum (arr, low, high, l, mid, 2*index);

	if (low > mid && high <= r)
		return query_sum (arr, low, high, mid + 1, r, 2*index + 1);

	if (high > mid && low <= mid)
		return query_sum (arr, low, mid, l, mid, 2*index) + query_sum (arr, mid+1, high, mid + 1, r, 2*index +1);
}

int main ()
{
	int num[50005];
	ULL len;

	cin >> len;

	for (ULL i = 0; i < len; i++)
		cin >> num[i];

	int *result = (int *) malloc (4*len*(sizeof(int)));
	memset (result, 0, (4*len*(sizeof(int))));

	construct_tree (num, result, 0, len-1, 1);

	int queries;

	cin >> queries;

	while (queries--) {
		ULL low, high;

		cout << "Your Query" << endl;

		cin >> low >> high;

		cout << "Sum: " << query_sum (result, low, high, 1, len, 1) << endl;
	}

	free (result);

	return 0;
}
