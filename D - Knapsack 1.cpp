/*
Problem Name: D - Knapsack 1
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_d
Idea: 
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, W;
        cin >> n >> W;
        vector<int> weight(n), value(n);
        for(int i = 0; i < n; i++) {
            cin >> weight[i] >> value[i];
        }
        vector<ll> dp(W+1, 0);
        for(int i = 0; i < n; i++) {
          for(int j = W - weight[i]; j >= 0; j--) {
            dp[j+weight[i]] = max(dp[j+weight[i]], dp[j] + value[i]);
          }
        }
        ll ans = 0;
        for(int i = 0; i <= W; i++) {
          ans = max(ans, dp[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}