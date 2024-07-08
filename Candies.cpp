/*
Problem Name: Candies
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_m
Idea:
Complexity:
Resource:
*/
#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> candies(n);
        for (int i = 0; i < n; i++) {
            cin >> candies[i];
        }
        vector<int> dp(k + 1, 0);
        dp[0] = 1; // dp[i] = total ways i candies used already
        for (int i = 0; i < n; i++) {
            vector<int> prefix(k + 1, 0);
            for (int used = k; used >= 0; used--) {
                int left = used + 1, right = used + min(k - used, candies[i]);
                if (left <= right) {
                    prefix[left] = (prefix[left] + dp[used]) % M;
                    if (right + 1 <= k)
                        prefix[right + 1] = (prefix[right + 1] - dp[used] + M) % M;
                }
            }
            for (int i = 1; i < k + 1; i++) {
                prefix[i] = (prefix[i - 1] + prefix[i]) % M;
                dp[i] = (dp[i] + prefix[i]) % M;
            }
        }
        cout << dp[k] << "\n";
    }
    return 0;
}