#include <stdio.h>
#include <stdlib.h>

int a[1 << 18], b[1 << 18], n, f[1 << 19];

int C(const void *i, const void *j) {
	return *(int*)i - *(int*)j;
}

int main() {
	while (2 == scanf("%d%d", a + n, b + n))
		++f[b[n++]];
	qsort(a, n, sizeof *a, C);
	qsort(b, n, sizeof *b, C);
	long long z = 0, z2 = 0;
	for (int i = 0; i < n; ++i)
		z += abs(a[i] - b[i]),
		z2 += a[i] * 1ll * f[a[i]];
	printf("%lld\n%lld", z, z2);
}
