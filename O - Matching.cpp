/*
Problem Name: O - Matching
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_o
Idea: Bitmask DP
Complexity:
Resource:
*/
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
        int n;
        cin >> n;
        vector<vector<int>> comp(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> comp[i][j];
            }
        }
        vector<int> dp(1 << n, 0);
        dp[0] = 1;
        for(int mask = 0; mask < (1 << n) - 1; mask++) {
            int cnt = __builtin_popcount(mask); // cnt-th man
            for(int w = 0; w < n; w++) {
                if(comp[cnt][w] && !(mask & (1 << w))) {
                    int new_mask = mask ^ (1 << w);
                    dp[new_mask] = (dp[new_mask] + dp[mask]) % M;
                }
            }
        }
        cout << dp[(1 << n) - 1] << "\n";
    }
    return 0;
}
