/*
Problem Name: Grouping
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_u
Idea: Bitmask DP 
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
        int n;
        cin >> n;
        vector<vector<ll>> cmp(n, vector<ll>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> cmp[i][j];
            }
        }
        vector<ll> dp(1 << n, 0);
        for(int mask = 0; mask < (1 << n); mask++) {
            for(int i = 0; i < n; i++) {
                if(!(mask & (1 << i)))continue;
                for(int j = i+1; j < n; j++) {
                    if(!(mask & (1 << j)))continue;
                    dp[mask]+=cmp[i][j];
                }
            }
        }
        for(int mask = 1; mask < (1 << n); mask++) {
            for(int submask = mask; submask > 0; submask = (submask-1) & mask) {
                dp[mask] = max(dp[mask], dp[submask] + dp[mask ^ submask]);
            }
        }
        cout << dp[(1 << n) - 1] << "\n";
    }
    return 0;
}
