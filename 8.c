#include <stdio.h>

int antenna(int c)
{
        return (c >= '0' && c <= '9')
                || (c >= 'a' && c <= 'z')
                || (c >= 'A' && c <= 'Z');
}

int n, m, eo[300], *eh[300], pool[1 << 21], alloc
        , z, z1;
char s[50][51], antinode[50][51]
        , antinode2[50][51];

int outside(int i, int j)
{
        return i < 0 || j < 0 || i >= n || j >= m;
}

int *pool_alloc(int n)
{
        alloc += n;
        return pool + alloc - n;
}

int main()
{
        int i, j, i_, j_;

        while (1 == scanf("%s", s[n]))
                ++n;
        while (s[0][m])
                ++m;

        for (i = 0; i < n; ++i)
        {
                for (j = 0; j < m; ++j)
                {
                        if (!antenna(s[i][j]))
                                continue;
                        ++eo[s[i][j]];
                }
        }

        for (i = 0; i < 300; ++i)
        {
                eh[i] = pool_alloc(eo[i]);
                eo[i] = 0;
        }

        for (i = 0; i < n; ++i)
        {
                for (j = 0; j < m; ++j)
                {
                        if (!antenna(s[i][j]))
                                continue;
                        eh[s[i][j]][eo[s[i][j]]++] = i * m + j;
                }
        }

        for (i = 0; i < n; ++i)
        {
                for (j = 0; j < m; ++j)
                {
                        int ii;
                        if (!antenna(s[i][j]))
                                continue;
                        for (ii = 0; ii < eo[s[i][j]]; ++ii)
                        {
                                int dx, dy
                                        , L, ni, nj;

                                if (i * m + j == eh[s[i][j]][ii])
                                        continue;

                                i_ = eh[s[i][j]][ii] / m;
                                j_ = eh[s[i][j]][ii] % m;

                                dy = i_ - i;
                                dx = j_ - j;

                                ni = i + 2 * dy;
                                nj = j + 2 * dx;

                                if (! outside(ni, nj))
                                {
                                        antinode[ni][nj] = 1;
                                }

                                for (L = 1; ; ++L)
                                {
                                        ni = i + L * dy;
                                        nj = j + L * dx;

                                        if ( outside(ni, nj))
                                                break;

                                        antinode2[ni][nj] = 1;
                                }

                        }
                }
        }

        for (i = 0; i < n; ++i)
                for (j = 0; j < m; ++j)
                {
                        z += antinode[i][j];
                        z1 += antinode2[i][j];
                }


        printf("%d\n%d", z, z1);


        return 0;
}



