#include <stdio.h>
#include <string.h>

#define N 2000

int n, m, si, sj, i, j, d, ni, nj, si_, sj_,
    dx[] = { 0, 1, 0, -1, 0 },
    dy[] = { -1, 0, 1, 0, 0 },
    z, z1, xx[1 << 16], xy[1 << 16], xo,
    i_, j_, k, mask[N][N];

char a[N][N], *p, b[N][N];

int x()
{
  int z;
  si = si_;
  sj = sj_;
  d = 0;
  while (si >= 0 && si < n && sj >= 0 && sj < m)
  {
    if (a[si][sj] == 'X' && ((mask[si][sj] >> d) & 1))
    {
      ++z1;
      return -1;
    }
    if (a[si][sj] != 'X')
    {
      ++z;
      a[si][sj] = 'X';
      mask[si][sj] = 0;
    }
    mask[si][sj] |= 1 << d;
    ni = si + dy[d];
    nj = sj + dx[d];
    if (ni < 0 || nj < 0 || ni >= n || nj >= m)
      break;
    if (a[ni][nj] == '#')
    {
      ++d;
      if (d > 3)
        d = 0;
    }
    else
    {
      si = ni;
      sj = nj;
    }
  }
  return z;
}

int main()
{
  d = 0;
  while (fgets(a[n], sizeof a[n], stdin))
  {
    if (a[n][0] == '\n')
      continue;
    p = strchr(a[n], '\n');
    m = p - a[n];
    *p = 0;

    for (j = 0; j < m; ++j)
    {
      if (a[n][j] == '^')
      {
        si_ = n;
        sj_ = j;
      }
    }

    ++n;
  }

  z = x();

  for (i = 0; i < n; ++i)
  {
    for (j = 0; j < m; ++j)
    {
      for (k = 0; k < 5; ++k)
      {
        i_ = i + dy[k];
        j_ = j + dx[k];
        if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && !b[i_][j_] && a[i_][j_] != '#' && !(i_ == si_ && j_ == sj_))
        {
          b[i_][j_] = 1;
          xx[xo] = j_;
          xy[xo] = i_;
          ++xo;
        }
      }
    }
  }

  for (i = 0; i < xo; ++i)
  {
    for (j = 0; j < xo; ++j)
      a[xy[j]][xx[j]] = '.';
    a[si_][sj_] = '.';
    a[xy[i]][xx[i]] = '#';
    x();
  }

  printf("%d\n%d", z, z1);
  return 0;
}

