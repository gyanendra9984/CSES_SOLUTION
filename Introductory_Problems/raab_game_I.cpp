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
    int n, a, b;
    cin >> n >> a >> b;
    if ((a == 0 && b != 0) || (a != 0 && b == 0) || (a + b > n))
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
        v[i] = i;
    int x = 1;
    for (int i = a + 1; i <= (a+b);i++){
        v[x] = i;
        x++;
    }
    for (int i = 1; i <= a;i++){
        v[x] = i;
        x++;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 1; i <= n;i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}