#include <stdio.h>

int n, start[10005], len[10005], len1[10005], hd, tl
        , at
        , tt[10][1 << 19];

char s[20001];

long long chksum, chksum1;

void write(int id, int len)
{
        while (len--)
        {
                chksum += id * at;
                ++at;
        }
}

void write1(int id, int len, int st)
{
        while (len--)
        {
                chksum1 += id * 1ll * st;
                ++st;
        }
}

void add(int o, int v, int l, int r, int p, int k)
{
        tt[o][v] += k;
        if (l == r) 
                return;
        if (p <= (l + r) / 2)
                add(o, 2 * v, l, (l + r) / 2, p, k);
        else
                add(o, 2 * v + 1, (l + r) / 2 + 1, r, p, k);
}

int search(int o, int v, int l, int r)
{
        if (l == r)
                return tt[o][v] ? l : -1;
        if (tt[o][2 * v])
                return search(o, 2 * v, l, (l + r) / 2);
        return search(o, 2 * v + 1, (l + r) / 2 + 1, r);
}

int main()
{
        scanf("%s", s);
        while (s[n])
                ++n;

        {
                int pos , i;

                pos = 0;

                for (i = 0; i < n; ++i)
                {
                        if (i % 2 == 0)
                        {
                                start[i / 2] = pos;
                                len[i / 2] = s[i] - '0';
                                len1[i / 2] = len[i / 2];
                                ++hd;
                        }
                        else
                        {
                                add(s[i] - '0', 1, 0, 200000, pos, 1);
                        }
                        pos += s[i] - '0';
                }
        }


        {

                at = 0;


                while (hd > tl)
                {
                        if (at == start[tl])
                        {
                                write(tl, len[tl]);
                                ++tl;
                        }
                        else
                        {
                                int gap;

                                gap = start[tl] - at;
                                if (gap >= len[hd - 1])
                                {
                                        write(hd - 1, len[hd - 1]);
                                        --hd;
                                }
                                else
                                {
                                        write(hd - 1, gap);
                                        len[hd - 1] -= gap;
                                }
                        }
                }



        }

        {
                int i;
                for (i = n / 2; i >= 2; --i)
                {
                        int mov, mov_;
                        int j;

                        mov = 1e9;

                        for (j = len1[i]; j < 10; ++j)
                        {
                                int x;
                                if ((x = search(j, 1, 0, 200000)) == -1)
                                        continue;

                                if (mov == 1e9 || x < mov_)
                                {
                                        mov_ = x;
                                        mov = j;
                                }
                        }


                        if (mov < 1e9 && mov_ < start[i])
                        {
                                write1(i, len1[i], mov_);
                                add(mov, 1, 0, 200000, mov_, -1);

                                mov -= len1[i];
                                if (mov)
                                {
                                        add(mov, 1, 0, 200000, mov_ + len1[i], 1);
                                }
                        }
                        else
                                write1(i, len1[i], start[i]);
                }


                {
                        int j, st_;
                        for (j = 1; j < 10; ++j)
                        {
                                st_ = search(j, 1, 1, 200000);
                                if (st_ == -1)
                                        continue;
                                if (st_ < start[1])
                                        start[1] = st_;
                        }
                        write1(1, len1[1], start[1]);
                }
        }

        printf("%lld\n%lld", chksum, chksum1);
        return 0;
}

