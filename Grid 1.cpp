/*
Problem Name: Grid 1
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_h
Idea: 
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
const int M = 1e9 + 7;
char grid[N+1][N+1];
int dp[N+1][N+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
          for(int j = 1; j <= m; j++) {
            cin >> grid[i][j];
          }
        }
        dp[1][1] = 1;
        for(int i = 1; i <= n; i++) {
          for(int j = 1; j <= m; j++) {
            if(grid[i][j] != '#') {
              dp[i][j] = (dp[i][j] + (dp[i-1][j] + dp[i][j-1]) % M) % M;
            }
          }
        }
        cout << dp[n][m] << "\n";
    }
    return 0;
}