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
ll dp[100][100001];
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
        vector<int> weight(n), value(n);
        ll sum_val = 0;
        for(int i = 0; i < n; i++) {
            cin >> weight[i] >> value[i];
            sum_val+=value[i];
        }
        for(int i = 0; i < n; i++) {
          for(int j = 0; j <= sum_val; j++) {
            dp[i][j] = INF;
          }
        }
        dp[0][value[0]] = weight[0]; // Take
        dp[0][0] = 0; // Not take
        for(int i = 1; i < n; i++) {
          for(int j = 0; j <= sum_val; j++) {
            dp[i][j] = min(dp[i][j], dp[i-1][j]); // Not take
            if(j-value[i] >= 0) {
              dp[i][j] = min(dp[i][j], dp[i-1][j-value[i]] + weight[i]); // Take
            }
          }
        }
        ll ans = 0;
        for(int i = 1; i <= sum_val; i++) {
          if(dp[n-1][i] <= W) {
            ans = i;
          }
        }
        cout << ans << "\n";
    }
    return 0;
}