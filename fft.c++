/* 
 * FFT (Fast Fourier Transformation)
 * Transforms a polynomial from it's
 * coefficient to Point form for quick
 * multiplication.
 * For IFFT set pass 'ift' as true.
 * SPOJ: POLYMUL
 */

long double PI = 3.1415926535897932384626433832795;

typedef complex<long double> base;
 
void fft (vector<base> & a, bool ift) {
	int n = a.size ();
	if (n == 1) return;

	vector<base> a0 (n/2), a1 (n/2);
	for (int i = 0, j = 0; i < n; i += 2, j++) {
 		a0[j] = a[i];
 		a1[j] = a[i + 1];
	}
 	fft (a0, ift);
	fft (a1, ift);

	long double ang = 2 * PI / n * (ift ? -1 : 1);

	base w (1), wn (cos(ang), sin(ang));
	for (int i = 0; i < n / 2; i++) {
		a[i] = a0[i] + w * a1[i];
		a[i + n / 2] = a0[i] - w * a1[i];
		if (ift)
			a[i] /= 2, a[i + n / 2] /= 2;
 		w *= wn;
	}
}

void multiply (const vector<int> & a, const vector<int> & b, vector<int64> & res) {
	vector<base> fa (a.begin(), a.end()), fb (b.begin(), b.end());
	int n = 1;
	while (n < max (a.size(), b.size())) n <<= 1;
 	n <<= 1;
 	fa.resize (n), fb.resize (n);

	fft (fa, false), fft (fb, false);
	for (int i = 0; i < n; i++)
		fa[i] *= fb[i];
	fft (fa, true);

	res.resize (n);
	for (int i = 0; i < n; i++)
		res[i] = (int64) (fa[i].real() + 0.5);
}
