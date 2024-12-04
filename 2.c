#include <stdio.h>
#include <string.h>

char s[99999];
int z, z1;

int manhattan(int x, int y)
{
  return x > y ? x - y: y - x;
}

int safe(int *a, int n)
{
  int ok = 1, i, inc = 0, dec = 0;
  for (i = 1; ok && i < n; ++i)
  {
    if (a[i] == a[i - 1])
      ok = 0;
    else
    {
      if (manhattan(a[i], a[i - 1]) > 3)
        ok = 0;
      if (a[i] > a[i - 1])
        ++inc;
      else
        ++dec;
    }
  }
  if (inc && dec)
    return 0;
  return ok;
}

int main()
{
  while (fgets(s, sizeof s, stdin))
  {
    char *p;
    int x, y, ok = 1, inc = 0, dec = 0, eq = 0;
    static int a[10], k, b[10], k2;

    k = 0;
    p = s;
    if (1 != sscanf(p, "%d", &x))
      continue;

    a[k++] = x;

    p = strchr(p, ' ');
    if (p)
      ++p;

    while (p)
    {
      sscanf(p, "%d", &y);
      p = strchr(p, ' ');
      a[k++] = y;
      if (p)
        ++p;
    }

    z += safe(a, k);

    if (safe(a, k))
      ++z1;
    else
    {
      int i, j;
      for (i = 0; i < k; ++i)
      {
        k2 = 0;
        for (j = 0; j < k; ++j)
          if (i != j)
            b[k2++] = a[j];
        if (safe(b, k2))
        {
          ++z1;
          break;
        }
      }
    }

  }
  printf("%d\n%d", z, z1);
}

