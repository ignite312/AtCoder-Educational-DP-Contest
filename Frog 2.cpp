/*
Problem Name: Frog 2
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_b
Idea: 
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<int> dp(n, INF);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
          for(int j = 1; j <= k; j++) {
            if(i+j < n)dp[i+j] = min(dp[i+j], abs(v[i] - v[i+j]) + dp[i]);
          }
        }
        cout << dp[n-1] << "\n";
    }
    return 0;
}
