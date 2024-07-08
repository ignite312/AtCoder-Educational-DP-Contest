/*
Problem Name: Deque
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_l
Idea: 
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
        vector<ll> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<vector<ll>> dp(n, vector<ll>(n, 0));
        for(int left = n-1; left >= 0; left--) {
            for(int right = left; right < n; right++) {
                if(left == right) {
                    dp[left][right] = v[left];
                }else {
                    dp[left][right] = max(v[left] - dp[left+1][right], -dp[left][right-1] + v[right]);
                }
            }
        }
        cout << dp[0][n-1] << "\n";
    }
    return 0;
}