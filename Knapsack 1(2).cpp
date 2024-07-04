/*
Problem Name: Knapsack 1
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_d
Idea: 
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[100][100001];

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
        dp[0][weight[0]] = value[0]; // Take
        // Not take defualt value dp[0][0] = 0
        for(int i = 1; i < n; i++) {
          for(int j = 0; j <= W; j++) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]); // Take
            if(j-weight[i] >= 0) {
              dp[i][j] = max(dp[i][j], dp[i-1][j-weight[i]] + value[i]);// Not take
            }
          }
        }
        ll ans = 0;
        for(int i = 0; i <= W; i++) {
          ans = max(ans, dp[n-1][i]);
        }
        cout << ans << "\n";
    }
    return 0;
}