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

void solve()
{
    int n;
    cin >> n;

    vector<int> freq(1000001, 0);

    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
        mx = max(mx, x);
    }

    for (int d = mx; d >= 1; d--)
    {
        int cnt = 0;

        for (int multiple = d; multiple <= mx; multiple += d)
        {
            cnt += freq[multiple];

            if (cnt >= 2)
                break;
        }

        if (cnt >= 2)
        {
            cout << d << endl;
            return;
        }
    }
}
int main(){
        solve();
    return 0; }