#include <stdio.h>


#define K 1000000000000000ll
#define M (1<<24)

int ii, rt[76], L[M], R[M];
long long z, z1;
long long A[M];

void set(int *v, long long l, long long r, long long p, long long k)
{
        if (!*v)
        {
                *v = ++ii;
        }

        if (l == r)
        {
                A[*v] = k;
                return;
        }

        if (p <= (l + r) / 2)
                set(L + *v, l, (l + r) / 2, p, k);
        else
                set(R + *v, (l + r) / 2 + 1, r, p, k);
}

long long point(int v, long long l, long long r, long long p)
{
        if (!v)
                return 0;
        if (l == r)
                return A[v];
        if (p <= (l + r) / 2)
                return point(L[v], l, (l + r) / 2, p);
        return point(R[v], (l + r) / 2 + 1, r, p);
}

int count_digits(long long a)
{
        int i;
        i = 0;
        while (a)
                ++i, a /= 10;
        return i;
}

long long Blink(long long a, int lf)
{
        int kk;
        long long res, a0;

        a0 = a;

        if (!lf)
                return 1;

        if ((res = point(rt[lf], 0, K, a)))
                return res;

        if (! a)
                res = Blink(1, lf - 1);
        else if ((kk = count_digits(a)) % 2 == 0)
        {
                long long b, b1;

                b = 0;
                b1 = 1;

                kk /= 2;
                while (kk--)
                {
                        b1 = b1 * 10 + a % 10, a /= 10;
                }
                while (b1)
                        b = b * 10 + b1 % 10, b1 /= 10;

                res = Blink(b / 10, lf - 1) + Blink(a, lf - 1);
        }
        else
                res = Blink(a * 2024, lf - 1);

        set(rt + lf, 0, K, a0, res);
        return res;
}

int main()
{
        int x;

        while (1 == scanf("%d", &x))
        {
                z += Blink(x, 25);
                z1 += Blink(x, 75);
        }

        printf("%lld\n%lld", z, z1);

        return 0;
}

