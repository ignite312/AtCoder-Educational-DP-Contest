/*
Problem Name: Flowers
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_q
Idea: 
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct FenwickTree {
    // 0 base indexing
    vector<ll> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, INT_MIN);
    }
    FenwickTree(vector<ll> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
    ll max_query(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = max(ret, bit[r]);
        return ret;
    }
    void add(int idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = max(bit[idx], delta);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> h(n), a(n);
        for(int i = 0; i < n; i++) {
            cin >> h[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<ll> dp(n+1, 0);
        FenwickTree ft(n+1);
        ft.add(0, 0);
        for(int i = 0; i < n; i++) {
            ll mx = ft.max_query(h[i]);
            dp[h[i]] = max(dp[h[i]], a[i] + mx);
            ft.add(h[i], dp[h[i]]);
        }
        ll ans = 0;
        for(int i = 0; i <= n; i++) {
            ans = max(ans, dp[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
