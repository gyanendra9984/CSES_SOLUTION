#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n, m;
vector<int> transitions[1 << 10];

void generate(int row, int curr_mask, int next_mask)
{
    if (row == n)
    {
        transitions[curr_mask].push_back(next_mask);
        return;
    }

    if (curr_mask & (1 << row))
    {
        generate(row + 1, curr_mask, next_mask);
    }
    else
    {
        // Place horizontal domino
        generate(row + 1, curr_mask, next_mask | (1 << row));

        // Place vertical domino
        if (row + 1 < n && !(curr_mask & (1 << (row + 1))))
        {
            generate(row + 2, curr_mask, next_mask);
        }
    }
}

int main()
{
    cin >> n >> m;

    int total_masks = 1 << n;

    for (int mask = 0; mask < total_masks; mask++)
    {
        generate(0, mask, 0);
    }

    vector<long long> dp(total_masks, 0), ndp(total_masks, 0);
    dp[0] = 1;

    for (int col = 0; col < m; col++)
    {
        fill(ndp.begin(), ndp.end(), 0);

        for (int mask = 0; mask < total_masks; mask++)
        {
            if(dp[mask] == 0)
                continue;

            for (int next_mask : transitions[mask])
            {
                ndp[next_mask] = (ndp[next_mask] + dp[mask]) % MOD;
            }
        }

        dp.swap(ndp);
    }

    cout << dp[0] << '\n';
    return 0;
}