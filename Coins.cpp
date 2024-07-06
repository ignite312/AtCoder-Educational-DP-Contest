/*
Problem Name: Coins
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_i
Idea: 
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<double> p(n);
        for(int i = 0; i < n; i++) {
          cin >> p[i];
        }
        vector<double> dp(n+1, 0);
        dp[0] = 1.0;       // Probability of 0 Head
        for(int i = 0; i < n; i++) {
          for(int h = i+1; h >= 0; h--) {
            if(h > 0)dp[h] = dp[h-1]*p[i] + dp[h]*(1-p[i]);
            else dp[h] = dp[h]*(1-p[i]);
          }
        }
        double ans = 0.00;
        for(int i = 0; i <= n; i++) {
          if(i > (n-i)) {
            ans += dp[i];
          }
        }
        cout << fixed << setprecision(12) << ans << "\n";
    }
    return 0;
}
