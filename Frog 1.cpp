/*
Problem Name: Frog 1
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_a
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
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<int> dp(n, INF);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            if(i+1 < n)dp[i+1] = min(dp[i+1], abs(v[i] - v[i+1]) + dp[i]);
            if(i+2 < n)dp[i+2] = min(dp[i+2], abs(v[i] - v[i+2]) + dp[i]);
        }
        cout << dp[n-1] << "\n";
    }
    return 0;
}