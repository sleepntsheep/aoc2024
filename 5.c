#include <stdio.h>
#include <string.h>

long long z, z1;
char s[1 << 18];
int n, a[1 << 18][2], q[100], b[1 << 18];

int main()
{
  while (1 == scanf("%s", s))
  {
    if (s[2] == '|')
    {
      s[2] = 0;
      sscanf(s, "%d", a[n]);
      sscanf(s + 3, "%d", a[n] + 1);
      ++n;
      continue;
    }

    for (int i = 0; i <= 99; ++i)
      q[i] = 0;

    int i, j, x, ok = 1;
    char *p = s, *p1;

    j = 0;

    for (;;)
    {
      p1 = strchr(p, ',');
      if (p1)
        *p1 = 0;
      sscanf(p, "%d", &x);
      q[x] = ++j;
      b[j] = x;
      if (p1 == NULL)
        break;
      p = p1 + 1;
    }

    for (i = 0; i < n; ++i)
      if (q[a[i][0]] && q[a[i][1]] && q[a[i][0]] > q[a[i][1]])
        ok = 0;

    if (ok)
      z += b[(j + 1) / 2];
    else
    {
      int changes = 0;
      for (;;)
      {
        changes = 0;
        for (i = 0; i < n; ++i)
        {
          if (q[a[i][0]] && q[a[i][1]] && q[a[i][0]] > q[a[i][1]])
          {
            int t;
            t = b[q[a[i][0]]];
            b[q[a[i][0]]] = b[q[a[i][1]]];
            b[q[a[i][1]]] = t;

            t = q[a[i][0]];
            q[a[i][0]] = q[a[i][1]];
            q[a[i][1]] = t;
            ++changes;
          }
        }
        if (!changes)
          break;
      }
      z1 += b[(j + 1) / 2];
    }

  }
  printf("%lld\n%lld", z, z1);
}

