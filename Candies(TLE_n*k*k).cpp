#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> candies(n);
        for(int i = 0; i < n; i++) {
          cin >> candies[i];
        }
        vector<int> dp(k+1, 0);
        dp[0] = 1; // dp[i] = total ways i candies used already
        for(int i = 0; i < n; i++) {
          for(int used = k; used >= 0; used--) {
            for(int c = 1; c <= min(candies[i], k-used); c++) {
              dp[used+c] = (dp[used+c] + dp[used]) % M;
              // cout << used << " " << dp[used+c] << "\n";
            }
          }
        }
        cout << dp[k] << "\n";
    }
    return 0;
}