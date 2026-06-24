//           //XXXXXX\\          ||\\      //||
//          ||        \\         || \\    // ||
//          ||        ||         ||  \\  //  ||
//          ||                   ||   \\//   ||
//          ||   //XXX\\         ||          ||
//          ||   ||   ||   __    ||          ||   __
//          \\XXX//   ||  |__|   ||          ||  |__|
//  ||XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1000000007;
ll power(ll a, ll b)
{
    ll result = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;

}


void solve()
{
    int n;
    cin >> n;

    ll sum = n * (n + 1) / 2;
    if (sum % 2 == 1)
    {
        cout << 0 << endl;
        return;
    }

    sum /= 2;
    vector<ll> dp(sum + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = sum; j >= i; j--)
        {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }

    cout<<(dp[sum] * power(2,MOD-2)) % MOD;
}

int main()
{
    solve();
    return 0;
}
