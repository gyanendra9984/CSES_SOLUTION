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

class SegmentTree
{
private:
    int size;
    vector<ll> tree, lazy;

public:
    SegmentTree(int n)
    {
        size = n;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void update(int l, int r, int idx, int ul, int ur, ll val)
    {
        if (lazy[idx] != 0)
        {
            tree[idx] += lazy[idx] * (r - l + 1);
            if (l != r)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if (l > ur || r < ul)
            return;
        if (l >= ul && r <= ur)
        {
            tree[idx] += val * (r - l + 1);
            if (l != r)
            {
                lazy[2 * idx + 1] += val;
                lazy[2 * idx + 2] += val;
            }
            return;
        }
        int mid = l + (r - l) / 2;
        update(l, mid, 2 * idx + 1, ul, ur, val);
        update(mid + 1, r, 2 * idx + 2, ul, ur, val);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    ll query(int l, int r, int idx, int ql, int qr)
    {
        if (lazy[idx] != 0)
        {
            tree[idx] += lazy[idx] * (r - l + 1);
            if (l != r)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if (l > qr || r < ql)
            return 0;
        if (l >= ql && r <= qr)
            return tree[idx];
        int mid = l + (r - l) / 2;
        return query(l, mid, 2 * idx + 1, ql, qr) + query(mid + 1, r, 2 * idx + 2, ql, qr);
    }
};

void solve()
{
    int arr_size, query_num;
    cin >> arr_size >> query_num;

    vector<int> arr(arr_size);
    for (int &i : arr)
        cin >> i;

    vector<vector<pair<int, int>>> queries(arr_size);
    for (int q = 0; q < query_num; q++)
    {
        int start, stop; // Renamed 'end' to 'stop'
        cin >> start >> stop;
        queries[start - 1].push_back({stop - 1, q});
    }

    vector<ll> pref_arr(arr_size + 1);
    for (int i = 0; i < arr_size; i++)
        pref_arr[i + 1] = pref_arr[i] + arr[i];

    vector<ll> ans(query_num);
    vector<pair<int, int>> maxes;
    SegmentTree contrib(arr_size);

    for (int i = arr_size - 1; i >= 0; i--)
    {
        while (!maxes.empty() && arr[i] >= maxes.back().first)
        {
            maxes.pop_back();
            contrib.update(0, arr_size - 1, 0, maxes.size(), maxes.size(), -contrib.query(0, arr_size - 1, 0, maxes.size(), maxes.size()));
        }

        int len = (maxes.empty() ? arr_size : maxes.back().second) - i;
        contrib.update(0, arr_size - 1, 0, maxes.size(), maxes.size(), (ll)arr[i] * len);
        maxes.push_back({arr[i], i});

        for (const pair<int, int> &query_pair : queries[i])
        {
            int stop_idx = query_pair.first;
            int q = query_pair.second;

            int lo = 0, hi = maxes.size() - 1, valid = -1;
            while (lo <= hi)
            {
                int mid = (lo + hi) / 2;
                if (maxes[mid].second <= stop_idx)
                {
                    valid = mid;
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }

            ll sum1 = contrib.query(0, arr_size - 1, 0, valid + 1, maxes.size() - 1);
            ll sum2 = (ll)(stop_idx - maxes[valid].second + 1) * maxes[valid].first;
            ll pref_sub = pref_arr[stop_idx + 1] - pref_arr[i];
            ans[q] = sum1 + sum2 - pref_sub;
        }
    }

    for (ll a : ans)
        cout << a << '\n';
}

int main()
{
    solve();
    return 0;
}