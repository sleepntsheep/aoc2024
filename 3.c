#include <stdio.h>
#include <string.h>

char s[1 << 20], *p, *p2;
long long z, a, b, z1;
int on = 1;

int xisdigit(int x)
{
  return x >= '0' && x <= '9';
}

int main()
{
  while (fgets(s, sizeof s, stdin))
  {

    p = s;
    while (*p)
    {
      if (0 == memcmp("don't()", p, 7))
      {
        p += 7;
        on = 0;
      }
      else if (0 == memcmp("do()", p, 4))
      {
        p += 4;
        on = 1;
      }
      else if ('m' != *p || 0 != memcmp("mul(", p, 4))
      {
        ++p;
        continue;
      }
      else
      {
        p += 4;
        if (!xisdigit(*p))
          continue;

        p2 = p;
        while (xisdigit(*p2))
          ++p2;

        if (*p2 != ',')
        {
          p = p2;
          continue;
        }

        *p2 = 0;
        sscanf(p, "%lld", &a);

        p = p2 + 1;

        if (!xisdigit(*p))
          continue;

        p2 = p;
        while (xisdigit(*p2))
          ++p2;

        if (*p2 != ')')
        {
          p = p2;
          continue;
        }

        *p2 = 0;
        sscanf(p, "%lld", &b);
        p = p2 + 1;

        z += a * b;
        if (on)
          z1 += a * b;
      }
    }

  }

  printf("%lld\n%lld", z, z1);
}

