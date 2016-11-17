/* Kadane's Algorithm
 * HR: maxsubarray
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int t;
    scanf ("%d", &t);
    while (t--) {
        long n;
        long num[100005];
        long long sum = 0;
        long counter = 0;
        long i,j;
        
        scanf ("%ld",&n);
        for (j = 0; j < n; j++) scanf ("%ld", &num[j]);
        
        /* kadane's Algo */
        long long max_so_far = 0;
        long long max = 0;
        long max_neg = num[0];
        
        for (i = 0; i < n; i++) {
            max_so_far += num[i];
            
            if (num[i] >= 0) {
                counter++; // a bit tweak for all -ve inputs.
		sum += num[i];
            } else {
                if (num[i] > max_neg)
                    max_neg = num[i];
            }
            
            if (max_so_far < 0) {
                max_so_far = 0;
                continue;
            }
            
            if (max_so_far >= max)
                max = max_so_far;
        }
        
        if (counter == 0)
            printf ("%ld %ld\n", max_neg, max_neg);
        else
            printf ("%lld %lld\n", max, sum);
    }
    return 0;
}

