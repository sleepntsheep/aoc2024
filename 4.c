#include <stdio.h>
#include <string.h>

char s[1005][1005], b[10];
int n, m;
long long z, z1;

int main()
{
  while (fgets(s[5 + n] + 5, sizeof s[0] - 5, stdin))
  {
    if (!m)
      m = strlen(s[5 + n] + 5);
    ++n;
  }

  for (int i = 5; i < 5 + n; ++i)
    for (int j = 5; j < 5 + m; ++j)
    {
      if (s[i][j] == 'X' && s[i][j + 1] == 'M' && s[i][j + 2] == 'A' && s[i][j + 3] == 'S')
        ++z;
      if (s[i][j] == 'X' && s[i][j - 1] == 'M' && s[i][j - 2] == 'A' && s[i][j - 3] == 'S')
        ++z;
      if (s[i][j] == 'X' && s[i + 1][j] == 'M' && s[i + 2][j] == 'A' && s[i + 3][j] == 'S')
        ++z;
      if (s[i][j] == 'X' && s[i - 1][j] == 'M' && s[i - 2][j] == 'A' && s[i - 3][j] == 'S')
        ++z;
      if (s[i][j] == 'X' && s[i - 1][j - 1] == 'M' && s[i - 2][j - 2] == 'A' && s[i - 3][j - 3] == 'S')
        ++z;
      if (s[i][j] == 'X' && s[i + 1][j + 1] == 'M' && s[i + 2][j + 2] == 'A' && s[i + 3][j + 3] == 'S')
        ++z;
      if (s[i][j] == 'X' && s[i + 1][j - 1] == 'M' && s[i + 2][j - 2] == 'A' && s[i + 3][j - 3] == 'S')
        ++z;
      if (s[i][j] == 'X' && s[i - 1][j + 1] == 'M' && s[i - 2][j + 2] == 'A' && s[i - 3][j + 3] == 'S')
        ++z;

      b[0] = s[i][j];
      b[1] = s[i][j + 2];
      b[2] = s[i + 1][j + 1];
      b[3] = s[i + 2][j];
      b[4] = s[i + 2][j + 2];
      b[5] = 0;
      if (0 == strcmp(b, "MSAMS")
        || 0 == strcmp(b, "SSAMM")
        || 0 == strcmp(b, "MMASS")
        || 0 == strcmp(b, "SMASM"))
        ++z1;

    }
  printf("%lld\n%lld", z, z1);
}

