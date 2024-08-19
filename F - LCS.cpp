/*
Problem Name: F - LCS
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_f
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
    string a, b;
    cin >> a >> b;
    int size_a = (int)a.size();
    int size_b = (int)b.size();
    vector<vector<int>> dp(size_b+1, vector<int> (size_a+1));
    for(int i = 0; i <= size_b; i++) {
      for(int j = 0; j <= size_a; j++) {
        if(i == 0 || j == 0) {
          dp[i][j] = 0;
        }else {
          if(b[i-1] == a[j-1]) {
            dp[i][j] = 1 + dp[i-1][j-1];
          }else {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
          }
        }
      }
    }
    string lcs = "";
    int i = size_b, j = size_a;
    while(i > 0 && j > 0) {
      if(a[j-1] == b[i-1]) {
        lcs.push_back(a[j-1]);
        i--, j--;
      }else if(dp[i-1][j] > dp[i][j-1]) {
        i--;
      }else j--;
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs << "\n";
  }
  return 0;
}