#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

long long dp[20][11][2][2];
string s;

long long solve(int pos, int prev, int tight, int started)
{
    if (pos == (int)s.size())
        return 1;

    long long &res = dp[pos][prev][tight][started];
    if (res != -1)
        return res;

    res = 0;

    int limit = tight ? (s[pos] - '0') : 9;

    for (int d = 0; d <= limit; d++)
    {
        int ntight = tight && (d == limit);

        if (!started && d == 0)
        {
            res += solve(pos + 1, 10, ntight, 0);
        }
        else
        {
            if (started && d == prev)
                continue;

            res += solve(pos + 1, d, ntight, 1);
        }
    }

    return res;
}

long long count_valid(long long x)
{
    if (x < 0)
        return 0;

    s = to_string(x);
    memset(dp, -1, sizeof(dp));

    return solve(0, 10, 1, 0);
}

int main()
{
    long long a, b;
    cin >> a >> b;

    cout << count_valid(b) - count_valid(a - 1) << '\n';
    return 0;
}