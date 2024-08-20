/*
Problem Name: T - Permutation
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_t
Idea: 
Complexity:
Resource: https://codeforces.com/blog/entry/64250?#comment-482552
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
        string sign;
        cin >> sign;
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        // dp[i][j] = the total number of valid permutations of length i
        // where the i-th element is j (j <= i), and this permutation respects the first i-1 signs
        dp[1][1] = 1;
        for(int i = 2; i <= n; i++) {
            vector<int> cumulative_sum(n+1, 0);
            for(int j = 1; j <= n; j++) {
                cumulative_sum[j] = (cumulative_sum[j-1] + dp[i-1][j]) % M;
            }

            for(int j = 1; j <= i; j++) {
                if(sign[i-2] == '>') {
                    dp[i][j] = (dp[i][j] + cumulative_sum[n] - cumulative_sum[j-1] + M) % M;
                }else dp[i][j] = (dp[i][j] + cumulative_sum[j-1] + M) % M;
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans = (ans + dp[n][i]) % M;
        }
        cout << ans << "\n";
    }
    return 0;
}
