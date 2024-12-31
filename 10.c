#include <stdio.h>

char s[50][50];
int n, m, z, z1
        , eh[10][2502], eo[10], dp[3000];

int score_trailhead(int i, int j)
{
        static int qu[3000], hd, tl, vis[3000];
        int score;
        int ii;

        for (ii = 0; ii < 3000; ++ii)
        {
                vis[ii] = 0;
                dp[ii] = 0;
        }

        hd = tl = 0;

        qu[hd++] = i * m + j;
        vis[qu[0]] = 1;
        dp[qu[0]] =1 ;


        score = 0;
        while (hd > tl)
        {
                int u;
                u = qu[tl++];

                if (s[u / m][u % m] == '9')
                {
                        ++score;
                        z1 += dp[u];
                        continue;
                }

                if (u >= m && s[u / m - 1][u % m] == s[u / m][u % m] + 1)
                {
                        if(!vis[u-m])
                        {
                                qu[hd++] = u - m;
                                vis[u - m] = 1;
                        }
                        dp[u - m] += dp[u];
                }
                if (u + m < n * m && s[u / m + 1][u % m] == s[u / m][u % m] + 1)
                {
                        if(!vis[u+m])
                        {
                        qu[hd++] = u + m;
                        vis[u + m] = 1;
                        }
                        dp[u + m] += dp[u];
                }
                if ((u + 1) % m && s[u / m][u % m + 1] == s[u / m][u % m] + 1)
                {
                        if(!vis[u+1])
                        {
                        qu[hd++] = u + 1;
                        vis[u + 1] = 1;
                        }
                        dp[u + 1] += dp[u];
                }
                if (u % m && s[u / m][u % m - 1] == s[u / m][u % m] + 1)
                {
                        if(!vis[u-1])
                        {
                        qu[hd++] = u - 1;
                        vis[u - 1] = 1;
                        }


                        dp[u - 1] += dp[u];
                }
        }

        return score;
}

int main()
{
        int i, j;

        while (1 == scanf("%s", s[n]))
                ++n;
        while (s[0][m])
                ++m;

        for (i = 0; i < n; ++i)
        {
                for (j = 0; j < m; ++j)
                {
                        if (s[i][j] == '0')
                        {
                                z += score_trailhead(i, j);
                        }

                        //eh[s[i][j] - '0'][eo[s[i][j] - '0']++] = i * m + j;
                }
        }


        printf("%d\n%d", z, z1);


        return 0;
}

