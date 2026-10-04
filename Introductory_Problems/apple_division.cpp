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

ll solve(int i, int n, vector<ll>& a, ll s1, ll s2)
{
    if (i == n)
    {
        return abs(s1 - s2);
    }
    else
    {
        return min(solve(i + 1, n, a, s1 + a[i], s2), solve(i + 1, n, a, s1, s2 + a[i]));
    }
}
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << solve(0, n, a, 0, 0);
    return 0;
}
