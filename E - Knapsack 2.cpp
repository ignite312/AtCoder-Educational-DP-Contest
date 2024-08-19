/*
Problem Name: E - Knapsack 2
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_e
Idea: 
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18+10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, W;
        cin >> n >> W;
        vector<ll> weight(n), value(n);
        int sum_val = 0;
        for(int i = 0; i < n; i++) {
            cin >> weight[i] >> value[i];
            sum_val+=value[i];
        }
        vector<ll> dp(sum_val+1, INF);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
          for(int j = sum_val - value[i]; j >= 0; j--) {
            dp[j+value[i]] = min(dp[j+value[i]], dp[j] + weight[i]);
          }
        }
        int ans = 0;
        for(int i = 0; i <= sum_val; i++) {
          if(dp[i] <= W) {
            ans = i;
          }
        }
        cout << ans << "\n";
    }
    return 0;
}