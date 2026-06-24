//           //XXXXXX\\          ||\\      //||
//          ||        \\         || \\    // ||
//          ||        ||         ||  \\  //  ||
//          ||                   ||   \\//   ||
//          ||   //XXX\\         ||          ||
//          ||   ||   ||   __    ||          ||   __
//          \\XXX//   ||  |__|   ||          ||  |__|
//  ||XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long int

// int fun(vector<int> &a)
// {
//     vector<int> temp;
//     for (int x : a)
//     {
//         auto it = lower_bound(temp.begin(), temp.end(), x);
//         if (it == temp.end())
//             temp.push_back(x);
//         else
//             *it = x;
//     }
//     return temp.size();
// }
// void solve()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     int ans1 = fun(a);
//     reverse(a.begin(), a.end());
//     int ans2 = fun(a);
//     cout << max(ans1,ans2) << endl;
// }
// int main()
// {
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<long long> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        int best = 1; // at least one element always forms a good subsequence

        for (int bit = 0; bit < 30; bit++)
        {
            unordered_map<long long, int> freq;
            long long mask = 1LL << bit;

            for (long long x : A)
            {
                long long key = x ^ mask;
                freq[key]++;
                best = max(best, freq[key]);
            }
        }

        cout << best << "\n";
    }

    return 0;
}
