/*
Problem Name: N - Slimes
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_n
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
        int n;
        cin >> n;
        vector<ll> v(n), prefix(n+1, 0);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            prefix[i+1] = prefix[i] + v[i];
        }
        vector<vector<ll>> dp(n, vector<ll>(n, 0));
        map<pair<int, int>, array<int, 3>> track;
        for(int l = n-1; l >= 0; l--) {
            for(int r = l; r < n; r++) {
                if(l == r) {
                    dp[l][r] = 0;
                }else {
                    dp[l][r] = INF;
                    for(int k = l; k < r; k++) {
                      dp[l][r] = min(dp[l][r], dp[l][k]+dp[k+1][r] + prefix[r+1] - prefix[l]);
                    }
                }
            }
        }

        cout << dp[0][n-1] << "\n";
    }
    return 0;
}
