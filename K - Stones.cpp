/*
Problem Name: K - Stones
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_k
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
        int n, k;
        cin >> n >> k;
        vector<int> pile(n);
        vector<bool> dp(k+1, false);
        for(int i = 0; i < n; i++) {
            cin >> pile[i];
        }
        for(int i = 1; i <= k; i++) {
            for(int j = 0; j < n; j++) {
                if(i-pile[j] >= 0 && !dp[i-pile[j]]) {
                    dp[i] = true;
                }
            }
        }
        cout << (dp[k] ? "First\n" : "Second\n");
    }
    return 0;
}