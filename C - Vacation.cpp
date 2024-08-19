/*
Problem Name: C - Vacation
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_c
Idea: 
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100000][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n;
        vector<array<int, 3>> ac(n);
        for(int i = 0; i < n; i++) {
            cin >> ac[i][0] >> ac[i][1] >> ac[i][2];
        }
        dp[0][0] = ac[0][0], dp[0][1] = ac[0][1], dp[0][2] = ac[0][2];
        for(int i = 1; i < n; i++) {
          for(auto x : {0, 1, 2}) {
            if(x == 0) {
              dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + ac[i][0];
            }else if(x == 1) {
              dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + ac[i][1];
            }else {
              dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + ac[i][2];
            }
          }
        }
        cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    }
    return 0;
}