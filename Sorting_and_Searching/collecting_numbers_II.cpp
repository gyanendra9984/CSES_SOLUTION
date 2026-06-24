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
    int n,m;
    cin >> n>>m;
    int a[n + 2],b[n+2], ans = 1,aa,x,y,bb;
    for (int i = 1; i <= n; i++)
    {
        cin >>b[i];
        a[b[i]] = i;
    }
    a[0] = 0,a[n + 1] = n+1;
    b[0] = 0, b[n + 1] = n + 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] < a[i - 1])
            ans++;
    }
    for (int i = 0; i < m;i++){
        aa=0,bb=0;
        cin >> x >> y;
        x = b[x], y = b[y];
        if (a[x] < a[x- 1]) aa++;
        if (a[y] < a[y - 1])aa++;
        if ((x+1!=y)&&a[x+1] < a[x])aa++;
        if ((y+ 1 != x) && a[y + 1] < a[y])aa++;
        swap(b[a[x]], b[a[y]]);
        swap(a[x], a[y]);
        if (a[x] < a[x - 1]) bb++;
        if (a[y] < a[y - 1]) bb++;
        if ((x + 1 != y) && a[x + 1] < a[x]) bb++;
        if ((y + 1 != x) && a[y + 1] < a[y])bb++;
        ans = ans + (bb - aa);
        cout << ans<<"\n";
    }
       
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}